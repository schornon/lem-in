/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:51:32 by schornon          #+#    #+#             */
/*   Updated: 2019/05/02 17:21:12 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	arg_control(t_pfl *h)
{
	h->chr = h->fmt[++h->i];
	check_flag(h);
	if (arg_to_head(h) == 1)
	{
		if (h->chr == 'd' || h->chr == 'i' || h->chr == 'u' || h->chr == 'o' ||
			h->chr == 'x' || h->chr == 'X' || h->chr == 'f' || h->chr == 'F')
			itoa_control(h);
		if (h->chr == 'b')
			itoa_control(h);
		if (h->chr == 'c')
			char_control(h);
		if (h->chr == 's')
			str_control(h);
		if (h->chr == 'p')
			pntr_control(h);
		if (h->chr == '%')
			procent(h);
	}
}

int		ft_printf(const char *format, ...)
{
	t_pfl	*h;

	h = ft_lstnewp(format);
	va_start(h->arg, format);
	while ((h->chr = format[h->i]) != '\0')
	{
		if (h->chr == '{')
			check_rainbow(h);
		if (h->chr != '%')
			h->buff = ft_jchar_f(h->buff, h->chr);
		if (h->chr == '%')
			arg_control(h);
		h->i++;
	}
	h->cnt = ft_strlen(h->buff);
	write(1, h->buff, h->cnt);
	list_free(h);
	va_end(h->arg);
	return (h->cnt + h->count_corrector);
}
