/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_conv_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 18:07:40 by bgonzale          #+#    #+#             */
/*   Updated: 2019/03/31 18:20:51 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_u_right_precision(t_fwplc *ptrfwplc, char *str, int *sl_mw_ps_mwm)
{
	if (ptrfwplc->minw > sl_mw_ps_mwm[3])
	{
		while (sl_mw_ps_mwm[1] < ptrfwplc->minw - sl_mw_ps_mwm[3])
		{
			ft_putchar(' ');
			sl_mw_ps_mwm[1]++;
		}
	}
	if (ptrfwplc->precision > sl_mw_ps_mwm[0])
	{
		while (sl_mw_ps_mwm[2] < ptrfwplc->precision - sl_mw_ps_mwm[0])
		{
			ft_putchar('0');
			sl_mw_ps_mwm[2]++;
		}
	}
	ft_putstr(str);
}

void	ft_u_right_minw(t_fwplc *ptrfwplc, t_flags *ptrflags,
	char *str, int *sl_mw_ps_mwm)
{
	while (sl_mw_ps_mwm[1] < ptrfwplc->minw - sl_mw_ps_mwm[0])
	{
		(ptrflags->zero) ? ft_putchar('0') : ft_putchar(' ');
		sl_mw_ps_mwm[1]++;
	}
	ft_putstr(str);
}

/*
** sl_mw_ps_mwm[4]: Break Down
** sl_mw_ps_mwm[0] = str_len: str/num length
** sl_mw_ps_mwm[1] = mwidth: number of times width executed
** sl_mw_ps_mwm[2] = prec_space: number of times precision executed
** sl_mw_ps_mwm[3] = mw_max: max number width can execute
*/

void	ft_u_right(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str)
{
	int		sl_mw_ps_mwm[4];

	sl_mw_ps_mwm[0] = ft_strlen(str);
	sl_mw_ps_mwm[1] = 0;
	sl_mw_ps_mwm[2] = 0;
	sl_mw_ps_mwm[3] =
	(ptrfwplc->precision > sl_mw_ps_mwm[0])
	? ptrfwplc->precision : sl_mw_ps_mwm[0];
	if (ptrfwplc->minw > sl_mw_ps_mwm[0] && ptrfwplc->precision == -1)
	{
		ft_u_right_minw(ptrfwplc, ptrflags, str, sl_mw_ps_mwm);
	}
	else if (ptrfwplc->precision > -1)
	{
		ft_u_right_precision(ptrfwplc, str, sl_mw_ps_mwm);
	}
	else
	{
		ft_putstr(str);
	}
}
