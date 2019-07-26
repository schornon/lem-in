/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 20:59:47 by schornon          #+#    #+#             */
/*   Updated: 2019/05/17 13:47:00 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	my_exit(void)
{
	ft_printf("Error.\n");
	exit(0);
}

void	validate_same_names(t_s *s, t_rm *rm)
{
	t_rm *curr;

	curr = rm;
	while (curr->next != NULL)
	{
		if (ft_strcmp(curr->rms[0], s->buff) == 0)
		{
			ft_printf("Error. Same room names\n");
			exit(0);
		}
		curr = curr->next;
	}
}

int		check_one_link(t_s *s)
{
	t_qu *tmp_p;

	if (s->p_cnt == 1)
	{
		tmp_p = s->s_path[0];
		while (tmp_p->next != NULL)
		{
			if (tmp_p->node->r_val == 1)
				break ;
			tmp_p = tmp_p->next;
		}
		if (tmp_p->node->r_val == 1)
		{
			if (tmp_p->node->links == 1)
				return (1);
		}
	}
	return (0);
}

int		l_validate(char *line)
{
	if (*line == 'L')
		return (1);
	return (0);
}

void	rooms_validator_ext(char *line)
{
	int flag;

	flag = l_validate(line);
	while (*line)
	{
		if (*line == ' ')
			break ;
		line++;
	}
	if (*line == ' ')
	{
		line++;
		while (*line)
		{
			if (!((*line >= '0' && *line <= '9') || *line == ' '))
				flag = 1;
			line++;
		}
	}
	if (flag == 1)
	{
		ft_printf("Error. Not valid room\n");
		exit(0);
	}
}
