/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 23:17:01 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/01 23:36:50 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_f_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	long double nbr;

	nbr = (long double)va_arg(arg, double);
	ptrfwplc = NULL;
	ptrflags = NULL;
	ft_putstr("f Conversion");
	printf("*** %f\n", (double)nbr);
	return (1);
}
