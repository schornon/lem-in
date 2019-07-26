/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:16:59 by schornon          #+#    #+#             */
/*   Updated: 2018/10/25 16:17:01 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ucdst;
	unsigned char	*ucsrc;

	i = 0;
	ucsrc = (unsigned char*)src;
	ucdst = (unsigned char*)dst;
	while (i < n)
	{
		ucdst[i] = ucsrc[i];
		if (ucsrc[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
