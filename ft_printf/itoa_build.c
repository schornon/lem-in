/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:02:42 by schornon          #+#    #+#             */
/*   Updated: 2019/03/05 16:52:38 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		left_side(t_pfl *h)
{
	char	temp;
	int		i;
	int		j;

	h->cnt = ft_strlen(h->t_buff);
	if (h->f_left == 1 && h->t_buff[0] == ' ')
	{
		i = 0;
		j = 0;
		while (h->t_buff[j] == ' ')
			j++;
		if (h->f_space == 1)
			j--;
		while (j < h->cnt)
		{
			temp = h->t_buff[j];
			h->t_buff[j] = h->t_buff[i];
			h->t_buff[i] = temp;
			i++;
			j++;
		}
	}
}

void		sharp_check(t_pfl *h)
{
	int		i;
	int		f;

	i = -1;
	f = 0;
	if ((h->chr == 'f' || h->chr == 'F') && h->f_sharp == 1)
	{
		while (h->t_buff[++i] != '\0')
			h->t_buff[i] == '.' ? f = 1 : 1;
		if (f != 1)
			h->t_buff = ft_jchar_f(h->t_buff, '.');
	}
	if ((h->chr == 'x' || h->chr == 'X') && h->f_sharp == 1 &&
		(h->vi != 0 || h->s_l > 0))
	{
		if (h->t_buff[0] != '0')
		{
			h->t_buff = ft_jchar_f_i(h->t_buff, '0', 0);
			if (h->chr == 'x')
				h->t_buff = ft_jchar_f_i(h->t_buff, 'x', 1);
			if (h->chr == 'X')
				h->t_buff = ft_jchar_f_i(h->t_buff, 'X', 1);
		}
	}
}

void		sign_check(t_pfl *h)
{
	h->chr == 'u' ? h->f_minus = 0 : 1;
	if (h->f_minus == -1)
		h->t_buff = ft_jchar_f_i(h->t_buff, '-', 0);
	if (h->f_plus == 1 && h->t_buff[0] != '-')
		h->t_buff = ft_jchar_f_i(h->t_buff, '+', 0);
	if (h->f_space == 1 && h->f_plus == 0 && h->f_minus == 0)
		h->t_buff = ft_jchar_f_i(h->t_buff, ' ', 0);
}

void		itoa_build(t_pfl *h)
{
	if ((h->f_dot == 1 || h->f_prec == 1) && h->n_prec == 0 && h->vi == 0)
		h->t_buff[0] != '\0' ? t_buff_remalloc(h) : 0;
	sign_check(h);
	sharp_check(h);
	if (h->chr == 'o' && h->f_sharp == 1 && ft_strcmp(h->t_buff, "0") != 0)
		h->t_buff = ft_jchar_f_i(h->t_buff, '0', 0);
	h->cnt = ft_strlen(h->t_buff);
	h->f_left == 1 ? h->f_zero = 0 : 0;
	if (h->f_plus == 1 || h->f_minus == -1 || h->f_space == 1)
		while (h->n_prec >= h->cnt && h->cnt++)
			h->t_buff = ft_jchar_f_w(h->t_buff, '0');
	while ((h->chr == 'f' || h->chr == 'F') && ++h->a_p <= h->n_prec)
		h->t_buff = ft_jchar_f(h->t_buff, '0');
	h->cnt = ft_strlen(h->t_buff);
	while (h->n_prec > h->cnt++)
		h->t_buff = ft_jchar_f_w(h->t_buff, '0');
	while (h->f_zero == 0 && h->n_width >= h->cnt++)
		h->t_buff = ft_jchar_f_i(h->t_buff, ' ', 0);
	while (h->f_zero == 1 && h->f_prec == 1 && h->n_width >= h->cnt++)
		h->t_buff = ft_jchar_f_i(h->t_buff, ' ', 0);
	while (h->f_zero == 1 && h->f_dot == 1 && h->n_width >= h->cnt++)
		h->t_buff = ft_jchar_f_i(h->t_buff, ' ', 0);
	while (h->f_zero == 1 && h->n_width >= h->cnt++)
		h->t_buff = ft_jchar_f_w(h->t_buff, '0');
	left_side(h);
}

void		itoa_build_hex(t_pfl *h)
{
	if ((h->f_dot == 1 || h->f_prec == 1) && h->n_prec == 0 && h->vi == 0)
		h->t_buff[0] != '\0' ? t_buff_remalloc(h) : 0;
	sign_check(h);
	sharp_check(h);
	h->cnt = ft_strlen(h->t_buff);
	while (h->f_sharp == 0 && h->n_prec > h->cnt && h->cnt++)
		h->t_buff = ft_jchar_f_i(h->t_buff, '0', 0);
	while (h->f_sharp == 1 && h->n_prec != 0 &&
		h->n_prec + 2 > h->cnt && h->cnt++)
		h->t_buff = ft_jchar_f_i(h->t_buff, '0', 2);
	while (h->f_sharp == 0 && h->n_width > h->cnt && h->cnt++)
		h->f_zero == 0 ? (h->t_buff = ft_jchar_f_i(h->t_buff, ' ', 0)) :
	(h->t_buff = ft_jchar_f_i(h->t_buff, '0', 0));
	while (h->f_sharp == 1 && h->n_width > h->cnt && ++h->cnt)
	{
		if (h->f_left == 0)
			h->f_zero == 0 ? (h->t_buff = ft_jchar_f_i(h->t_buff, ' ', 0)) :
		(h->t_buff = ft_jchar_f_i(h->t_buff, '0', 2));
		if (h->f_left == 1)
			h->t_buff = ft_jchar_f_i(h->t_buff, ' ', 0);
	}
	left_side(h);
}
