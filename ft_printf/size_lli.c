/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_lli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:01:30 by schornon          #+#    #+#             */
/*   Updated: 2019/03/05 16:51:27 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*conv_lli(unsigned long long num, int base, t_pfl *head)
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

void		transform_dec_lli(t_pfl *h)
{
	if (h->vlli < 0 && h->chr != 'u')
	{
		h->vlli = -h->vlli;
		h->f_minus = -1;
	}
	h->t_buff = ft_strjoin_f(h->t_buff, conv_lli(h->vlli, 10, h));
	itoa_build(h);
	h->buff = ft_strjoin_f(h->buff, h->t_buff);
	t_buff_remalloc(h);
}

void		transform_hex_lli(t_pfl *h)
{
	h->t_buff = ft_strjoin_f(h->t_buff, \
		conv_lli((unsigned long long)h->vlli, 16, h));
	itoa_build_hex(h);
	h->buff = ft_strjoin_f(h->buff, h->t_buff);
	t_buff_remalloc(h);
}

void		transform_oct_lli(t_pfl *h)
{
	h->t_buff = ft_strjoin_f(h->t_buff, \
		conv_lli((unsigned long long)h->vlli, 8, h));
	itoa_build(h);
	h->buff = ft_strjoin_f(h->buff, h->t_buff);
	t_buff_remalloc(h);
}
