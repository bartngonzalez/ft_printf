/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:36:25 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/01 04:12:29 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	if (ptrfwplc->convtype == 'c')
	{
		ft_c_conv(ptrfwplc, ptrflags, arg);
	}
	else if (ptrfwplc->convtype == 's')
	{
		ft_s_conv(ptrfwplc, ptrflags, arg);
	}
	else if (ptrfwplc->convtype == 'p')
	{
		ft_p_conv(ptrfwplc, ptrflags, arg);
	}
	else if (ptrfwplc->convtype == 'd' || ptrfwplc->convtype == 'i')
	{
		ft_di_conv(ptrfwplc, ptrflags, arg);
	}
	else if (ptrfwplc->convtype == 'o')
	{
		ft_o_conv(ptrfwplc, ptrflags, arg);
	}
	else if (ptrfwplc->convtype == 'u')
	{
		ft_u_conv(ptrfwplc, ptrflags, arg);
	}
	else if (ptrfwplc->convtype == 'x' || ptrfwplc->convtype == 'X')
	{
		ft_xs_conv(ptrfwplc, ptrflags, arg);
	}
}
