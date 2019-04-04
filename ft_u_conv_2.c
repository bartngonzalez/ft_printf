/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_conv_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:16:54 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/03 20:36:38 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_u_left_precision(t_fwplc *ptrfwplc, char *str, int *sl_ps_mw)
{
	while (sl_ps_mw[1] < ptrfwplc->precision - sl_ps_mw[0])
	{
		ft_putchar('0');
		sl_ps_mw[1]++;
	}
	ft_putstr(str);
	if (ptrfwplc->minw > sl_ps_mw[0] + sl_ps_mw[1])
	{
		sl_ps_mw[2] = sl_ps_mw[0] + sl_ps_mw[1];
		while (sl_ps_mw[2] < ptrfwplc->minw)
		{
			ft_putchar(' ');
			sl_ps_mw[2]++;
		}
		sl_ps_mw[2] -= sl_ps_mw[0] + sl_ps_mw[1];
	}
	return (sl_ps_mw[0] + sl_ps_mw[1] + sl_ps_mw[2]);
}

int		ft_u_left_minw(t_fwplc *ptrfwplc, char *str, int *sl_ps_mw)
{
	ft_putstr(str);
	while (sl_ps_mw[2] < ptrfwplc->minw - sl_ps_mw[0])
	{
		ft_putchar(' ');
		sl_ps_mw[2]++;
	}
	return (sl_ps_mw[0] + sl_ps_mw[2]);
}

/*
** sl_ps_mw[3]: Break Down
** sl_ps_mw[0] = str_len: str/num length
** sl_ps_mw[1] = prec_space: number of times prec was used
** sl_ps_mw[2] = mwidth: number of times mwidth was used
*/

int		ft_u_left(t_fwplc *ptrfwplc, char *str)
{
	int		sl_ps_mw[3];
	int		total;

	sl_ps_mw[0] = ft_strlen(str);
	sl_ps_mw[1] = 0;
	sl_ps_mw[2] = 0;
	total = 0;
	if (ptrfwplc->minw > sl_ps_mw[0] && ptrfwplc->precision == -1)
	{
		total += ft_u_left_minw(ptrfwplc, str, sl_ps_mw);
	}
	else if (ptrfwplc->precision > -1)
	{
		total += ft_u_left_precision(ptrfwplc, str, sl_ps_mw);
	}
	else
	{
		ft_putstr(str);
		total += sl_ps_mw[0];
	}
	return (total);
}
