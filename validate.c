/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:19:06 by schornon          #+#    #+#             */
/*   Updated: 2019/05/13 13:03:20 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	validate_ants(t_s *s, char *line)
{
	int i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == ' ' && s->ants < 1)
		{
			ft_printf("Error. Not valid number of ants\n");
			exit(0);
		}
	}
}

void	validate_start_end(t_s *s)
{
	int i;
	int flag;

	flag = 0;
	i = -1;
	while (++i < s->rm_cnt)
	{
		if (s->gph[i]->r_val == 1 || s->gph[i]->r_val == 2)
			flag++;
	}
	if (flag != 2)
	{
		ft_printf("Error. Start or End room is absent\n");
		exit(0);
	}
}

void	validate_room_names(t_s *s)
{
	char	*tmp;
	int		i;
	int		r;

	i = -1;
	while (++i < s->rm_cnt)
	{
		tmp = s->gph[i]->name;
		r = -1;
		while (++r < s->rm_cnt)
		{
			if (i != r && ft_strcmp(s->gph[r]->name, tmp) == 0)
			{
				ft_printf("Error. Each room name must be unique\n");
				exit(0);
			}
		}
	}
}

void	validate_links(t_s *s)
{
	if (s->f_ant < 2)
	{
		ft_printf("Error. Map must have one or more links\n");
		exit(0);
	}
}

void	validate_min_one_way(t_s *s)
{
	if (s->minoneway == 0)
	{
		ft_printf("Error. There is no way from start to end\n");
		exit(0);
	}
}
