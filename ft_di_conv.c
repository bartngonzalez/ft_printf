/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:07:11 by bgonzale          #+#    #+#             */
/*   Updated: 2019/03/20 19:29:51 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_di_right(t_fwplc *ptrfwplc, t_flags *ptrflags,
	char *str, int *base_isneg)
{
	int		str_len;
	int		ps_space;
	int		mwidth;
	int		mwidth_max;
	int		prec_space;
	int		neg_space;

	str_len = ft_strlen(str);
	ps_space = (base_isneg[1] == 0 && (ptrflags->plus || ptrflags->space))
	? 1 : 0;
	mwidth = 0;
	mwidth_max = (ptrfwplc->precision > str_len)
	? ptrfwplc->precision : str_len;
	prec_space = 0;
	neg_space = (base_isneg[1] == 1) ? 1 : 0;
	if (ptrfwplc->minw > str_len && ptrfwplc->precision == -1)
	{
		if (ptrflags->zero == 0)
		{
			while (mwidth < ptrfwplc->minw - str_len - ps_space - neg_space)
			{
				ft_putchar(' ');
				mwidth++;
			}
		}
		ft_di_plus_space(ptrflags, base_isneg[1]);
		if (neg_space)
			ft_putchar('-');
		if (ptrflags->zero == 1)
		{
			while (mwidth < ptrfwplc->minw - str_len - ps_space - neg_space)
			{
				ft_putchar('0');
				mwidth++;
			}
		}
		ft_putstr(str);
	}
	else if (ptrfwplc->precision > -1)
	{
		if (ptrfwplc->minw > mwidth_max)
		{
			while (mwidth < ptrfwplc->minw - mwidth_max
				- neg_space - ps_space)
			{
				ft_putchar(' ');
				mwidth++;
			}
		}
		ft_di_plus_space(ptrflags, base_isneg[1]);
		if (neg_space)
			ft_putchar('-');
		if (ptrfwplc->precision > str_len)
		{
			while (prec_space < ptrfwplc->precision - str_len)
			{
				ft_putchar('0');
				prec_space++;
			}
		}
		ft_putstr(str);
	}
	else
	{
		ft_di_plus_space(ptrflags, base_isneg[1]);
		if (neg_space)
			ft_putchar('-');
		ft_putstr(str);
	}
}

void	ft_di_conv_help(t_fwplc *ptrfwplc, t_flags *ptrflags,
	char *str, int *base_isneg)
{
	if (ptrflags->minus)
	{
		if (base_isneg[1] == 1)
			ft_putchar('-');
		ft_di_left(ptrfwplc, ptrflags, str, base_isneg);
	}
	else
	{
		ft_di_right(ptrfwplc, ptrflags, str, base_isneg);
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
	base_isneg[1] = (nbr < 0) ? 1 : 0;
	if ((long)nbr == 2147483648 || (long)nbr == -2147483648)
	{
		ft_putstr("-2147483648");
		return (1);
	}
	if (nbr < 0)
	{
		nbr = nbr * -1;
	}
	ft_di_base(ptrfwplc, ptrflags, nbr, base_isneg);
	return (1);
}
