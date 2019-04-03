/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:23:05 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/02 21:37:36 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_p_conv_help_2(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str)
{
	int		i;
	int		str_len;

	i = 0;
	str_len = ft_strlen(str);
	if (ptrfwplc->minw > str_len)
	{
		while (i < ptrfwplc->minw - str_len - 2)
		{
			(ptrflags->zero) ? ft_putchar('0') : ft_putchar(' ');
			i++;
		}
	}
	ft_putstr("0x");
	ft_putstr(str);
	return (str_len + 2 + i);
}

int		ft_p_conv_help(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str)
{
	int		i;
	int		str_len;

	i = 0;
	str_len = ft_strlen(str);
	if (ptrflags->minus)
	{
		ft_putstr("0x");
		ft_putstr(str);
		if (ptrfwplc->minw > str_len)
		{
			while (i < ptrfwplc->minw - str_len - 2)
			{
				ft_putchar(' ');
				i++;
			}
		}
	}
	else
		return (ft_p_conv_help_2(ptrfwplc, ptrflags, str));
	return (str_len + 2 + i);
}

int		ft_p_base(t_fwplc *ptrfwplc, t_flags *ptrflags,
	long long nbr, int base)
{
	long long	len;
	char		*str;
	char		num;
	int			str_len;

	len = ft_nbr_len(nbr, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str_len = 0;
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
	str_len = (ft_p_conv_help(ptrfwplc, ptrflags, str));
	free(str);
	return (str_len);
}

int		ft_p_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	long long	nbr;

	nbr = va_arg(arg, long long);
	return (ft_p_base(ptrfwplc, ptrflags, nbr, 16));
}
