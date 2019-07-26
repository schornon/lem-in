/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:15:29 by schornon          #+#    #+#             */
/*   Updated: 2018/10/25 19:15:30 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sclone;
	unsigned char	c2;

	i = 0;
	c2 = (unsigned char)c;
	sclone = (unsigned char*)s;
	while (i < n)
	{
		if (sclone[i] == c2)
			return (&sclone[i]);
		i++;
	}
	return (NULL);
}
