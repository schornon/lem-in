/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:14:51 by schornon          #+#    #+#             */
/*   Updated: 2019/04/29 18:22:27 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include "libft.h"

typedef struct		s_pfl
{
	va_list			arg;
	char			*fmt;
	int				i;
	int				cnt;
	char			chr;
	char			*t_buff;
	int				ti;
	char			*buff;
	int				f_f;
	int				f_left;
	int				f_plus;
	int				f_minus;
	int				f_space;
	int				f_sharp;
	int				f_zero;
	int				f_width;
	int				f_prec;
	int				f_dot;
	int				size;
	int				n_width;
	int				n_prec;
	int				s_l;
	int				s_h;
	int				vi;
	char			*vs;
	long long		vp;
	long long		vlli;
	double			vd;
	long double		vld;
	void			*vdp;
	int				isvoid;
	int				a_p;
	int				count_corrector;
}					t_pfl;

int					ft_printf(const char *format, ...);
t_pfl				*ft_lstnewp(const char *format);
void				list_free(t_pfl *head);
char				*ft_jchar_f(char *s, char chr);
char				*ft_strjoin_f(char *s1, char const *s2);
char				*ft_jchar_f_i(char *s, char chr, int j);
char				*ft_jchar_f_w(char *s, char chr);
void				t_buff_remalloc(t_pfl *head);
void				check_flag(t_pfl *h);
int					arg_star(t_pfl *h);
void				check_size(t_pfl *h);
int					arg_to_head(t_pfl *h);
void				itoa_control(t_pfl *h);
void				str_control(t_pfl *h);
void				transform_dec(t_pfl *h);
void				transform_dec_lli(t_pfl *h);
void				transform_dec_h(t_pfl *h);
void				transform_hex(t_pfl *h);
void				transform_hex_lli(t_pfl *h);
void				transform_hex_h(t_pfl *h);
void				transform_oct(t_pfl *h);
void				transform_oct_lli(t_pfl *h);
void				transform_oct_h(t_pfl *h);
void				transform_float(t_pfl *h);
void				transform_float_ld(t_pfl *h);
void				transform_binary(t_pfl *h);
char				*ft_ftoa(double num, int aft_point, char *res2);
char				*ft_ftoa_ld(long double num, int aft_point);
char				*ft_strcpy_pf(char *dst, const char *src);
char				*ft_strjoin_dfree(char *s1, char *s2);
void				procent(t_pfl *h);
long double			round_f(long double number, int decimal_places);
unsigned long long	ft_pow(int x, unsigned int n);
char				*conv(unsigned int num, int base, t_pfl *head);
char				*conv_f(unsigned long long num, int base);
char				*conv_lli(unsigned long long num, int base, t_pfl *head);
void				itoa_build(t_pfl *h);
void				left_side(t_pfl *h);
void				itoa_build_hex(t_pfl *h);
void				itoa_build_pointer(t_pfl *h);
void				itoa_build_float(t_pfl *h);
void				char_control(t_pfl *h);
void				pntr_control(t_pfl *h);
char				*ft_joinchar_free_0(char *s, char chr);
void				check_rainbow(t_pfl *h);
int					ft_strlen_ac(char *s, char c);
double				check_num_d(double num, int aft_point);
long double			check_num_ld(long double num, int aft_point);
int					read_s(t_pfl *h);
int					check_del_n_n(t_pfl *h);
void				sign_check(t_pfl *h);
void				sharp_check(t_pfl *h);
char				*b_remalloc(char *buff);
void				zero_char_case(t_pfl *h);

#endif
