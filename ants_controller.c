/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:45:59 by schornon          #+#    #+#             */
/*   Updated: 2019/05/19 14:43:15 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	run_ant_run(t_s *s)
{
	t_qu	*tmp_p;
	int		path_len;

	tmp_p = s->s_path[s->i];
	path_len = tmp_p->path_len;
	while (tmp_p->next != NULL)
		tmp_p = tmp_p->next;
	tmp_p->prev->node->visited = s->ant_name;
	s->ants--;
	ft_printf("L%d-%s ", tmp_p->prev->node->visited,
		tmp_p->prev->node->name);
	s->flag_n = 1;
	if (s->last_ant_dist < path_len)
		s->last_ant_dist = path_len;
}

int		check_pl_coef(t_s *s)
{
	int j;
	int res;

	j = -1;
	res = 0;
	while (++j < s->i)
	{
		res += s->s_path[s->i]->path_len - s->s_path[j]->path_len;
	}
	return (res);
}

void	push_prev_ants(t_s *s)
{
	t_qu *tmp_p;

	s->flag_n = 0;
	s->i = -1;
	while (++s->i < s->p_cnt)
	{
		tmp_p = s->s_path[s->i];
		while (tmp_p->next != NULL)
		{
			if (tmp_p->node->visited == 0 && tmp_p->next->node->visited > 0)
			{
				tmp_p->node->visited = tmp_p->next->node->visited;
				tmp_p->next->node->visited = 0;
				ft_printf("L%d-%s ", tmp_p->node->visited, tmp_p->node->name);
				s->flag_n = 1;
				if (tmp_p->node->r_val == 2)
					tmp_p->node->visited = 0;
			}
			tmp_p = tmp_p->next;
		}
	}
}

void	ants_controller(t_s *s)
{
	int	k;

	k = 0;
	s->p_cnt == 0 ? (k = 1) : 0;
	while (1)
	{
		push_prev_ants(s);
		s->i = -1;
		while (++s->i < s->p_cnt + k)
		{
			if (s->ants > check_pl_coef(s))
			{
				run_ant_run(s);
				s->ant_name++;
			}
		}
		s->last_ant_dist--;
		if (s->flag_n > 0)
			ft_printf("\n");
		s->steps_count++;
		if (!(s->last_ant_dist >= 0))
			break ;
	}
	if (s->p_cnt == 0 && s->s_path[0]->path_len == 2)
		s->steps_count -= 2;
}
