/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 17:02:41 by schornon          #+#    #+#             */
/*   Updated: 2018/10/26 17:02:42 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	if (!*s2)
		return ((char *)s1);
	if (!*s1)
		return (NULL);
	if ((*s1 == *s2) && (ft_strstr(s1 + 1, s2 + 1) == s1 + 1))
		return ((char *)s1);
	return (ft_strstr(s1 + 1, s2));
}
