/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:12:52 by schornon          #+#    #+#             */
/*   Updated: 2019/05/19 14:49:39 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	show_me_paths(t_s *s)
{
	int		i;
	t_qu	*tmp_p;

	i = -1;
	while (++i < s->p_cnt)
	{
		tmp_p = s->s_path[i];
		ft_printf("\nPath {magn}%d{eoc-} | path_len is {magn}%d{eoc-} :\n",
			i, tmp_p->path_len);
		while (tmp_p->next != NULL)
			tmp_p = tmp_p->next;
		while (tmp_p != NULL)
		{
			if (tmp_p->node->r_val == 1)
				ft_printf("|{cyan}%s{eoc-}->", tmp_p->node->name);
			else if (tmp_p->node->r_val == 2)
				ft_printf("{red-}%s{eoc-}|", tmp_p->node->name);
			else
				ft_printf("{yell}%s{eoc-}->", tmp_p->node->name);
			tmp_p = tmp_p->prev;
		}
		ft_printf("\n");
	}
}

void	usage(int ac, char **av)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-help") == 0)
		{
			ft_printf("{red-}flags list:{eoc-}\n");
			ft_printf("     {cyan}-print_paths{eoc-}\n");
			ft_printf("     {cyan}-psc{eoc-}   -   print_steps_count\n");
			exit(0);
		}
	}
}

void	bonus(t_s *s, int ac, char **av)
{
	s->i = 0;
	while (++s->i < ac)
	{
		if (ft_strcmp(av[s->i], "-print_paths") == 0)
		{
			show_me_paths(s);
			if (s->p_cnt == 0 && s->s_path[0]->path_len == 2)
				ft_printf("\n|{cyan}%s{eoc-}->{red-}%s{eoc-}|\n",
				s->s_path[0]->next->node->name, s->s_path[0]->node->name);
		}
		if (ft_strcmp(av[s->i], "-psc") == 0)
			ft_printf("Steps: '%d'\n", s->steps_count);
	}
}
