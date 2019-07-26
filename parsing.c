/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:19:06 by schornon          #+#    #+#             */
/*   Updated: 2019/05/15 14:53:02 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	pars_tunnels(t_s *s, char *line, t_rm *rm)
{
	t_rm *curr;
	t_rm *curr_2;

	curr = rm;
	curr_2 = rm;
	s->i = -1;
	while (line[++s->i] != '-' && line[s->i] != '\0')
		if ((line[s->i] >= '0' && line[s->i] <= '9') ||
		(line[s->i] >= 'A' && line[s->i] <= 'z'))
			s->buff = ft_jchar_f(s->buff, line[s->i]);
	curr = pars_tunnels_ext(curr, s);
	s->buff = bl_remalloc(s->buff);
	while ((line[++s->i] >= '0' && line[s->i] <= '9') ||
		(line[s->i] >= 'A' && line[s->i] <= 'z'))
		s->buff = ft_jchar_f(s->buff, line[s->i]);
	curr_2 = pars_tunnels_ext(curr_2, s);
	connect_rooms(curr, curr_2);
	s->buff = bl_remalloc(s->buff);
	s->links_cnt++;
}

void	pars_words(t_s *s, char *line)
{
	if (ft_strncmp(&line[2], "start", 5) == 0)
		s->f_word = 1;
	if (ft_strncmp(&line[2], "end", 3) == 0)
		s->f_word = 3;
}

void	pars_rooms(t_s *s, char *line, t_rm *rm)
{
	s->i = -1;
	while (line[++s->i] != ' ' && line[s->i] != '\0')
	{
		s->buff = ft_jchar_f(s->buff, line[s->i]);
	}
	add_room(s, rm);
}

void	pars_ants(t_s *s, char *line)
{
	s->i = -1;
	while (line[++s->i] >= '0' && line[s->i] <= '9')
		s->buff = ft_jchar_f(s->buff, line[s->i]);
	s->ants = ft_atoi(s->buff);
	s->buff = bl_remalloc(s->buff);
	s->f_ant = 1;
	if (!(s->ants <= 2147483647 && s->ants > 0))
	{
		ft_printf("Error. Not valid numbers of ants\n");
		exit(0);
	}
}

char	*bl_remalloc(char *buff)
{
	ft_strdel(&buff);
	buff = NULL;
	buff = (char*)malloc(sizeof(char) * 1);
	buff[0] = 0;
	return (buff);
}
