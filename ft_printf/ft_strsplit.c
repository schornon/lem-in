/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 21:36:29 by schornon          #+#    #+#             */
/*   Updated: 2018/10/29 21:36:29 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_words(char const *s, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			words++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (words);
}

static char			*ft_strndup(const char *s, size_t n)
{
	char			*str;

	str = (char *)malloc(sizeof(char) * n + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}

char				**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		t;
	char	**tab;

	i = 0;
	t = 0;
	if (!s || (!(tab = (char**)malloc(sizeof(char *)
			* (ft_words(s, c)) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			tab[t] = ft_strndup(s + j, i - j);
			t++;
		}
	}
	tab[t] = NULL;
	return (tab);
}
