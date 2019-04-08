/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:07:11 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/08 00:42:12 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define ABS(i)  ((i < 0) ? (-i) : (i))

int		ft_di_conv_help(t_fwplc *ptrfwplc, t_flags *ptrflags,
	char *str, int *base_isneg)
{
	if (ptrflags->minus)
	{
		if (base_isneg[1] == 1)
			ft_putchar('-');
		return (ft_di_left(ptrfwplc, ptrflags, str, base_isneg));
	}
	else
	{
		return (ft_di_right(ptrfwplc, ptrflags, str, base_isneg));
	}
	return (0);
}

int		ft_di_base(t_fwplc *ptrfwplc, t_flags *ptrflags,
	long long nbr, int *base_isneg)
{
	int			size;
	char		*tab;
	long long	tmp;
	char		*str;
	int			str_len;

	size = 1;
	tab =
	(ptrfwplc->convtype == 'X' ? ("0123456789ABCDEF") : ("0123456789abcdef"));
	tmp = nbr;
	str_len = 0;
	while (tmp /= base_isneg[0])
		size++;
	str = (char *)malloc(sizeof(char) * (size + tmp + 1));
	if (str == NULL)
		return (0);
	str[size] = '\0';
	while (size-- > tmp)
	{
		str[size] = tab[ABS(nbr % base_isneg[0])];
		nbr /= base_isneg[0];
	}
	str_len = ft_di_conv_help(ptrfwplc, ptrflags, str, base_isneg);
	free(str);
	return (str_len);
}

int		ft_di_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	long long	nbr;
	int			base_isneg[2];

	nbr = ft_int_mod(ptrfwplc, arg);
	base_isneg[0] = 10;
	base_isneg[1] = (nbr < 0) ? 1 : 0;
	if (nbr < 0)
		nbr = nbr * -1;
	return (ft_di_base(ptrfwplc, ptrflags, nbr, base_isneg));
}
