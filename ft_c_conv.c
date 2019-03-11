/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:59:06 by bgonzale          #+#    #+#             */
/*   Updated: 2019/03/06 19:44:52 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_c_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	int		i;
	int		letter;
	int		size;
	char	*str;
	char	s_z;

	i = 0;
	letter = va_arg(arg, int);
	size = (1 > ptrfwplc->minw ? 1 : ptrfwplc->minw);
	str = (char *)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	if (ptrflags->minus)
	{
		str[i++] = letter;
		while (i < size)
			str[i++] = ' ';
	}
	else
	{
		s_z = (ptrflags->zero) ? '0' : ' ';
		while (i < size - 1)
			str[i++] = s_z;
		str[i] = letter;
	}
	ft_putstr(str);
	return (1);
}
