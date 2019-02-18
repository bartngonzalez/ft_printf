/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:33:05 by bgonzale          #+#    #+#             */
/*   Updated: 2019/02/04 15:10:28 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Starts a loop on format and checks for %
*/

int		ft_printf(const char *restrict format, ...)
{
	va_list arg;
	int		str_len;
	t_fwplc *ptrfwplc;
	t_flags *ptrflags;

	str_len = 0;
	ptrfwplc = (t_fwplc *)malloc(sizeof(t_fwplc));
	ptrflags = (t_flags *)malloc(sizeof(t_flags));
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			ft_setformat((char *)format, ptrfwplc, ptrflags, arg);
			format = format + ptrfwplc->pos + 1;
		}
		else
		{
			ft_putchar(*format);
			str_len += 1;
			format++;
		}
	}
	va_end(arg);
	return (str_len);
}
