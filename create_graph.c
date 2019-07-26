/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:19:06 by schornon          #+#    #+#             */
/*   Updated: 2019/05/03 11:25:21 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_g		*init_g(t_rm *curr)
{
	t_g *tmp;

	tmp = (t_g*)malloc(sizeof(t_g));
	tmp->name = ft_strdup(curr->rms[0]);
	tmp->r_val = curr->r_val;
	tmp->links = curr->links;
	tmp->lvl = -1;
	tmp->visited = curr->visited;
	tmp->block = curr->visited;
	tmp->links_in = 0;
	tmp->links_out = 0;
	return (tmp);
}

void	link_it(t_g **gph, t_rm *curr, t_s *s, int g)
{
	if (s->p_cnt == 0)
		gph[g]->next = (t_g**)malloc(sizeof(t_g*) * curr->links);
	gph[g]->next[s->p_cnt++] = gph[s->r];
}

void	init_g_links(t_g **gph, t_rm *rm, t_s *s)
{
	t_rm	*curr;
	int		g;

	curr = rm;
	g = -1;
	s->p_cnt = 0;
	while (curr)
	{
		s->p_cnt = 0;
		s->i = 0;
		g++;
		while (++s->i <= curr->links)
		{
			s->r = -1;
			while (++s->r < s->rm_cnt)
			{
				if (ft_strcmp(gph[s->r]->name, curr->rms[s->i]) == 0)
					link_it(s->gph, curr, s, g);
			}
		}
		curr = curr->next;
	}
	s->p_cnt = 0;
}

void	create_graph(t_s *s, t_rm *rm)
{
	t_rm	*curr;
	t_g		*tmp;

	curr = rm;
	s->gph = (t_g**)malloc(sizeof(t_g*) * (s->rm_cnt + 1));
	s->i = 0;
	while (curr)
	{
		tmp = init_g(curr);
		s->gph[s->i++] = tmp;
		curr = curr->next;
	}
	init_g_links(s->gph, rm, s);
}
