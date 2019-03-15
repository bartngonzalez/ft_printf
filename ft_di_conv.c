/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:07:11 by bgonzale          #+#    #+#             */
/*   Updated: 2019/03/14 18:08:37 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_di_conv_help(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str)
{
	int mwidth;

	if (ptrflags->minus)
	{
		if (ptrfwplc->minw > (int)ft_strlen(str) &&
		ptrfwplc->minw > ptrfwplc->precision)
		{
			if (ptrfwplc->precision > (int)ft_strlen(str))
			{
				mwidth = 0;
				while (mwidth < ptrfwplc->minw - ptrfwplc->precision)
				{
					ft_putchar(' ');
					mwidth++;
				}
				while (mwidth <= ptrfwplc->precision - (int)ft_strlen(str))
				{
					ft_putchar('0');
					mwidth++;
				}
				ft_putstr(str);
			}
			else
			{
				ft_putstr(str);
				mwidth = 1;
				while (mwidth <= ptrfwplc->minw - (int)ft_strlen(str))
				{
					ft_putchar(' ');
					mwidth++;
				}
			}
		}
		else if (ptrfwplc->precision > (int)ft_strlen(str)
		&& ptrfwplc->precision > ptrfwplc->minw)
		{
			mwidth = 0;
			while (mwidth < ptrfwplc->precision - (int)ft_strlen(str))
			{
				ft_putchar('0');
				mwidth++;
			}
			ft_putstr(str);
		}
	}
	else
	{
		if (ptrfwplc->minw > (int)ft_strlen(str) &&
		ptrfwplc->minw > ptrfwplc->precision)
		{
			if (ptrfwplc->precision > (int)ft_strlen(str))
			{
				mwidth = 0;
				while (mwidth < ptrfwplc->minw - ptrfwplc->precision)
				{
					ft_putchar(' ');
					mwidth++;
				}
				while (mwidth <= ptrfwplc->precision - (int)ft_strlen(str))
				{
					ft_putchar('0');
					mwidth++;
				}
			}
			else
			{
				mwidth = 1;
				while (mwidth <= ptrfwplc->minw - (int)ft_strlen(str))
				{
					ft_putchar(' ');
					mwidth++;
				}
			}
		}
		else if (ptrfwplc->precision > (int)ft_strlen(str)
		&& ptrfwplc->precision > ptrfwplc->minw)
		{
			mwidth = 0;
			while (mwidth < ptrfwplc->precision - (int)ft_strlen(str))
			{
				ft_putchar('0');
				mwidth++;
			}
		}
		ft_putstr(str);
	}
}

int		ft_di_base(t_fwplc *ptrfwplc, t_flags *ptrflags,
	unsigned long nbr, int base)
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
	ft_di_conv_help(ptrfwplc, ptrflags, str);
	free(str);
	return (1);
}

int		ft_di_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	int		i;

	i = va_arg(arg, int);
	if ((long)i == 2147483648 || (long)i == -2147483648)
	{
		ft_putstr("-2147483648");
		return (1);
	}
	if (i < 0)
	{
		i = i * -1;
		ft_putchar('-');
	}
	ft_di_base(ptrfwplc, ptrflags, i, 10);
	return (1);
}
