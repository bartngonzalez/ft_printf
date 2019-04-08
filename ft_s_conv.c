/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:02:34 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/08 04:46:11 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_s_right(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str)
{
	int		str_len;
	int		mwidth;
	int		prec;

	str_len =
	(ptrfwplc->precision >= 0 && ptrfwplc->precision <= ft_strlen(str))
	? ptrfwplc->precision : ft_strlen(str);
	mwidth = 0;
	prec = 0;
	if (ptrfwplc->minw > str_len)
	{
		while (mwidth < ptrfwplc->minw - str_len)
		{
			(ptrflags->zero) ? ft_putchar('0') : ft_putchar(' ');
			mwidth++;
		}
	}
	if (ptrfwplc->precision > -1)
	{
		while (prec < str_len)
			ft_putchar(str[prec++]);
	}
	else
		ft_putstr(str);
	return (str_len + mwidth);
}

int		ft_s_left(t_fwplc *ptrfwplc, char *str)
{
	int		str_len;
	int		mwidth;
	int		prec;

	str_len =
	(ptrfwplc->precision >= 0 && ptrfwplc->precision <= ft_strlen(str))
	? ptrfwplc->precision : ft_strlen(str);
	mwidth = 0;
	prec = 0;
	if (ptrfwplc->precision > -1)
	{
		while (prec < str_len)
			ft_putchar(str[prec++]);
	}
	else
		ft_putstr(str);
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

int		ft_s_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	char	*str;
	int		str_len;

	str = va_arg(arg, char *);
	str_len = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (ptrflags->minus)
		str_len = ft_s_left(ptrfwplc, str);
	else
		str_len = ft_s_right(ptrfwplc, ptrflags, str);
	return (str_len);
}
