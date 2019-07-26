/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:19:06 by schornon          #+#    #+#             */
/*   Updated: 2019/05/17 13:50:44 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	create_map(t_s *s)
{
	s->map = (int**)malloc(sizeof(int*) * s->rm_cnt);
	s->r = -1;
	while (++s->r < s->rm_cnt)
	{
		s->map[s->r] = (int*)malloc(sizeof(int) * s->rm_cnt);
		s->i = -1;
		while (++s->i < s->rm_cnt)
			s->map[s->r][s->i] = 0;
	}
	s->f_ant = 3;
}

char	**tab_char_remalloc(char **tab, int row)
{
	char	**res;
	int		i;

	i = -1;
	res = (char**)malloc(sizeof(char*) * row);
	while (++i < row - 1)
		res[i] = ft_strdup_f(tab[i]);
	free(tab);
	return (res);
}

void	add_room(t_s *s, t_rm *rm)
{
	t_rm *curr;

	curr = rm;
	if (s->rm_cnt > 0)
		curr = add_r_list(rm);
	validate_same_names(s, rm);
	curr->rms[0] = ft_strdup(s->buff);
	s->buff = bl_remalloc(s->buff);
	if (s->f_word == 1 && s->f_word++)
		curr->r_val = 1;
	if (s->f_word == 3 && s->f_word++)
		curr->r_val = 2;
	s->rm_cnt++;
}

t_s		*create_struct(void)
{
	t_s *new;

	if (!(new = (t_s*)malloc(sizeof(t_s))))
		return (NULL);
	new->buff = (char*)malloc(sizeof(char));
	new->buff[0] = '\0';
	new->i = 0;
	new->r = 0;
	new->ants = 0;
	new->f_ant = 0;
	new->rm_cnt = 0;
	new->f_word = 0;
	new->r_start = 0;
	new->r_end = 0;
	new->act_rm = 0;
	new->links_cnt = 0;
	new->max_lvl = 0;
	new->pai = 0;
	new->steps_count = 0;
	new->paths = (char**)malloc(sizeof(char*));
	new->p_cnt = 0;
	return (new);
}
