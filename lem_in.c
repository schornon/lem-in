/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:56:56 by schornon          #+#    #+#             */
/*   Updated: 2019/05/19 14:28:04 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_tunnel(t_s *s, char *line)
{
	int i;

	i = -1;
	while (line[++i])
		if (line[i] == '-')
		{
			if (s->f_ant != 3 && s->f_ant != 0)
				s->f_ant = 2;
			break ;
		}
}

int		sharp_validate(char *line)
{
	int len;

	len = ft_strlen(line);
	if (len >= 5 && len <= 7)
	{
		if (line[0] == '#' && line[1] == '#')
			return (1);
	}
	if (len >= 2)
	{
		if (line[0] == '#' && line[1] != '#')
			return (2);
	}
	if (len > 0)
		if (line[0] != '#')
			return (3);
	return (0);
}

int		pars_master(t_s *s, char *line, t_rm *rm)
{
	check_tunnel(s, line);
	validate_ants(s, line);
	if ((s->f_ant == 2 || s->f_ant == 3) && line[0] != '#')
		pars_tunnels(s, line, rm);
	if (s->f_ant == 1 && sharp_validate(line) == 3)
		pars_rooms(s, line, rm);
	if (s->f_ant == 1 && sharp_validate(line) == 1)
		pars_words(s, line);
	if (s->f_ant == 0 && (line[0] >= '0' && line[0] <= '9'))
		pars_ants(s, line);
	return (0);
}

int		main(int ac, char **av)
{
	t_s		*s;
	t_rm	*rm;
	t_l		*l;
	t_l		*tmpl;

	s = create_struct();
	rm = create_first_room();
	usage(ac, av);
	l = input_validator(s);
	tmpl = l->next;
	while (tmpl != NULL)
	{
		pars_master(s, tmpl->input, rm);
		tmpl = tmpl->next;
	}
	validate_links(s);
	path_finder(s, rm);
	bonus(s, ac, av);
	return (0);
}
