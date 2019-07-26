/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highwaytohell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 10:13:30 by schornon          #+#    #+#             */
/*   Updated: 2019/05/19 14:36:08 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		smallest_bfslvl_room(t_s *s, t_qu *tmp_p)
{
	int r;
	int tmp_lvl;

	s->r = 2147483647;
	tmp_lvl = 2147483647;
	r = -1;
	while (++r < tmp_p->node->links)
	{
		if (tmp_p->node->next[r]->lvl < tmp_lvl &&
			tmp_p->node->next[r]->lvl >= 0 &&
			tmp_p->node->next[r]->block == 0)
		{
			tmp_lvl = tmp_p->node->next[r]->lvl;
			s->r = r;
		}
	}
}

void		find_way(t_s *s)
{
	t_qu		*tmp_p;
	int			res;

	res = 0;
	tmp_p = s->s_path[s->p_cnt];
	while (tmp_p != NULL)
	{
		if (tmp_p->node->r_val == 1)
			break ;
		smallest_bfslvl_room(s, tmp_p);
		if (s->r == 2147483647)
			break ;
		add_node_to_path(s, tmp_p);
		tmp_p = tmp_p->next;
	}
	if ((res = path_validator(tmp_p)) == 0)
		find_way(s);
}

void		bfs_second(t_s *s)
{
	t_qu *tmp_q;
	t_qu *t;

	tmp_q = s->q;
	while (tmp_q != NULL)
	{
		t = tmp_q;
		tmp_q = tmp_q->next;
		free(t);
	}
	bfs(s);
}

void		find_highway(t_s *s)
{
	int prev_block;

	prev_block = 0;
	p_visited_to_0(s);
	s->s_path = (t_qu**)malloc(sizeof(t_qu*) * 50);
	s->p_cnt = 0;
	while (1)
	{
		init_new_path(s, 2);
		find_way(s);
		bfs_second(s);
		if (count_visited(s) == prev_block)
			break ;
		prev_block = count_visited(s);
		s->p_cnt++;
		if (check_one_link(s) == 1 || s->p_cnt >= 49)
			break ;
	}
	if (s->p_cnt > 0 && s->s_path[s->p_cnt - 1]->next == NULL)
		s->p_cnt--;
}

void		highwaytohell(t_s *s)
{
	bfs(s);
	validate_min_one_way(s);
	find_highway(s);
	find_paths_len(s);
	if (s->p_cnt > 0 && s->s_path[s->p_cnt - 1]->path_len < 1)
		s->p_cnt--;
	sort_paths(s);
	p_visited_to_0(s);
	s->ant_name = 1;
	s->last_ant_dist = 0;
	ft_printf("\n");
	ants_controller(s);
}
