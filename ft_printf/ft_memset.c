/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:36:13 by schornon          #+#    #+#             */
/*   Updated: 2018/10/25 13:36:16 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	size_t			i;
	unsigned char	*res;

	i = 0;
	res = (unsigned char*)destination;
	while (i < n)
	{
		res[i++] = c;
	}
	return (res);
}
