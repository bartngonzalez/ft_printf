/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 20:32:55 by bgonzale          #+#    #+#             */
/*   Updated: 2019/03/27 15:08:03 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_fwplc
{
	int flags;
	int minw;
	int precision;
	int length;
	char convtype;
	int pos;
} t_fwplc;

typedef struct s_flags
{
	int hash;
	int minus;
	int plus;
	int space;
	int zero;
} t_flags;

/*
** ft_printf.c
*/

int		ft_printf(const char *restrict format, ...);

/*
** ft_setformat.c
*/

void ft_setformat(char *format, t_fwplc *ptrfwplc, t_flags *ptrflags,
		va_list arg);
void ft_isminw(char *str, t_fwplc *ptrfwplc);
void ft_isprec(char *str, t_fwplc *ptrfwplc);
void ft_islen(char *str, t_fwplc *ptrfwplc);

/*
** ft_isflags.c
*/

void ft_isflags(char *str, t_fwplc *ptrfwplc, t_flags *ptrflags);
void ft_setflags(t_flags *ptrflags);
void ft_flagson(t_fwplc *ptrfwplc, t_flags *ptrflags);

/*
** ft_convtype.c
*/

void ft_convtype(char *str, t_fwplc *ptrfwplc);
void ft_convtype_2(char *str, t_fwplc *ptr);

/*
** ft_format.c
*/

void ft_format(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg);

/*
** ft_c_conv.c
*/

int		ft_c_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg);

/*
** ft_s_conv.c
*/

int		ft_s_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg);
char	*ft_s_conv_help(t_fwplc *ptrfwplc, t_flags *ptrflags,
	int *i_j_strsize, char *str);
char	*ft_s_conv_help_2(t_fwplc *ptrfwplc, int *i_j_strsize);

/*
** ft_p_conv.c
*/

int		ft_p_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg);
int		ft_p_base(t_fwplc *ptrfwplc, t_flags *ptrflags,
	unsigned long nbr, int base);
void	ft_p_conv_help(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str);
void	ft_p_conv_help_2(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str);

/*
** ft_di_conv.c
*/

int		ft_di_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg);
int		ft_di_base(t_fwplc *ptrfwplc, t_flags *ptrflags,
	unsigned long nbr, int *base_isneg);
void ft_di_conv_help(t_fwplc *ptrfwplc, t_flags *ptrflags,
	char *str, int *base_isneg);

/*
** ft_di_conv_2.c
*/

void ft_di_left(t_fwplc *ptrfwplc, t_flags *ptrflags,
	char *str, int *base_isneg);
void	ft_di_left_minw(t_fwplc *ptrfwplc, char *str, int *strlen_mw_ps_neg);
void	ft_di_left_precision(t_fwplc *ptrfwplc, char *str, int *strlen_mw_ps_neg);
void	ft_di_plus_space(t_flags *ptrflags, int is_neg);

/*
** ft_di_conv_3.c
*/

void ft_di_right(t_fwplc *ptrfwplc, t_flags *ptrflags,
	char *str, int *base_isneg);
void ft_di_right_minw(t_fwplc *ptrfwplc, t_flags *ptrflags,
	char *str, int *slen_ps_mw_mwmax_prec_in);
void ft_di_right_precision(t_fwplc *ptrfwplc, t_flags *ptrflags,
	char *str, int *slen_ps_mw_mwmax_prec_in);

/*
** ft_o_conv.c
*/

int		ft_o_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg);
int		ft_o_base(t_fwplc *ptrfwplc, t_flags *ptrflags,
	unsigned long nbr, int base);
void ft_o_conv_help(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str);

/*
** ft_o_conv_2.c
*/

void ft_o_left(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str);
void	ft_o_left_minw(t_fwplc *ptrfwplc, char *str, int *sl_ih_mw_ps);
void	ft_o_left_precision(t_fwplc *ptrfwplc, char *str, int *sl_ih_mw_ps);

/*
** ft_o_conv_3.c
*/

void	ft_o_right(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str);
void	ft_o_right_minw(t_fwplc *ptrfwplc, t_flags *ptrflags,
	char *str, int *sl_mw_ps_ih_mwm);
void	ft_o_right_precision(t_fwplc *ptrfwplc,
	char *str, int *sl_mw_ps_ih_mwm);

int		ft_flags(char *str, va_list arg);
int		ft_base(unsigned long nbr, int base);

int		ft_u_flag(va_list arg);
int		ft_x_flag(va_list arg);

/*
** ft_libft.c
*/

void	ft_putchar(char c);
void	ft_putstr(const char *str);
size_t	ft_strlen(const char *str);
int		ft_nbr_len(unsigned long nbr, int base);
int		ft_atoi(const char *str);

#endif
