/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:02:34 by bgonzale          #+#    #+#             */
/*   Updated: 2019/02/04 18:14:57 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_s_flag(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	int str_size;
	int i;
	int j;
	char *str;
	char *new_str;

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
		while (i < str_size || str[i] != '\0')
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
			while (i < ptrfwplc->minw)
			{
				new_str[i] = ' ';
				i++;
			}
		}
		while (j < str_size || str[j] != '\0')
		{
			new_str[i + j] = str[j];
			j++;
		}
	}
	// printf("[str *** %s]\n", str);
	// printf("[new_str *** {%s}]\n", new_str);
	// printf("[str_size *** %d]\n", str_size);
	// printf("[minw *** %d]\n", ptrfwplc->minw);
	// printf("[prec *** %d]\n", ptrfwplc->precision);
	ft_putstr(new_str);
	return (1);
}
