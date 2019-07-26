/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 20:07:59 by schornon          #+#    #+#             */
/*   Updated: 2019/05/15 17:36:01 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rm	*pars_tunnels_ext(t_rm *curr, t_s *s)
{
	if (s->rm_cnt > 0)
	{
		while (curr != NULL)
		{
			if (ft_strcmp(curr->rms[0], s->buff) == 0)
				break ;
			curr = curr->next;
		}
	}
	else
	{
		ft_printf("Error. No rooms\n");
		exit(0);
	}
	return (curr);
}

void	path_finder(t_s *s, t_rm *rm)
{
	create_graph(s, rm);
	validate_start_end(s);
	validate_room_names(s);
	highwaytohell(s);
}
