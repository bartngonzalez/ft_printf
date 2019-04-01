/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xs_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:18:38 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/01 04:39:11 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define ABS(i)  ((i < 0) ? (-i) : (i))

void	ft_xs_conv_help(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str)
{
	if (ptrflags->minus)
	{
		ft_xs_left(ptrfwplc, ptrflags, str);
	}
	else
	{
		ft_xs_right(ptrfwplc, ptrflags, str);
	}
}

int		ft_xs_base(t_fwplc *ptrfwplc, t_flags *ptrflags,
	unsigned long long nbr, int base)
{
	unsigned long long		size;
	char					*tab;
	unsigned long long		tmp;
	char					*str;

	size = 1;
	tab =
	(ptrfwplc->convtype == 'X' ? ("0123456789ABCDEF") : ("0123456789abcdef"));
	tmp = nbr;
	while (tmp /= base)
		size++;
	str = (char *)malloc(sizeof(char) * (size + tmp + 1));
	if (str == NULL)
		return (0);
	str[size] = '\0';
	while (size-- > tmp)
	{
		str[size] = tab[ABS(nbr % base)];
		nbr /= base;
	}
	ft_xs_conv_help(ptrfwplc, ptrflags, str);
	free(str);
	return (1);
}

int		ft_xs_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	unsigned long long nbr;

	nbr = va_arg(arg, unsigned int);
	ft_xs_base(ptrfwplc, ptrflags, nbr, 16);
	return (1);
}
