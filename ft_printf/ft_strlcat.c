/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:07:29 by schornon          #+#    #+#             */
/*   Updated: 2018/10/26 15:07:29 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		j;
	size_t	dstlen;
	size_t	srclen;

	i = ft_strlen(dst);
	j = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize < dstlen + 1)
		return (srclen + dstsize);
	if (dstsize > dstlen + 1)
	{
		while (i < dstsize - 1)
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	return (dstlen + srclen);
}
