/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 04:55:47 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/08 06:53:12 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_percent_right(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str)
{
	int		str_len;
	int		mwidth;

	str_len = ft_strlen(str);
	mwidth = 0;
	if (ptrfwplc->minw > str_len)
	{
		while (mwidth < ptrfwplc->minw - str_len)
		{
			(ptrflags->zero) ? ft_putchar('0') : ft_putchar(' ');
			mwidth++;
		}
	}
	ft_putstr(str);
	return (str_len + mwidth);
}

int		ft_percent_left(t_fwplc *ptrfwplc, char *str)
{
	int		str_len;
	int		mwidth;

	str_len = ft_strlen(str);
	mwidth = 0;
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

int		ft_percent_conv(t_fwplc *ptrfwplc, t_flags *ptrflags)
{
	char	str[2];
	int		str_len;

	str[0] = '%';
	str[1] = '\0';
	str_len = 0;
	if (ptrflags->minus)
		str_len = ft_percent_left(ptrfwplc, str);
	else
		str_len = ft_percent_right(ptrfwplc, ptrflags, str);
	return (str_len);
}
