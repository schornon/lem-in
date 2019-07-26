/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:41:11 by schornon          #+#    #+#             */
/*   Updated: 2018/10/26 16:41:11 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	int		i;

	last = NULL;
	i = -1;
	while (++i < (int)ft_strlen(s) + 1)
		if (*(s + i) == (char)c)
			last = (char *)s + i;
	if (last == NULL)
		return (NULL);
	return (last);
}
