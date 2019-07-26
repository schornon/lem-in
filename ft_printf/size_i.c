/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:06:10 by schornon          #+#    #+#             */
/*   Updated: 2019/03/05 17:00:28 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*conv(unsigned int num, int base, t_pfl *head)
{
	static char	rep[] = "0123456789abcdef";
	static char	rep_u[] = "0123456789ABCDEF";
	char		*temp;
	static char	buffer[50];
	char		*ptr;

	temp = rep;
	if (head->chr >= 'A' && head->chr <= 'Z')
		temp = rep_u;
	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0 && (*--ptr = '0'))
		return (ptr);
	if (num != 0)
	{
		*--ptr = temp[num % base];
		num /= base;
	}
	while (num != 0)
	{
		*--ptr = temp[num % base];
		num /= base;
	}
	return (ptr);
}

char		*conv_h(unsigned short num, int base, t_pfl *head)
{
	static char	rep[] = "0123456789abcdef";
	static char	rep_u[] = "0123456789ABCDEF";
	char		*temp;
	static char	buffer[50];
	char		*ptr;

	temp = rep;
	if (head->chr >= 'A' && head->chr <= 'Z')
		temp = rep_u;
	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0 && (*--ptr = '0'))
		return (ptr);
	if (num != 0)
	{
		*--ptr = temp[num % base];
		num /= base;
	}
	while (num != 0)
	{
		*--ptr = temp[num % base];
		num /= base;
	}
	return (ptr);
}

void		transform_dec_h(t_pfl *h)
{
	if (h->s_h == 1 && (short)h->vi < 0 && h->chr != 'u')
	{
		h->vi = (short)h->vi * -1;
		h->f_minus = -1;
	}
	if (h->s_h == 2 && (char)h->vi < 0 && h->chr != 'u')
	{
		h->vi = (char)h->vi * -1;
		h->f_minus = -1;
	}
	if (h->s_h == 1)
		h->t_buff = ft_strjoin_f(h->t_buff, \
			conv_h((unsigned short)h->vi, 10, h));
	else if (h->s_h == 2)
	{
		if (h->chr != 'u')
			h->t_buff = ft_strjoin_f(h->t_buff, \
				conv_h((char)h->vi, 10, h));
		if (h->chr == 'u')
			h->t_buff = ft_strjoin_f(h->t_buff, \
				conv_h((unsigned char)h->vi, 10, h));
	}
	itoa_build(h);
	h->buff = ft_strjoin_f(h->buff, h->t_buff);
	t_buff_remalloc(h);
}

void		transform_hex_h(t_pfl *h)
{
	if (h->s_h == 1)
		h->t_buff = ft_strjoin_f(h->t_buff, \
			conv_h((unsigned short)h->vi, 16, h));
	else if (h->s_h == 2)
		h->t_buff = ft_strjoin_f(h->t_buff, \
			conv_h((unsigned char)h->vi, 16, h));
	itoa_build_hex(h);
	h->buff = ft_strjoin_f(h->buff, h->t_buff);
	t_buff_remalloc(h);
}

void		transform_oct_h(t_pfl *h)
{
	if (h->s_h == 1)
		h->t_buff = ft_strjoin_f(h->t_buff, \
			conv_h((unsigned short)h->vi, 8, h));
	else if (h->s_h == 2)
		h->t_buff = ft_strjoin_f(h->t_buff, \
			conv_h((unsigned char)h->vi, 8, h));
	itoa_build(h);
	h->buff = ft_strjoin_f(h->buff, h->t_buff);
	t_buff_remalloc(h);
}
