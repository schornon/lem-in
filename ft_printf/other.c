/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:33:45 by schornon          #+#    #+#             */
/*   Updated: 2019/03/05 16:17:25 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		transform_binary(t_pfl *h)
{
	h->t_buff = ft_strjoin_f(h->t_buff, conv_lli(h->vlli, 2, h));
	itoa_build(h);
	h->buff = ft_strjoin_f(h->buff, h->t_buff);
}

void		create_pb(char **paint_board)
{
	paint_board[0] = "{eoc-}\0";
	paint_board[1] = "{red-}\0";
	paint_board[2] = "{blue}\0";
	paint_board[3] = "{yell}\0";
	paint_board[4] = "{magn}\0";
	paint_board[5] = "{gree}\0";
	paint_board[6] = "{cyan}\0";
	paint_board[7] = "{pink}\0";
	paint_board[8] = "{grey}\0";
}

void		stir_pnt(char **stir_paint)
{
	stir_paint[0] = "\033[0m";
	stir_paint[1] = "\033[91;m";
	stir_paint[2] = "\033[94;m";
	stir_paint[3] = "\033[93;m";
	stir_paint[4] = "\033[35;m";
	stir_paint[5] = "\033[92;m";
	stir_paint[6] = "\033[36;m";
	stir_paint[7] = "\033[95;m";
	stir_paint[8] = "\033[90;m";
}

void		check_rainbow(t_pfl *h)
{
	int		j;
	char	*check;
	char	*paint_board[9];
	char	*stir_paint[9];

	j = -1;
	check = malloc(7);
	create_pb(paint_board);
	stir_pnt(stir_paint);
	while (++j < 7)
	{
		check[j] = h->fmt[h->i + j];
	}
	check[6] = '\0';
	j = -1;
	while (++j < 9)
	{
		if (ft_strcmp(check, paint_board[j]) == 0)
		{
			h->buff = ft_strjoin_f(h->buff, stir_paint[j]);
			h->i += 6;
			h->chr = h->fmt[h->i];
		}
	}
	free(check);
}

void		procent(t_pfl *h)
{
	int	len;

	len = 1;
	h->t_buff = ft_jchar_f(h->t_buff, h->chr);
	while (h->n_width > len && ++len)
		h->t_buff = ft_jchar_f_i(h->t_buff, ' ', 0);
	left_side(h);
	h->buff = ft_strjoin_f(h->buff, h->t_buff);
	t_buff_remalloc(h);
}
