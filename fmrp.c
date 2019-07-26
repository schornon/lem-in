/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmrp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:19:06 by schornon          #+#    #+#             */
/*   Updated: 2019/05/14 17:59:10 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	p_visited_to_0(t_s *s)
{
	s->i = -1;
	while (++s->i < s->rm_cnt)
	{
		s->gph[s->i]->visited = 0;
	}
}

void	init_new_path(t_s *s, int r_val)
{
	s->s_path[s->p_cnt] = (t_qu*)malloc(sizeof(t_qu));
	s->s_path[s->p_cnt]->next = NULL;
	s->s_path[s->p_cnt]->prev = NULL;
	s->s_path[s->p_cnt]->path_len = 0;
	s->i = -1;
	while (++s->i < s->rm_cnt)
	{
		if (s->gph[s->i]->r_val == r_val)
		{
			s->s_path[s->p_cnt]->node = s->gph[s->i];
			s->s_path[s->p_cnt]->node->visited = 0;
			break ;
		}
	}
}

void	add_node_to_path(t_s *s, t_qu *tmp_p)
{
	t_qu *tmp_n;

	tmp_n = (t_qu*)malloc(sizeof(t_qu));
	tmp_n->next = NULL;
	tmp_n->path_len = 0;
	tmp_n->node = tmp_p->node->next[s->r];
	if (tmp_n->node->r_val == 0)
	{
		tmp_n->node->block = 1;
		tmp_n->node->visited = 1;
	}
	tmp_p->next = tmp_n;
	tmp_n->prev = tmp_p;
}
