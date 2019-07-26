/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:54:32 by schornon          #+#    #+#             */
/*   Updated: 2019/03/05 17:01:25 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strndup(const char *src, int n)
{
	char	*s;
	int		len;

	len = 0;
	while (src[len] && len < n - 1)
		++len;
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len] = '\0';
	while (len >= 0)
	{
		s[len] = src[len];
		len--;
	}
	return (s);
}

void		build_null_s(t_pfl *h)
{
	if (h->n_prec > 0)
	{
		free(h->t_buff);
		h->t_buff = ft_strndup("(null)", h->n_prec);
		while (--h->n_width - h->n_prec >= 0)
			h->t_buff = ft_jchar_f_i(h->t_buff, ' ', 0);
	}
	if (h->n_prec == 0)
	{
		if (h->n_width > 6)
		{
			h->t_buff = ft_strjoin_f(h->t_buff, "(null)");
			h->n_width -= 6;
		}
		while (--h->n_width >= 0)
			h->t_buff = ft_jchar_f_i(h->t_buff, ' ', 0);
	}
	h->buff = ft_strjoin_f(h->buff, h->t_buff);
	t_buff_remalloc(h);
}

int			read_s(t_pfl *h)
{
	h->vdp = va_arg(h->arg, void *);
	if (h->vdp != NULL)
	{
		h->vs = h->vdp;
		return (1);
	}
	if (h->vdp == NULL)
	{
		h->vs = "(null)\0";
		if (h->n_width > 0 || h->n_prec > 0)
			build_null_s(h);
		else if (h->f_prec == 0 && h->f_width == 0 && h->f_dot == 0)
			h->buff = ft_strjoin_f(h->buff, "(null)");
		return (0);
	}
	return (0);
}

int			check_del_n_n(t_pfl *h)
{
	if (h->chr == 'f' || h->chr == 'F')
	{
		if ((h->s_l == 0 || h->s_l == 1) && h->s_h == 0)
		{
			if (h->vd == 1.0 / 0.0 &&
				(h->buff = ft_strjoin_f(h->buff, "inf")))
				return (0);
			if (h->vd == -1.0 / 0.0 &&
				(h->buff = ft_strjoin_f(h->buff, "-inf")))
				return (0);
		}
		if (h->s_l == 3)
		{
			if (h->vld == 1.0 / 0.0 &&
				(h->buff = ft_strjoin_f(h->buff, "inf")))
				return (0);
			if (h->vld == -1.0 / 0.0 &&
				(h->buff = ft_strjoin_f(h->buff, "-inf")))
				return (0);
		}
	}
	return (1);
}

void		itoa_build_float(t_pfl *h)
{
	sign_check(h);
	sharp_check(h);
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
	while (h->f_zero == 1 && h->n_width >= h->cnt++)
		h->t_buff = ft_jchar_f_w(h->t_buff, '0');
	left_side(h);
}
