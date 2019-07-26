/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:26:09 by schornon          #+#    #+#             */
/*   Updated: 2019/03/04 12:17:42 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				arg_star(t_pfl *h)
{
	int num;

	num = va_arg(h->arg, int);
	h->chr = h->fmt[++h->i];
	return (num);
}

void			t_buff_remalloc(t_pfl *h)
{
	free(h->t_buff);
	h->t_buff = NULL;
	h->t_buff = (char*)malloc(sizeof(char) * 1);
	h->t_buff[0] = 0;
}

int				arg_to_head(t_pfl *h)
{
	if (h->chr == 'c')
		h->vi = va_arg(h->arg, int);
	if (h->chr == 's' && read_s(h) == 0)
		return (0);
	if (h->chr == 'p')
		h->vp = va_arg(h->arg, long long);
	if (h->s_l == 0 && h->s_h == 0)
		if (h->chr == 'd' || h->chr == 'i' || h->chr == 'o' ||
			h->chr == 'x' || h->chr == 'X' || h->chr == 'u')
			h->vi = va_arg(h->arg, int);
	if (h->s_l == 1 || h->s_l == 2)
		h->vlli = va_arg(h->arg, long long);
	if (h->s_h == 1 || h->s_h == 2)
		h->vi = va_arg(h->arg, int);
	if (h->chr == 'f' || h->chr == 'F')
	{
		if ((h->s_l == 0 || h->s_l == 1) && h->s_h == 0)
			h->vd = va_arg(h->arg, double);
		if (h->s_l == 3)
			h->vld = va_arg(h->arg, long double);
	}
	if (h->chr == 'b')
		h->vlli = va_arg(h->arg, long long);
	return (check_del_n_n(h));
}

double			check_num_d(double num, int aft_point)
{
	if (aft_point < 18 && (long long)num % 2 == 0 && aft_point != 0)
		num = round_f(num, aft_point + 1);
	else
		num = round_f(num, aft_point);
	return (num);
}

long double		check_num_ld(long double num, int aft_point)
{
	if (aft_point < 18 && (long long)num % 2 == 0)
		num = round_f(num, aft_point + 1);
	else
		num = round_f(num, aft_point);
	return (num);
}
