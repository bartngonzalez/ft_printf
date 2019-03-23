/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:07:11 by bgonzale          #+#    #+#             */
/*   Updated: 2019/03/22 16:30:07 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
