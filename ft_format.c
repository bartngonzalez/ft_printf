/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:36:25 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/07 17:34:55 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_format(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	if (ptrfwplc->convtype == 'c')
		return (ft_c_conv(ptrfwplc, ptrflags, arg));
	else if (ptrfwplc->convtype == 's')
		return (ft_s_conv(ptrfwplc, ptrflags, arg));
	else if (ptrfwplc->convtype == 'p')
		return (ft_p_conv(ptrfwplc, ptrflags, arg));
	else if (ptrfwplc->convtype == 'd' || ptrfwplc->convtype == 'i')
		return (ft_di_conv(ptrfwplc, ptrflags, arg));
	else if (ptrfwplc->convtype == 'o')
		return (ft_o_conv(ptrfwplc, ptrflags, arg));
	else if (ptrfwplc->convtype == 'u')
		return (ft_u_conv(ptrfwplc, ptrflags, arg));
	else if (ptrfwplc->convtype == 'x' || ptrfwplc->convtype == 'X')
		return (ft_xs_conv(ptrfwplc, ptrflags, arg));
	else if (ptrfwplc->convtype == 'f')
		return (ft_f_conv(ptrfwplc, ptrflags, arg));
	return (0);
}
