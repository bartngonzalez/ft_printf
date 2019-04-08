/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xs_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:18:38 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/07 19:37:20 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define ABS(i)  ((i < 0) ? (-i) : (i))

int		ft_xs_conv_help(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str)
{
	if (ptrflags->minus)
	{
		return (ft_xs_left(ptrfwplc, ptrflags, str));
	}
	else
	{
		return (ft_xs_right(ptrfwplc, ptrflags, str));
	}
	return (0);
}

int		ft_xs_base(t_fwplc *ptrfwplc, t_flags *ptrflags,
	unsigned long long nbr, int base)
{
	unsigned long long		size;
	char					*tab;
	unsigned long long		tmp;
	char					*str;
	int						str_len;

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
	str_len = 0;
	while (size-- > tmp)
	{
		str[size] = tab[ABS(nbr % base)];
		nbr /= base;
	}
	str_len = ft_xs_conv_help(ptrfwplc, ptrflags, str);
	free(str);
	return (str_len);
}

int		ft_xs_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	unsigned long long nbr;

	nbr = ft_uint_mod(ptrfwplc, arg);
	return (ft_xs_base(ptrfwplc, ptrflags, nbr, 16));
}
