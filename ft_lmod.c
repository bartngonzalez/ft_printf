/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lmod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:06:49 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/07 19:32:51 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			ft_int_mod(t_fwplc *ptrfwplc, va_list arg)
{
	long long	nbr;

	nbr = 0;
	if (ptrfwplc->length == 1)
		nbr = (signed char)va_arg(arg, int);
	else if (ptrfwplc->length == 2)
		nbr = (short)va_arg(arg, int);
	else if (ptrfwplc->length == 3)
		nbr = (long long)va_arg(arg, long long);
	else if (ptrfwplc->length == 4)
		nbr = (long)va_arg(arg, long);
	else
		nbr = va_arg(arg, int);
	return (nbr);
}

unsigned long long	ft_uint_mod(t_fwplc *ptrfwplc, va_list arg)
{
	unsigned long long	nbr;

	nbr = 0;
	if (ptrfwplc->length == 1)
		nbr = (unsigned char)va_arg(arg, unsigned int);
	else if (ptrfwplc->length == 2)
		nbr = (unsigned short)va_arg(arg, unsigned int);
	else if (ptrfwplc->length == 3)
		nbr = (unsigned long long)va_arg(arg, unsigned long long);
	else if (ptrfwplc->length == 4)
		nbr = (unsigned long)va_arg(arg, unsigned long);
	else
		nbr = va_arg(arg, unsigned int);
	return (nbr);
}

long double			ft_f_mod(t_fwplc *ptrfwplc, va_list arg)
{
	long double	nbr;

	nbr = 0;
	if (ptrfwplc->length == 4)
		nbr = (double)va_arg(arg, double);
	else if (ptrfwplc->length == 5)
		nbr = (long double)va_arg(arg, long double);
	else
		nbr = (long double)va_arg(arg, double);
	return (nbr);
}
