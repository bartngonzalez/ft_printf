/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:43:35 by bgonzale          #+#    #+#             */
/*   Updated: 2019/03/05 17:15:34 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Checks every char after % to find flags, min-width, precision,
** length, and conversion type. Calls format function to begin printing.
*/

void	ft_setformat(char *format, t_fwplc *ptrfwplc, t_flags *ptrflags,
		va_list arg)
{
	format++;
	ptrfwplc->pos = 0;
	ft_isflags(format, ptrfwplc, ptrflags);
	ft_isminw(format, ptrfwplc);
	ft_isprec(format, ptrfwplc);
	ft_islen(format, ptrfwplc);
	ft_convtype(format, ptrfwplc);
	ft_format(ptrfwplc, ptrflags, arg);
}
