/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:33:05 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/07 18:20:50 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_help(char *format)
{
	ft_putchar(*format);
	return (1);
}

/*
** Starts a loop on format and checks for %
*/

int		ft_printf(const char *restrict format, ...)
{
	va_list	arg;
	int		str_len;
	t_fwplc	*ptrfwplc;
	t_flags	*ptrflags;

	str_len = 0;
	ptrfwplc = (t_fwplc *)malloc(sizeof(t_fwplc));
	ptrflags = (t_flags *)malloc(sizeof(t_flags));
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			str_len += ft_setformat((char *)format, ptrfwplc, ptrflags, arg);
			format = format + ptrfwplc->pos + 1;
		}
		else
		{
			str_len += ft_printf_help((char *)format++);
		}
	}
	va_end(arg);
	free(ptrfwplc);
	free(ptrflags);
	return (str_len);
}
