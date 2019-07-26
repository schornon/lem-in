/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:52:19 by schornon          #+#    #+#             */
/*   Updated: 2019/03/05 16:58:34 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		transform_float_ld(t_pfl *h)
{
	h->a_p = h->n_prec;
	if (h->vld < 0)
	{
		h->vld = -h->vld;
		h->f_minus = -1;
	}
	if (h->n_prec == 0 && h->f_prec == 0 && (h->a_p = 6))
		h->n_prec = 6;
	if (h->f_dot == 1)
	{
		h->n_prec = 0;
		h->t_buff = ft_strjoin_f(h->t_buff, ft_ftoa_ld(h->vld, h->n_prec));
	}
	if (h->f_dot == 0)
	{
		if (h->n_prec >= 15)
			h->a_p = 15;
		h->t_buff = ft_strjoin_f(h->t_buff, ft_ftoa_ld(h->vld, h->a_p));
	}
	itoa_build_float(h);
	h->buff = ft_strjoin_f(h->buff, h->t_buff);
	t_buff_remalloc(h);
}

void		transform_float(t_pfl *h)
{
	h->a_p = h->n_prec;
	if (h->vd < 0)
	{
		h->vd = -h->vd;
		h->f_minus = -1;
	}
	if (h->n_prec == 0 && h->f_prec == 0 && (h->a_p = 6))
		h->n_prec = 6;
	if (h->f_dot == 1)
	{
		h->n_prec = 0;
		h->t_buff = ft_strjoin_f(h->t_buff, ft_ftoa(h->vd, h->n_prec, NULL));
	}
	if (h->f_dot == 0)
	{
		if (h->n_prec >= 15)
			h->a_p = 15;
		h->t_buff = ft_strjoin_f(h->t_buff, ft_ftoa(h->vd, h->a_p, NULL));
	}
	itoa_build_float(h);
	h->buff = ft_strjoin_f(h->buff, h->t_buff);
	t_buff_remalloc(h);
}

void		transform_dec(t_pfl *h)
{
	if (h->vi < 0 && h->chr != 'u')
	{
		h->vi = -h->vi;
		h->f_minus = -1;
	}
	h->t_buff = ft_strjoin_f(h->t_buff, conv((unsigned int)h->vi, 10, h));
	if ((h->f_dot == 1 || h->f_prec == 1) && h->n_prec == 0 && h->vi == 0)
		t_buff_remalloc(h);
	itoa_build(h);
	ft_strlen(h->t_buff) > 0 ? h->buff = ft_strjoin_f(h->buff, h->t_buff) : 0;
	ft_strlen(h->t_buff) > 0 ? t_buff_remalloc(h) : 0;
}

void		transform_hex(t_pfl *h)
{
	h->t_buff = ft_strjoin_f(h->t_buff, conv((unsigned int)h->vi, 16, h));
	itoa_build_hex(h);
	h->buff = ft_strjoin_f(h->buff, h->t_buff);
	t_buff_remalloc(h);
}

void		transform_oct(t_pfl *h)
{
	h->t_buff = ft_strjoin_f(h->t_buff, conv((unsigned int)h->vi, 8, h));
	itoa_build(h);
	h->buff = ft_strjoin_f(h->buff, h->t_buff);
	t_buff_remalloc(h);
}
