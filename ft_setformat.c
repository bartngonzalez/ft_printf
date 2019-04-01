/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:43:35 by bgonzale          #+#    #+#             */
/*   Updated: 2019/03/20 13:08:13 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Checks for length modifiers hh, h, ll, l, L
** hh = 1, h = 2, ll = 3. l = 4, L = 5
*/

void	ft_islen(char *str, t_fwplc *ptrfwplc)
{
	int	pos;

	pos = ptrfwplc->pos;
	ptrfwplc->length = 0;
	if (str[pos] == 'h' && str[pos + 1] == 'h')
		ptrfwplc->length = 1;
	else if (str[pos] == 'h')
		ptrfwplc->length = 2;
	else if (str[pos] == 'l' && str[pos + 1] == 'l')
		ptrfwplc->length = 3;
	else if (str[pos] == 'l')
		ptrfwplc->length = 4;
	else if (str[pos] == 'L')
		ptrfwplc->length = 5;
	if (ptrfwplc->length == 1 || ptrfwplc->length == 3)
		pos += 2;
	else if (ptrfwplc->length == 2 || ptrfwplc->length == 4
			|| ptrfwplc->length == 5)
		pos += 1;
	ptrfwplc->pos = pos;
}

void	ft_isprec(char *str, t_fwplc *ptrfwplc)
{
	int		i;
	int		pos;
	char	numbrs_str[1000];

	i = 0;
	ptrfwplc->precision = -1;
	pos = ptrfwplc->pos;
	if (str[pos] == '.')
	{
		pos++;
		while (str[pos] >= '0' && str[pos] <= '9')
		{
			numbrs_str[i] = str[pos];
			pos++;
			i++;
		}
		numbrs_str[i] = '\0';
		ptrfwplc->precision = ft_atoi(numbrs_str);
	}
	ptrfwplc->pos = pos;
}

void	ft_isminw(char *str, t_fwplc *ptrfwplc)
{
	int		pos;
	int		i;
	char	numbrs_str[1000];

	i = 0;
	pos = ptrfwplc->pos;
	ptrfwplc->minw = 0;
	if (str[pos] >= '0' && str[pos] <= '9')
	{
		while (str[pos] >= '0' && str[pos] <= '9')
		{
			numbrs_str[i] = str[pos];
			i++;
			pos++;
		}
	}
	numbrs_str[i] = '\0';
	ptrfwplc->minw = ft_atoi(numbrs_str);
	ptrfwplc->pos = pos;
}

/*
** Checks every char after % to find flags, min-width, precision,
** length, and conversion type. Calls format function to begin printing.
*/

void	ft_setformat(char *format, t_fwplc *ptrfwplc, t_flags *ptrflags,
		va_list arg)
{
	format++;
	ptrfwplc->pos = 0;
	ft_isflags(format, ptrfwplc, ptrflags);
	ft_isminw(format, ptrfwplc);
	ft_isprec(format, ptrfwplc);
	ft_islen(format, ptrfwplc);
	ft_convtype(format, ptrfwplc);
	ft_format(ptrfwplc, ptrflags, arg);
}
