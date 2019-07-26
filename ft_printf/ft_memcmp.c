/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:43:35 by schornon          #+#    #+#             */
/*   Updated: 2018/10/25 19:43:37 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1cln;
	unsigned char	*s2cln;

	i = -1;
	s1cln = (unsigned char*)s1;
	s2cln = (unsigned char*)s2;
	while (++i < n && *(s1cln + i) == *(s2cln + i))
		;
	if (i == n)
		return (0);
	return (s1cln[i] - s2cln[i]);
}
