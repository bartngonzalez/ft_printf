/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:59:06 by bgonzale          #+#    #+#             */
/*   Updated: 2019/02/04 18:12:46 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_c_flag(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	int		i;
	int		letter;
	int		str_len;
	int		size;
	char	*str;

	i = 0;
	letter = va_arg(arg, int);
	str_len = 0;
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
		while (i < size - 1)
			str[i++] = ' ';
		str[i] = letter;
	}
	ft_putstr(str);
	str_len += 1;
	return (str_len);
}
