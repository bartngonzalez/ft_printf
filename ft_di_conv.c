/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:07:11 by bgonzale          #+#    #+#             */
/*   Updated: 2019/03/15 19:40:35 by bart             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_left(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str, int is_neg)
{
	int str_len;
	int mwidth;
	int ex_space;

	str_len = (int)ft_strlen(str);
	ex_space = 0;
	if (ptrfwplc->minw > str_len && ptrfwplc->precision == -1)
	{
		mwidth = 0;
		ft_putstr(str);
		while (mwidth < ptrfwplc->minw - str_len)
		{
			ft_putchar(' ');
			mwidth++;
		}
	}
	else if (ptrfwplc->precision > -1)
	{
		mwidth = 0;
		if (is_neg == 0 && (ptrflags->plus || ptrflags->space))
		{
			if (ptrflags->plus)
			{
				ft_putchar('+');
			}
			else if (ptrflags->space)
			{
				ft_putchar(' ');
			}
			ex_space = 1;
		}
		if (ptrfwplc->precision > str_len)
		{
			while (mwidth < ptrfwplc->precision - str_len)
			{
				ft_putchar('0');
				mwidth++;
			}
		}
		ft_putstr(str);
		if (ptrfwplc->minw > mwidth + str_len)
		{
			mwidth += str_len + ex_space;
			while (mwidth < ptrfwplc->minw)
			{
				ft_putchar(' ');
				mwidth++;
			}
		}
	}
	else
	{
		if (is_neg == 0 && (ptrflags->plus || ptrflags->space))
		{
			if (ptrflags->plus)
			{
				ft_putchar('+');
			}
			else if (ptrflags->space)
			{
				ft_putchar(' ');
			}
		}
		ft_putstr(str);
	}
}

void	ft_di_conv_help(t_fwplc *ptrfwplc, t_flags *ptrflags,
	char *str, int is_neg)
{
	if (ptrflags->minus)
	{
		ft_left(ptrfwplc, ptrflags, str, is_neg);
	}
}

int		ft_di_base(t_fwplc *ptrfwplc, t_flags *ptrflags,
	unsigned long nbr, int base, int is_neg)
{
	unsigned long	i;
	unsigned long	len;
	char			*str;
	char			num;

	i = 0;
	len = ft_nbr_len(nbr, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	str[len] = '\0';
	while (nbr != 0)
	{
		len--;
		num = ("0123456789abcdef"[nbr % base]);
		str[len] = num;
		nbr /= base;
		i++;
	}
	ft_di_conv_help(ptrfwplc, ptrflags, str, is_neg);
	free(str);
	return (1);
}

int		ft_di_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	int		i;
	int is_neg;

	i = va_arg(arg, int);
	is_neg = 0;
	if ((long)i == 2147483648 || (long)i == -2147483648)
	{
		ft_putstr("-2147483648");
		return (1);
	}
	if (i < 0)
	{
		is_neg = 1;
		i = i * -1;
		ft_putchar('-');
	}
	ft_di_base(ptrfwplc, ptrflags, i, 10, is_neg);
	return (1);
}
