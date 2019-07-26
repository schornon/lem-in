/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:19:29 by schornon          #+#    #+#             */
/*   Updated: 2019/04/29 17:48:18 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_strjoin_dfree(char *s1, char *s2)
{
	char			*answer;
	int				i;
	int				j;

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
		if (s1)
			free(s1);
		if (s2)
			free(s2);
		return (answer);
	}
	return (NULL);
}

unsigned long long	ft_pow(int x, unsigned int n)
{
	if (n == 0)
		return (1);
	if (n % 2 == 0)
		return (ft_pow(x, n / 2) * ft_pow(x, n / 2));
	else
		return (x * ft_pow(x, n / 2) * ft_pow(x, n / 2));
}

char				*conv_f(unsigned long long num, int base)
{
	static char		rep[] = "0123456789abcdef";
	char			*temp;
	static char		buffer[50];
	char			*ptr;

	temp = rep;
	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0)
		*--ptr = '0';
	if (num != 0)
	{
		*--ptr = temp[num % base];
		num /= base;
	}
	while (num != 0)
	{
		*--ptr = temp[num % base];
		num /= base;
	}
	return (ptr);
}

char				*ft_strcpy_pf(char *dst, const char *src)
{
	int				i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '.';
	dst[i + 1] = '\0';
	return (dst);
}

char				*ft_ftoa(double num, int aft_point, char *res2)
{
	char				*res;
	unsigned long long	ipart;
	double				fpart;

	res = (char*)malloc(50);
	num = check_num_d(num, aft_point);
	ipart = (unsigned long long)num;
	fpart = num - (double)ipart;
	res2 = conv_f(ipart, 10);
	if (aft_point != 0)
	{
		res = ft_strcpy_pf(res, res2);
		fpart = fpart * ft_pow(10, aft_point);
		if (fpart != (double)(unsigned long long)fpart)
			fpart = fpart + (fpart - (double)(unsigned long long)fpart);
		res = ft_strjoin_f(res, conv_f((unsigned long long)(fpart), 10));
		while (fpart == 0.0 && ft_strlen_ac(res, '.') <= aft_point)
			res = ft_jchar_f(res, '0');
		while (ft_strlen_ac(res, '.') <= aft_point)
			res = ft_jchar_f_i(res, '0', ft_strlen(res2) + 1);
		return (res);
	}
	free(res);
	return (res2);
}
