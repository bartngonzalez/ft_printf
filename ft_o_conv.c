/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:11:21 by bgonzale          #+#    #+#             */
/*   Updated: 2019/03/27 14:27:06 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_o_conv_help(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str)
{
	if (ptrflags->minus)
	{
		ft_o_left(ptrfwplc, ptrflags, str);
	}
	else
	{
		ft_o_right(ptrfwplc, ptrflags, str);
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
