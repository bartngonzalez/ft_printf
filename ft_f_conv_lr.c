/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_conv_lr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:23:57 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/05 21:40:26 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_f_right_help(t_fwplc *ptrfwplc, int str_len,
		int mwidth, char *str)
{
	if (str[0] == '-')
	{
		str[0] = 0;
		ft_putchar('-');
	}
	while (mwidth < ptrfwplc->minw - str_len)
	{
		ft_putchar('0');
		mwidth++;
	}
	return (mwidth);
}

int		ft_f_right(t_fwplc *ptrfwplc, t_flags *ptrflags,
		char *str, int *varz)
{
	int		mwidth;
	int		str_len;
	int		plus_space;

	mwidth = 0;
	plus_space = (varz[1] == 0 && (ptrflags->plus || ptrflags->space)) ? 1 : 0;
	str_len = varz[4] + (varz[1] - 1) + plus_space;
	if (ft_strchr(str, '.') == NULL)
		str_len -= 1;
	if (ptrflags->zero == 0 && ptrfwplc->minw > str_len)
	{
		while (mwidth < ptrfwplc->minw - str_len)
		{
			ft_putchar(' ');
			mwidth++;
		}
	}
	if (plus_space)
		(ptrflags->plus) ? ft_putchar('+') : ft_putchar(' ');
	if (ptrflags->zero == 1 && ptrfwplc->minw > str_len)
	{
		mwidth = ft_f_right_help(ptrfwplc, str_len, mwidth, str);
	}
	write(1, str, varz[4] + varz[1] - 1);
	return (str_len + mwidth);
}

int		ft_f_left(t_fwplc *ptrfwplc, t_flags *ptrflags,
		char *str, int *varz)
{
	int		mwidth;
	int		str_len;
	int		plus_space;

	mwidth = 0;
	plus_space = (varz[1] == 0 && (ptrflags->plus || ptrflags->space)) ? 1 : 0;
	str_len = varz[4] + (varz[1] - 1) + plus_space;
	if (ft_strchr(str, '.') == NULL)
		str_len -= 1;
	if (plus_space)
		(ptrflags->plus) ? ft_putchar('+') : ft_putchar(' ');
	write(1, str, varz[4] + varz[1] - 1);
	if (ptrfwplc->minw > str_len)
	{
		while (mwidth < ptrfwplc->minw - str_len)
		{
			ft_putchar(' ');
			mwidth++;
		}
	}
	return (str_len + mwidth);
}
