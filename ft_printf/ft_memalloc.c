/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 01:43:23 by schornon          #+#    #+#             */
/*   Updated: 2018/10/28 01:43:24 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *buff;

	if (!(buff = (void*)malloc(size)))
		return (NULL);
	ft_bzero(buff, size);
	return (buff);
}
