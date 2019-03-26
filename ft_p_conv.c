/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:23:05 by bgonzale          #+#    #+#             */
/*   Updated: 2019/03/25 17:40:49 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_p_conv_help_2(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str)
{
	int		i;
	int		str_len;
	char	s_z;

	i = 0;
	str_len = ft_strlen(str);
	if (ptrfwplc->minw > str_len)
	{
		s_z = (ptrflags->zero) ? '0' : ' ';
		while (i < ptrfwplc->minw - str_len - 2)
		{
			ft_putchar(s_z);
			i++;
		}
	}
	ft_putstr("0x");
	ft_putstr(str);
}

void	ft_p_conv_help(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str)
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
		ft_p_conv_help_2(ptrfwplc, ptrflags, str);
}

int		ft_p_base(t_fwplc *ptrfwplc, t_flags *ptrflags,
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
	ft_p_conv_help(ptrfwplc, ptrflags, str);
	free(str);
	return (1);
}

int		ft_p_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	unsigned long	nbr;

	nbr = va_arg(arg, unsigned long);
	ft_p_base(ptrfwplc, ptrflags, nbr, 16);
	return (1);
}
