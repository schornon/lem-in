/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_pf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:01:20 by schornon          #+#    #+#             */
/*   Updated: 2019/04/29 16:09:57 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*ft_strjoin_f(char *s1, char const *s2)
{
	char	*answer;
	int		i;
	int		j;

	if (s1 && !s2)
		return (ft_strdup_f(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && s2)
	{
		if (!(answer = (char*)malloc(sizeof(char) *
			(ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		i = -1;
		while (s1[++i] != '\0')
			answer[i] = s1[i];
		j = -1;
		while (s2[++j] != '\0')
			answer[i + j] = s2[j];
		answer[i + j] = '\0';
		free(s1);
		return (answer);
	}
	return (NULL);
}

char		*ft_jchar_f(char *s, char chr)
{
	char	*answer;
	int		i;

	i = -1;
	if (s && chr)
	{
		if (!(answer = (char*)malloc(sizeof(char) * ft_strlen(s) + 2)))
			return (NULL);
		while (s[++i] != '\0')
			answer[i] = s[i];
		answer[i] = chr;
		answer[i + 1] = '\0';
		free(s);
		return (answer);
	}
	return (NULL);
}

char		*ft_jchar_f_i(char *s, char chr, int j)
{
	char	*answer;
	int		i;

	i = ft_strlen(s);
	if (s && chr)
	{
		if (!(answer = (char*)malloc(sizeof(char) * i + 2)))
			return (NULL);
		i += 1;
		answer[i] = '\0';
		while (--i != j)
			answer[i] = s[i - 1];
		answer[i] = chr;
		while (--i >= 0)
			answer[i] = s[i];
		free(s);
		return (answer);
	}
	return (NULL);
}

char		*ft_jchar_f_w(char *s, char chr)
{
	char	*answer;
	int		i;
	int		len;

	len = ft_strlen(s);
	if (s && chr)
	{
		if (!(answer = (char*)malloc(sizeof(char) * len + 2)))
			return (NULL);
		answer[len + 1] = '\0';
		i = -1;
		while (!(s[++i] >= '0' && s[i] <= '9'))
			answer[i] = s[i];
		answer[i] = chr;
		while (++i <= len)
			answer[i] = s[i - 1];
		free(s);
		return (answer);
	}
	return (NULL);
}

char		*ft_strdup_f(char *src)
{
	char	*s;
	int		len;

	len = 0;
	while (src[len])
		++len;
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len] = '\0';
	while (len >= 0)
	{
		s[len] = src[len];
		len--;
	}
	free(src);
	return (s);
}
