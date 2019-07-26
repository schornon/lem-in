/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:19:06 by schornon          #+#    #+#             */
/*   Updated: 2019/05/15 17:34:53 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_rm	*create_first_room(void)
{
	t_rm *new;

	if (!(new = (t_rm*)malloc(sizeof(t_rm))))
		return (NULL);
	new->rms = (char**)malloc(sizeof(char*));
	new->r_val = 0;
	new->links = 0;
	new->lvl = -1;
	new->visited = 0;
	new->next = NULL;
	return (new);
}

t_rm	*add_r_list(t_rm *rm)
{
	t_rm *new;

	new = rm;
	while (new->next != NULL)
		new = new->next;
	if (!(new->next = (t_rm*)malloc(sizeof(t_rm))))
		return (NULL);
	new = new->next;
	new->rms = (char**)malloc(sizeof(char*));
	new->r_val = 0;
	new->links = 0;
	new->lvl = -1;
	new->visited = 0;
	new->next = NULL;
	return (new);
}

void	connect_rooms(t_rm *curr, t_rm *curr_2)
{
	if (curr == NULL || curr_2 == NULL)
	{
		ft_printf("Error. Wrong rooms connections\n");
		exit(0);
	}
	if (ft_strcmp(curr->rms[0], curr_2->rms[0]) == 0 ||
		curr == NULL || curr_2 == NULL)
	{
		ft_printf("Error. Wrong rooms connections\n");
		exit(0);
	}
	curr->rms = tab_char_remalloc(curr->rms, ++curr->links + 1);
	curr_2->rms = tab_char_remalloc(curr_2->rms, ++curr_2->links + 1);
	curr->rms[curr->links] = ft_strdup(curr_2->rms[0]);
	curr_2->rms[curr_2->links] = ft_strdup(curr->rms[0]);
}
