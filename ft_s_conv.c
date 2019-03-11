/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:02:34 by bgonzale          #+#    #+#             */
/*   Updated: 2019/03/09 18:49:08 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_s_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	int str_size;
	int i;
	int j;
	char *str;
	char *new_str;
	char s_z;

	i = 0;
	j = 0;
	str = va_arg(arg, char *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (0);
	}
	str_size = ft_strlen(str);
	if (ptrfwplc->precision > -1)
	{
		str_size = ptrfwplc->precision;
	}
	new_str = (char *)malloc(sizeof(char) * (str_size + ptrfwplc->minw + 1));
	new_str[str_size + ptrfwplc->minw] = '\0';
	if (ptrflags->minus)
	{
		while (i < str_size)
		{
			new_str[i] = str[i];
			i++;
		}
		i = str_size;
		if (ptrfwplc->minw > str_size)
		{
			while (i < ptrfwplc->minw)
			{
				new_str[i] = ' ';
				i++;
			}
		}
	}
	else
	{
		if (ptrfwplc->minw > str_size)
		{
			s_z = (ptrflags->zero) ? '0' : ' ';
			while (i < ptrfwplc->minw - str_size)
			{
				new_str[i] = s_z;
				i++;
			}
		}
		while (j < str_size)
		{
			new_str[i + j] = str[j];
			j++;
		}
	}
	ft_putstr(new_str);
	return (1);
}
