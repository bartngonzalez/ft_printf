/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:11:21 by bgonzale          #+#    #+#             */
/*   Updated: 2019/03/25 21:15:03 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_o_left(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str)
{
	int str_len;
	int is_hash;
	int mwidth;
	int prec_space;

	str_len = ft_strlen(str);
	is_hash = (ptrflags->hash) ? 1 : 0;
	mwidth = 0;
	prec_space = 0;
	if (ptrfwplc->minw > str_len && ptrfwplc->precision == -1)
	{
		if (is_hash)
		{
			ft_putchar('0');
		}
		ft_putstr(str);
		while (mwidth < ptrfwplc->minw - str_len - is_hash)
		{
			ft_putchar(' ');
			mwidth++;
		}
	}
	else if (ptrfwplc->precision > -1)
	{
		if (is_hash)
		{
			ft_putchar('0');
		}
		while (prec_space < ptrfwplc->precision - str_len - is_hash)
		{
			ft_putchar('0');
			prec_space++;
		}
		ft_putstr(str);
		if (ptrfwplc->minw > str_len + is_hash + prec_space)
		{
			mwidth = str_len + is_hash + prec_space;
			while (mwidth < ptrfwplc->minw)
			{
				ft_putchar(' ');
				mwidth++;
			}
		}
	}
}

void ft_o_conv_help(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str)
{
	if (ptrflags->minus)
	{
		ft_o_left(ptrfwplc, ptrflags, str);
	}
}

int		ft_o_base(t_fwplc *ptrfwplc, t_flags *ptrflags,
	unsigned long nbr, int base)
{
	unsigned long	len;
	char			*str;
	char			num;

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
	}
	ft_o_conv_help(ptrfwplc, ptrflags, str);
	free(str);
	return (1);
}

int		ft_o_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	unsigned int	nbr;

	nbr = va_arg(arg, unsigned int);
	ft_o_base(ptrfwplc, ptrflags, nbr, 8);
	return (1);
}
