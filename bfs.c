/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:19:06 by schornon          #+#    #+#             */
/*   Updated: 2019/05/06 16:09:01 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	start_to_queue(t_s *s)
{
	s->q = (t_qu*)malloc(sizeof(t_qu));
	s->q->next = NULL;
	s->i = -1;
	while (++s->i < s->rm_cnt)
	{
		if (s->gph[s->i]->r_val == 1)
		{
			s->q->node = s->gph[s->i];
			s->q->node->visited = 1;
			s->q->node->lvl = 0;
			break ;
		}
	}
}

void	add_to_queue(t_s *s, t_qu *tmp_q)
{
	t_qu *tmp_n;
	t_qu *t;

	tmp_n = (t_qu*)malloc(sizeof(t_qu));
	tmp_n->next = NULL;
	tmp_n->node = tmp_q->node->next[s->i];
	tmp_n->node->lvl = s->max_lvl;
	tmp_n->node->visited = 1;
	t = s->q;
	while (t->next != NULL)
		t = t->next;
	t->next = tmp_n;
	if (tmp_n->node->r_val == 2)
		tmp_n->node->lvl = 2147483647;
}

void	bfs(t_s *s)
{
	t_qu *tmp_q;

	s->max_lvl = 1;
	s->minoneway = 0;
	start_to_queue(s);
	tmp_q = s->q;
	while (1)
	{
		s->i = -1;
		s->max_lvl++;
		while (++s->i < tmp_q->node->links)
		{
			if (tmp_q->node->r_val == 2)
			{
				s->minoneway = 1;
				break ;
			}
			if (tmp_q->node->next[s->i]->visited == 0)
				add_to_queue(s, tmp_q);
		}
		if (tmp_q->next == NULL)
			break ;
		tmp_q = tmp_q->next;
	}
}
