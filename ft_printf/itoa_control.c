/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:19:53 by schornon          #+#    #+#             */
/*   Updated: 2019/03/04 14:06:33 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		itoa_control2(t_pfl *h)
{
	if (h->chr == 'o')
	{
		if (h->s_l == 0 && h->s_h == 0)
			transform_oct(h);
		if (h->s_l == 1 || h->s_l == 2)
			transform_oct_lli(h);
		if (h->s_h == 1 || h->s_h == 2)
			transform_oct_h(h);
	}
	if (h->chr == 'f' || h->chr == 'F')
	{
		if (h->s_l < 3 && h->s_h < 3)
			transform_float(h);
		if (h->s_l == 3)
			transform_float_ld(h);
	}
	if (h->chr == 'b')
		transform_binary(h);
}

void		itoa_control(t_pfl *h)
{
	if (h->chr == 'd' || h->chr == 'i' || h->chr == 'u')
	{
		if (h->s_l == 0 && h->s_h == 0)
			transform_dec(h);
		if (h->s_l == 1 || h->s_l == 2)
			transform_dec_lli(h);
		if (h->s_h == 1 || h->s_h == 2)
			transform_dec_h(h);
	}
	if (h->chr == 'x' || h->chr == 'X')
	{
		if (h->s_l == 0 && h->s_h == 0)
			transform_hex(h);
		if (h->s_l == 1 || h->s_l == 2)
			transform_hex_lli(h);
		if (h->s_h == 1 || h->s_h == 2)
			transform_hex_h(h);
	}
	itoa_control2(h);
}
