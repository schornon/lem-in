/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 20:59:15 by schornon          #+#    #+#             */
/*   Updated: 2019/05/15 17:33:24 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_l		*create_lnode(char *line)
{
	t_l *tmpl;

	tmpl = (t_l*)malloc(sizeof(t_l));
	tmpl->input = ft_strdup(line);
	tmpl->next = NULL;
	return (tmpl);
}

int		what_is_it(char *line, int space, int sharp, t_s *s)
{
	int min;

	min = 0;
	while (*line != 0)
	{
		*line == '-' ? min++ : 0;
		*line == ' ' ? space++ : 0;
		if (*line == '#')
		{
			if (sharp == 1 && *(line - 1) == '#')
				sharp = 2;
			else
				sharp = 1;
		}
		line++;
	}
	if ((space == 2 || sharp == 2) && min == 0)
		return (1);
	if (min == 1 && space == 0 && sharp == 0)
	{
		s->f_ant = 2;
		return (2);
	}
	min > 0 ? (s->f_ant = 2) : 0;
	return (0);
}

void	word_link(t_s *s, t_l *tmpl)
{
	if (ft_strcmp(tmpl->input, "##start") == 0 ||
		ft_strcmp(tmpl->input, "##end") == 0)
	{
		if (tmpl->next != NULL)
		{
			s->r = what_is_it(tmpl->next->input, 0, 0, s);
			if (s->r != 1)
			{
				ft_printf("Error. Not valid map\n");
				exit(0);
			}
		}
		else
		{
			ft_printf("Error. Not valid map\n");
			exit(0);
		}
	}
}

void	in_v_step2(t_s *s, t_l *l)
{
	t_l *tmpl;
	int flag;

	flag = 0;
	tmpl = l->next;
	while (tmpl != NULL)
	{
		ft_printf("%s\n", tmpl->input);
		flag = what_is_it(tmpl->input, 0, 0, s);
		if (flag == 1)
			rooms_validator_ext(tmpl->input);
		if ((tmpl->input[0] != '#' && flag < s->f_ant) ||
			ft_strcmp(tmpl->input, "") == 0)
		{
			ft_printf("Error.\n");
			exit(0);
		}
		flag > s->f_ant ? (s->f_ant = flag) : 0;
		word_link(s, tmpl);
		tmpl = tmpl->next;
	}
	s->f_ant = 0;
}

t_l		*input_validator(t_s *s)
{
	t_l *l;
	t_l *tmpl;
	t_l *prevl;

	l = (t_l*)malloc(sizeof(t_l));
	l->input = (char*)malloc(sizeof(char));
	l->input[0] = '\0';
	l->next = NULL;
	prevl = l;
	while (get_next_line(0, &s->line) > 0)
	{
		tmpl = create_lnode(s->line);
		prevl->next = tmpl;
		prevl = prevl->next;
		ft_strdel(&s->line);
	}
	in_v_step2(s, l);
	return (l);
}
