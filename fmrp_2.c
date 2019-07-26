/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmrp_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:19:06 by schornon          #+#    #+#             */
/*   Updated: 2019/05/19 14:17:50 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		count_visited(t_s *s)
{
	int i;
	int v;

	v = 0;
	i = -1;
	while (++i < s->rm_cnt)
	{
		if (s->gph[i]->block == 1)
			v++;
	}
	return (v);
}

void	find_paths_len(t_s *s)
{
	t_qu	*tmp_p;
	int		*p_len;
	int		k;
	int		k2;

	k = 0;
	s->rm_cnt > 1500 ? k = 1 : 0;
	k2 = 0;
	s->p_cnt == 0 ? (k2 = 1) : 0;
	s->i = -1;
	while (++s->i < s->p_cnt - k + k2)
	{
		tmp_p = s->s_path[s->i];
		p_len = &tmp_p->path_len;
		while (tmp_p != NULL)
		{
			(*p_len)++;
			tmp_p = tmp_p->next;
		}
		*p_len > 2 ? *p_len -= 2 : 0;
	}
}

void	sort_paths(t_s *s)
{
	t_qu *tmp;

	if (s->p_cnt > 1)
	{
		s->i = 0;
		while (s->i + 1 < s->p_cnt)
		{
			if (s->s_path[s->i]->path_len > s->s_path[s->i + 1]->path_len)
			{
				tmp = s->s_path[s->i];
				s->s_path[s->i] = s->s_path[s->i + 1];
				s->s_path[s->i + 1] = tmp;
				s->i = -1;
			}
			s->i++;
		}
	}
}

int		path_validator(t_qu *tmp_p)
{
	t_qu *t;

	if (tmp_p->node->r_val == 1)
	{
		return (1);
	}
	if (tmp_p->node->r_val != 2)
	{
		t = tmp_p;
		tmp_p = tmp_p->prev;
		free(t);
		while (tmp_p->prev != NULL)
		{
			t = tmp_p;
			tmp_p->node->visited = 0;
			tmp_p->node->block = 0;
			tmp_p = tmp_p->prev;
			free(t);
		}
		tmp_p->next = NULL;
		return (0);
	}
	return (2);
}
