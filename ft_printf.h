/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 20:32:55 by bgonzale          #+#    #+#             */
/*   Updated: 2019/03/09 18:47:41 by bgonzale         ###   ########.fr       */
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

/*
** ft_isflags.c
*/

void ft_isflags(char *str, t_fwplc *ptrfwplc, t_flags *ptrflags);
void ft_setflags(t_flags *ptrflags);
void ft_flagson(t_fwplc *ptrfwplc, t_flags *ptrflags);

/*
** ft_isminw.c
*/

void ft_isminw(char *str, t_fwplc *ptrfwplc);

/*
** ft_isprec.c
*/

void ft_isprec(char *str, t_fwplc *ptrfwplc);

/*
** ft_islen.c
*/

void ft_islen(char *str, t_fwplc *ptrfwplc);

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

/*
** ft_p_conv.c
*/

int		ft_p_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg);
int		ft_p_base(t_fwplc *ptrfwplc, t_flags *ptrflags,
	unsigned long nbr, int base);
void	ft_p_conv_help(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str);

int		ft_flags(char *str, va_list arg);
int		ft_base(unsigned long nbr, int base);

int		ft_d_i_flag(va_list arg);
int		ft_o_flag(va_list arg);
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
