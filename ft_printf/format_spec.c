/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:01:30 by schornon          #+#    #+#             */
/*   Updated: 2019/03/04 13:58:12 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_precision(t_pfl *h)
{
	h->n_prec = 0;
	if (h->chr == '.' && (h->chr = h->fmt[++h->i]))
	{
		while (h->chr >= '0' && h->chr <= '9')
		{
			h->t_buff = ft_jchar_f(h->t_buff, h->chr);
			h->chr = h->fmt[++h->i];
		}
		if (h->t_buff[0] != '\0')
		{
			h->f_prec = 1;
			h->n_prec = ft_atoi(h->t_buff);
			t_buff_remalloc(h);
		}
		if (h->chr == '*')
		{
			h->n_prec = arg_star(h);
			h->f_prec = 1;
		}
		if (h->f_prec != 1)
			h->f_dot = 1;
	}
}

void		get_width(t_pfl *h)
{
	while (h->chr >= '0' && h->chr <= '9')
	{
		h->t_buff = ft_jchar_f(h->t_buff, h->chr);
		h->chr = h->fmt[++h->i];
	}
	if (h->t_buff[0] != '\0')
	{
		h->n_width = ft_atoi(h->t_buff);
		t_buff_remalloc(h);
	}
}

void		check_width(t_pfl *h)
{
	if (h->chr >= '0' && h->chr <= '9' && (h->f_width = 1))
		get_width(h);
	if (h->chr == '*' && (h->f_width = 1))
		h->n_width = arg_star(h);
}

void		form_to_0(t_pfl *h)
{
	h->f_f = 0;
	h->f_left = 0;
	h->f_plus = 0;
	h->f_space = 0;
	h->f_sharp = 0;
	h->f_zero = 0;
	h->f_minus = 0;
	h->f_width = 0;
	h->f_prec = 0;
	h->f_dot = 0;
	h->size = 0;
	h->n_width = 0;
	h->n_prec = 0;
}

void		check_flag(t_pfl *h)
{
	int i;

	i = -1;
	form_to_0(h);
	while (++i <= 10)
	{
		if (h->chr == '+' && (h->chr = h->fmt[++h->i]))
			h->f_plus = 1;
		if (h->chr == '#' && (h->chr = h->fmt[++h->i]))
			h->f_sharp = 1;
		if (h->chr == '-' && (h->chr = h->fmt[++h->i]))
			h->f_left = 1;
		if (h->chr == '#' && (h->chr = h->fmt[++h->i]))
			h->f_sharp = 1;
		if (h->chr == ' ' && (h->chr = h->fmt[++h->i]))
			h->f_space = 1;
		if (h->chr == '0' && (h->chr = h->fmt[++h->i]))
			h->f_zero = 1;
	}
	check_width(h);
	check_precision(h);
	check_size(h);
}
