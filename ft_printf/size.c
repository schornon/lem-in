/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 20:25:46 by schornon          #+#    #+#             */
/*   Updated: 2019/05/02 17:03:49 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_size(t_pfl *h)
{
	h->s_l = 0;
	h->s_h = 0;
	while (h->chr == 'l' && (h->chr = h->fmt[++h->i]))
		h->s_l++;
	while (h->chr == 'h' && (h->chr = h->fmt[++h->i]))
		h->s_h++;
	if (h->chr == 'L' && (h->chr = h->fmt[++h->i]))
		h->s_l = 3;
	if (h->s_l != 0 || h->s_h != 0)
		h->size = 1;
}

void		str_build(t_pfl *h)
{
	h->cnt = ft_strlen(h->vs);
	h->ti = -1;
	if (ft_strcmp(h->vs, "") != 0)
	{
		while (h->n_prec > h->ti + 1)
			h->t_buff = ft_jchar_f(h->t_buff, h->vs[++h->ti]);
		if (h->f_prec == 0 && h->f_dot != 1)
			while (h->n_prec < h->cnt && h->cnt--)
				h->t_buff = ft_jchar_f(h->t_buff, h->vs[++h->ti]);
		h->cnt = ft_strlen(h->t_buff);
		while (h->n_width > h->cnt && h->f_zero == 1 &&
			h->f_left == 0 && ++h->cnt)
			h->t_buff = ft_jchar_f_i(h->t_buff, '0', 0);
		while (h->n_width > h->cnt && h->cnt++)
			h->t_buff = ft_jchar_f_i(h->t_buff, ' ', 0);
		h->ti = -1;
		if (ft_strcmp(h->t_buff, "") == 0)
			while (h->n_width > ++h->ti)
				h->t_buff = ft_jchar_f_i(h->t_buff, ' ', 0);
	}
	if (ft_strcmp(h->vs, "") == 0)
		while (h->n_width > ++h->ti)
			h->t_buff = ft_jchar_f_i(h->t_buff, ' ', 0);
	left_side(h);
}

void		str_control(t_pfl *h)
{
	if (h->n_width > 0 || h->n_prec > 0 || h->f_dot == 1)
		str_build(h);
	else if (h->f_prec == 0)
		h->t_buff = ft_strjoin_f(h->t_buff, h->vs);
	h->buff = ft_strjoin_f(h->buff, h->t_buff);
	t_buff_remalloc(h);
}

void		pntr_control(t_pfl *h)
{
	itoa_build_pointer(h);
	h->buff = ft_strjoin_f(h->buff, h->t_buff);
	t_buff_remalloc(h);
}

void		char_control(t_pfl *h)
{
	int		len;

	len = 1;
	h->cnt = ft_strlen(h->buff);
	if (h->n_width != 0 || h->n_prec != 0)
	{
		if (h->vi != 0)
			h->t_buff = ft_jchar_f(h->t_buff, h->vi);
		if (h->vi == 0)
			h->count_corrector += 1;
		while (h->n_width > len && h->f_zero == 1 && h->f_left == 0 && len++)
			h->t_buff = ft_jchar_f_i(h->t_buff, '0', 0);
		while (h->n_width > len && (h->f_zero == 0 || h->f_left == 1) && len++)
			h->t_buff = ft_jchar_f_i(h->t_buff, ' ', 0);
	}
	if (h->n_width == 0 && h->n_prec == 0)
	{
		if (h->vi != 0)
			h->t_buff = ft_jchar_f(h->t_buff, h->vi);
		if (h->vi == 0)
			zero_char_case(h);
	}
	left_side(h);
	h->buff = ft_strjoin_f(h->buff, h->t_buff);
	t_buff_remalloc(h);
}
