/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xs_conv_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 03:46:50 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/03 21:02:54 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_xs_right_precision(t_fwplc *ptrfwplc, char *str,
	int *sl_is_mw_ps_mwm)
{
	if (ptrfwplc->minw > sl_is_mw_ps_mwm[4])
	{
		while (sl_is_mw_ps_mwm[2] <
			ptrfwplc->minw - sl_is_mw_ps_mwm[4] - sl_is_mw_ps_mwm[1])
		{
			ft_putchar(' ');
			sl_is_mw_ps_mwm[2]++;
		}
	}
	if (sl_is_mw_ps_mwm[1] == 2)
		(ptrfwplc->convtype == 'X') ? ft_putstr("0X") : ft_putstr("0x");
	if (ptrfwplc->precision > sl_is_mw_ps_mwm[0])
	{
		while (sl_is_mw_ps_mwm[3] < ptrfwplc->precision
			- sl_is_mw_ps_mwm[0])
		{
			ft_putchar('0');
			sl_is_mw_ps_mwm[3]++;
		}
	}
	ft_putstr(str);
	return (sl_is_mw_ps_mwm[0] + sl_is_mw_ps_mwm[2] + sl_is_mw_ps_mwm[3]);
}

int		ft_xs_right_minw(t_fwplc *ptrfwplc, t_flags *ptrflags,
	char *str, int *sl_is_mw_ps_mwm)
{
	if (ptrflags->zero == 0)
	{
		while (sl_is_mw_ps_mwm[2] <
			ptrfwplc->minw - sl_is_mw_ps_mwm[0] - sl_is_mw_ps_mwm[1])
		{
			ft_putchar(' ');
			sl_is_mw_ps_mwm[2]++;
		}
	}
	if (sl_is_mw_ps_mwm[1] == 2)
		(ptrfwplc->convtype == 'X') ? ft_putstr("0X") : ft_putstr("0x");
	if (ptrflags->zero == 1)
	{
		while (sl_is_mw_ps_mwm[2] <
			ptrfwplc->minw - sl_is_mw_ps_mwm[0] - sl_is_mw_ps_mwm[1])
		{
			ft_putchar('0');
			sl_is_mw_ps_mwm[2]++;
		}
	}
	ft_putstr(str);
	return (sl_is_mw_ps_mwm[0] + sl_is_mw_ps_mwm[2]);
}

/*
** sl_is_mw_ps_mwm[5]: Break Down
** sl_is_mw_ps_mwm[0] = str_len: str/num length
** sl_is_mw_ps_mwm[1] = is_hash: hash flag on set 2 else 0 (prefix 0x/0X)
** sl_is_mw_ps_mwm[2] = mwidth: number of times min-width executed
** sl_is_mw_ps_mwm[3] = prec_space: number of times precision executed
** sl_is_mw_ps_mwm[4] = mw_max: max number mwidth can execute
*/

int		ft_xs_right(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str)
{
	int		sl_is_mw_ps_mwm[5];
	int		total;

	sl_is_mw_ps_mwm[0] = ft_strlen(str);
	sl_is_mw_ps_mwm[1] =
	(ptrflags->hash && ft_strlen(str) > 1 && str[0] != '0') ? 2 : 0;
	sl_is_mw_ps_mwm[2] = 0;
	sl_is_mw_ps_mwm[3] = 0;
	sl_is_mw_ps_mwm[4] = (ptrfwplc->precision > sl_is_mw_ps_mwm[0])
	? ptrfwplc->precision : sl_is_mw_ps_mwm[0];
	total = 0 + sl_is_mw_ps_mwm[1];
	if (ptrfwplc->minw > sl_is_mw_ps_mwm[0] && ptrfwplc->precision == -1)
		total += ft_xs_right_minw(ptrfwplc, ptrflags, str, sl_is_mw_ps_mwm);
	else if (ptrfwplc->precision > -1)
		total += ft_xs_right_precision(ptrfwplc, str, sl_is_mw_ps_mwm);
	else
	{
		if (sl_is_mw_ps_mwm[1] == 2)
			(ptrfwplc->convtype == 'X') ? ft_putstr("0X") : ft_putstr("0x");
		ft_putstr(str);
		total += sl_is_mw_ps_mwm[0];
	}
	return (total);
}
