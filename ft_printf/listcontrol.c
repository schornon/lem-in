/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listcontrol.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:32:16 by schornon          #+#    #+#             */
/*   Updated: 2019/05/11 10:19:17 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pfl	*ft_lstnewp(const char *format)
{
	t_pfl	*new;

	if (!(new = (t_pfl*)malloc(sizeof(t_pfl))))
		return (NULL);
	new->i = 0;
	new->cnt = 0;
	new->ti = 0;
	new->isvoid = 0;
	new->a_p = 0;
	new->count_corrector = 0;
	new->buff = (char*)malloc(sizeof(char) * 1);
	new->buff[0] = '\0';
	new->t_buff = (char*)malloc(sizeof(char) * 1);
	new->t_buff[0] = '\0';
	new->fmt = ft_strdup(format);
	return (new);
}

void	list_free(t_pfl *head)
{
	free(head->buff);
	free(head->t_buff);
	free(head->fmt);
	free(head);
}

void	itoa_build_pointer(t_pfl *h)
{
	if ((h->f_dot == 1 || h->f_prec == 1) && h->n_prec == 0 && h->vi == 0)
		h->t_buff = ft_strjoin_f(h->t_buff, "0x");
	else
	{
		h->t_buff = ft_strjoin_f(h->t_buff, "0x");
		h->t_buff = ft_strjoin_f(h->t_buff, \
		conv_lli((unsigned long long)h->vp, 16, h));
	}
	sign_check(h);
	h->cnt = ft_strlen(h->t_buff);
	while (h->n_prec + 2 > h->cnt && ++h->cnt)
		h->t_buff = ft_jchar_f_i(h->t_buff, '0', 2);
	while (h->n_width > h->cnt && ++h->cnt)
	{
		if (h->f_zero == 0)
			h->t_buff = ft_jchar_f_i(h->t_buff, ' ', 0);
		if (h->f_zero == 1 && h->f_prec == 0)
			h->t_buff = ft_jchar_f_i(h->t_buff, '0', 2);
	}
	h->cnt = ft_strlen(h->t_buff);
	while (h->n_width > h->cnt && ++h->cnt)
		h->t_buff = ft_jchar_f_i(h->t_buff, ' ', 0);
	left_side(h);
}

void	zero_char_case(t_pfl *h)
{
	write(1, h->buff, h->cnt);
	write(1, &h->vi, 1);
	h->buff = b_remalloc(h->buff);
	h->count_corrector += h->cnt + 1;
}

char	*b_remalloc(char *buff)
{
	free(buff);
	buff = NULL;
	buff = (char*)malloc(sizeof(char) * 1);
	buff[0] = 0;
	return (buff);
}
