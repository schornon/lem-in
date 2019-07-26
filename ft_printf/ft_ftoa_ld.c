/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_ld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:01:30 by schornon          #+#    #+#             */
/*   Updated: 2019/02/24 19:06:17 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long			ft_pow_ld(int x, unsigned int n)
{
	if (n == 0)
		return (1);
	if (n % 2 == 0)
		return (ft_pow_ld(x, n / 2) * ft_pow_ld(x, n / 2));
	else
		return (x * ft_pow_ld(x, n / 2) * ft_pow_ld(x, n / 2));
}

char						*conv_f_ld(unsigned long long num, int base)
{
	static char	rep[] = "0123456789abcdef";
	char		*temp;
	static char	buffer[50];
	char		*ptr;

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

long double					round_f(long double number, int decimal_places)
{
	long double power;

	power = ft_pow(10, decimal_places);
	number *= power;
	if (number >= 0)
	{
		if ((long long)number % 2 == 0)
			return (((long long)(number + 0.4)) / power);
		return (((long long)(number + 0.5)) / power);
	}
	else
		return (((long long)(number - 0.5)) / power);
	return (0);
}

char						*ft_ftoa_ld(long double num, int aft_point)
{
	char				*res;
	char				*res2;
	unsigned long long	ipart;
	long double			fpart;

	res = (char*)malloc(50);
	num = check_num_ld(num, aft_point);
	ipart = (unsigned long long)num;
	fpart = num - (long double)ipart;
	res2 = conv_f_ld(ipart, 10);
	if (aft_point != 0)
	{
		res = ft_strcpy_pf(res, res2);
		fpart = fpart * ft_pow_ld(10, aft_point);
		if ((long double)fpart != (long double)(unsigned long long)fpart)
			fpart = fpart + (fpart - (long double)(unsigned long long)fpart);
		res = ft_strjoin_f(res, conv_f_ld((unsigned long long)(fpart), 10));
		while (fpart == 0.0 && ft_strlen_ac(res, '.') <= aft_point)
			res = ft_jchar_f(res, '0');
		while (ft_strlen_ac(res, '.') <= aft_point)
			res = ft_jchar_f_i(res, '0', ft_strlen(res2) + 1);
		return (res);
	}
	free(res);
	return (res2);
}

int							ft_strlen_ac(char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (i);
	while (s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}
