/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:59:06 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/02 20:59:00 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_c_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	int		i_letter_size[3];
	char	*str;
	char	s_z;

	i_letter_size[0] = 0;
	i_letter_size[1] = va_arg(arg, int);
	i_letter_size[2] = (1 > ptrfwplc->minw ? 1 : ptrfwplc->minw);
	str = (char *)malloc(sizeof(char) * (i_letter_size[2] + 1));
	str[i_letter_size[2]] = '\0';
	if (ptrflags->minus)
	{
		str[i_letter_size[0]++] = i_letter_size[1];
		while (i_letter_size[0] < i_letter_size[2])
			str[i_letter_size[0]++] = ' ';
	}
	else
	{
		s_z = (ptrflags->zero) ? '0' : ' ';
		while (i_letter_size[0] < i_letter_size[2] - 1)
			str[i_letter_size[0]++] = s_z;
		str[i_letter_size[0]] = i_letter_size[1];
	}
	ft_putstr(str);
	return (ft_strlen(str));
}
