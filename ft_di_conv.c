/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:07:11 by bgonzale          #+#    #+#             */
/*   Updated: 2019/03/16 01:32:55 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_left(t_fwplc *ptrfwplc, t_flags *ptrflags,
		char *str, int *base_isneg)
{
	int		str_len;
	int		mwidth;
	int		ps_space;
	int		neg_space;

	str_len = (int)ft_strlen(str);
	ps_space = 0;
	neg_space = (base_isneg[1] == 1) ? 1 : 0;
	if (ptrfwplc->minw > str_len && ptrfwplc->precision == -1)
	{
		mwidth = 0;
		if (base_isneg[1] == 0 && (ptrflags->plus || ptrflags->space))
		{
			if (ptrflags->plus)
			{
				ft_putchar('+');
			}
			else if (ptrflags->space)
			{
				ft_putchar(' ');
			}
			ps_space = 1;
		}
		ft_putstr(str);
		while (mwidth < ptrfwplc->minw - str_len - ps_space - neg_space)
		{
			ft_putchar(' ');
			mwidth++;
		}
	}
	else if (ptrfwplc->precision > -1)
	{
		mwidth = 0;
		if (base_isneg[1] == 0 && (ptrflags->plus || ptrflags->space))
		{
			if (ptrflags->plus)
			{
				ft_putchar('+');
			}
			else if (ptrflags->space)
			{
				ft_putchar(' ');
			}
			ps_space = 1;
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
		if (ptrfwplc->minw > mwidth + str_len + ps_space + neg_space)
		{
			mwidth += str_len + ps_space + neg_space;
			while (mwidth < ptrfwplc->minw)
			{
				ft_putchar(' ');
				mwidth++;
			}
		}
	}
	else
	{
		if (base_isneg[1] == 0 && (ptrflags->plus || ptrflags->space))
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
	char *str, int *base_isneg)
{
	if (ptrflags->minus)
	{
		ft_left(ptrfwplc, ptrflags, str, base_isneg);
	}
}

int		ft_di_base(t_fwplc *ptrfwplc, t_flags *ptrflags,
	unsigned long nbr, int *base_isneg)
{
	unsigned long	i;
	unsigned long	len;
	char			*str;
	char			num;

	i = 0;
	len = ft_nbr_len(nbr, base_isneg[0]);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	str[len] = '\0';
	while (nbr != 0)
	{
		len--;
		num = ("0123456789abcdef"[nbr % base_isneg[0]]);
		str[len] = num;
		nbr /= base_isneg[0];
		i++;
	}
	ft_di_conv_help(ptrfwplc, ptrflags, str, base_isneg);
	free(str);
	return (1);
}

int		ft_di_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	int		nbr;
	int		base_isneg[2];

	nbr = va_arg(arg, int);
	base_isneg[0] = 10;
	base_isneg[1] = 0;
	if ((long)nbr == 2147483648 || (long)nbr == -2147483648)
	{
		ft_putstr("-2147483648");
		return (1);
	}
	if (nbr < 0)
	{
		base_isneg[1] = 1;
		nbr = nbr * -1;
		ft_putchar('-');
	}
	ft_di_base(ptrfwplc, ptrflags, nbr, base_isneg);
	return (1);
}
