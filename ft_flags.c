/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:50:12 by bgonzale          #+#    #+#             */
/*   Updated: 2019/03/28 00:11:35 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flags(char *str, va_list arg)
{
	int str_len;

	str_len = 0;
	// if (*str == 'c')
	// 	str_len += ft_c_flag(arg);
	// if (*str == 's')
	// 	str_len += ft_s_flag(arg);
	// if (*str == 'd' || *str == 'i')
	// 	str_len += ft_d_i_flag(arg);
	// if (*str == 'o')
	// 	str_len += ft_o_flag(arg);
	// if (*str == 'u')
	// 	str_len += ft_u_flag(arg);
	if (*str == 'x')
		str_len += ft_x_flag(arg);
	// if (*str == 'p')
	// 	str_len += ft_p_flag(arg);
	if (*str == '%')
	{
		ft_putchar('%');
		str_len += 1;
	}
	return (str_len);
}
