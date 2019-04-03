/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_conv_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bart <bart@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 20:24:58 by bart              #+#    #+#             */
/*   Updated: 2019/04/03 00:00:53 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_di_right_precision(t_fwplc *ptrfwplc, t_flags *ptrflags,
		char *str, int *sl_ps_mw_mwm_prs_in)
{
	int		ps_space;

	if (ptrfwplc->minw > sl_ps_mw_mwm_prs_in[3])
	{
		while (sl_ps_mw_mwm_prs_in[2] < ptrfwplc->minw - sl_ps_mw_mwm_prs_in[3]
			- sl_ps_mw_mwm_prs_in[5] - sl_ps_mw_mwm_prs_in[1])
		{
			ft_putchar(' ');
			sl_ps_mw_mwm_prs_in[2]++;
		}
	}
	ps_space = ft_di_plus_space(ptrflags, sl_ps_mw_mwm_prs_in[5]);
	(sl_ps_mw_mwm_prs_in[5]) ? ft_putchar('-') : 0;
	if (ptrfwplc->precision > sl_ps_mw_mwm_prs_in[0])
	{
		while (sl_ps_mw_mwm_prs_in[4] < ptrfwplc->precision
			- sl_ps_mw_mwm_prs_in[0])
		{
			ft_putchar('0');
			sl_ps_mw_mwm_prs_in[4]++;
		}
	}
	ft_putstr(str);
	return (sl_ps_mw_mwm_prs_in[0] + ps_space +
		sl_ps_mw_mwm_prs_in[2] + sl_ps_mw_mwm_prs_in[4]);
}

int		ft_di_right_minw(t_fwplc *ptrfwplc, t_flags *ptrflags,
		char *str, int *sl_ps_mw_mwm_prs_in)
{
	int		ps_space;

	if (ptrflags->zero == 0)
	{
		while (sl_ps_mw_mwm_prs_in[2] < ptrfwplc->minw - sl_ps_mw_mwm_prs_in[0]
			- sl_ps_mw_mwm_prs_in[1] - sl_ps_mw_mwm_prs_in[5])
		{
			ft_putchar(' ');
			sl_ps_mw_mwm_prs_in[2]++;
		}
	}
	ps_space = ft_di_plus_space(ptrflags, sl_ps_mw_mwm_prs_in[5]);
	(sl_ps_mw_mwm_prs_in[5]) ? ft_putchar('-') : 0;
	if (ptrflags->zero == 1)
	{
		while (sl_ps_mw_mwm_prs_in[2] < ptrfwplc->minw - sl_ps_mw_mwm_prs_in[0]
			- sl_ps_mw_mwm_prs_in[1] - sl_ps_mw_mwm_prs_in[5])
		{
			ft_putchar('0');
			sl_ps_mw_mwm_prs_in[2]++;
		}
	}
	ft_putstr(str);
	return (sl_ps_mw_mwm_prs_in[0] + sl_ps_mw_mwm_prs_in[2] + ps_space);
}

/*
** sl_ps_mw_mwm_prs_in[6]: Break Down
** sl_ps_mw_mwm_prs_in[0] = str_len: size of the string/num
** sl_ps_mw_mwm_prs_in[1] = ps_space: add space if +/- is applicable
** sl_ps_mw_mwm_prs_in[2] = mwidth: number of mwidth spaces applied
** sl_ps_mw_mwm_prs_in[3] = mwidth_max: max amount mwidth needs to be used
** sl_ps_mw_mwm_prs_in[4] = prec_space: amount of times precision was used
** sl_ps_mw_mwm_prs_in[5] = is_neg: if num neg is_neg = 1 else is_neg = 0
*/

int		ft_di_right(t_fwplc *ptrfwplc, t_flags *ptrflags,
		char *str, int *base_isneg)
{
	int		sl_ps_mw_mwm_prs_in[6];
	int		total;

	sl_ps_mw_mwm_prs_in[0] = ft_strlen(str);
	sl_ps_mw_mwm_prs_in[1] =
	(base_isneg[1] == 0 && (ptrflags->plus || ptrflags->space)) ? 1 : 0;
	sl_ps_mw_mwm_prs_in[2] = 0;
	sl_ps_mw_mwm_prs_in[3] = (ptrfwplc->precision > sl_ps_mw_mwm_prs_in[0])
	? ptrfwplc->precision : sl_ps_mw_mwm_prs_in[0];
	sl_ps_mw_mwm_prs_in[4] = 0;
	sl_ps_mw_mwm_prs_in[5] = base_isneg[1];
	total = 0 + base_isneg[1];
	if (ptrfwplc->minw > sl_ps_mw_mwm_prs_in[0] && ptrfwplc->precision == -1)
		total += ft_di_right_minw(ptrfwplc, ptrflags, str, sl_ps_mw_mwm_prs_in);
	else if (ptrfwplc->precision > -1)
		total += ft_di_right_precision(ptrfwplc, ptrflags, str,
			sl_ps_mw_mwm_prs_in);
	else
	{
		total += ft_di_plus_space(ptrflags, sl_ps_mw_mwm_prs_in[5]) +
		ft_strlen(str);
		(sl_ps_mw_mwm_prs_in[5]) ? ft_putchar('-') : 0;
		ft_putstr(str);
	}
	return (total);
}
