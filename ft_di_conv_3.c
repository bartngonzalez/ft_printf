/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_conv_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bart <bart@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 20:24:58 by bart              #+#    #+#             */
/*   Updated: 2019/03/21 20:47:28 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_di_right_precision(t_fwplc *ptrfwplc, t_flags *ptrflags,
	char *str, int *slen_ps_mw_mwmax_prec)
{
	if (ptrfwplc->minw > slen_ps_mw_mwmax_prec[3])
	{
		while (slen_ps_mw_mwmax_prec[2] < ptrfwplc->minw
			- slen_ps_mw_mwmax_prec[3]
			- slen_ps_mw_mwmax_prec[5] - slen_ps_mw_mwmax_prec[1])
		{
			ft_putchar(' ');
			slen_ps_mw_mwmax_prec[2]++;
		}
	}
	ft_di_plus_space(ptrflags, slen_ps_mw_mwmax_prec[5]);
	if (slen_ps_mw_mwmax_prec[5])
		ft_putchar('-');
	if (ptrfwplc->precision > slen_ps_mw_mwmax_prec[0])
	{
		while (slen_ps_mw_mwmax_prec[4] < ptrfwplc->precision
			- slen_ps_mw_mwmax_prec[0])
		{
			ft_putchar('0');
			slen_ps_mw_mwmax_prec[4]++;
		}
	}
	ft_putstr(str);
}

void	ft_di_right_minw(t_fwplc *ptrfwplc, t_flags *ptrflags,
		char *str, int *slen_ps_mw_mwmax_prec)
{
	if (ptrflags->zero == 0)
	{
		while (slen_ps_mw_mwmax_prec[2] < ptrfwplc->minw -
			slen_ps_mw_mwmax_prec[0] -
			slen_ps_mw_mwmax_prec[1] - slen_ps_mw_mwmax_prec[5])
		{
			ft_putchar(' ');
			slen_ps_mw_mwmax_prec[2]++;
		}
	}
	ft_di_plus_space(ptrflags, slen_ps_mw_mwmax_prec[5]);
	if (slen_ps_mw_mwmax_prec[5])
		ft_putchar('-');
	if (ptrflags->zero == 1)
	{
		while (slen_ps_mw_mwmax_prec[2] < ptrfwplc->minw -
			slen_ps_mw_mwmax_prec[0] -
			slen_ps_mw_mwmax_prec[1] - slen_ps_mw_mwmax_prec[5])
		{
			ft_putchar('0');
			slen_ps_mw_mwmax_prec[2]++;
		}
	}
	ft_putstr(str);
}

/*
** slen_ps_mw_mwmax_prec[6]: Break Down
** slen_ps_mw_mwmax_prec[0] = str_len: size of the string/num
** slen_ps_mw_mwmax_prec[1] = ps_space: add space if +/- is applicable
** slen_ps_mw_mwmax_prec[2] = mwidth: number of mwidth spaces applied
** slen_ps_mw_mwmax_prec[3] = mwidth_max: max amount mwidth needs to be used
** slen_ps_mw_mwmax_prec[4] = prec_space: amount of times precision was used
** slen_ps_mw_mwmax_prec[5] = is_neg: if num is neg is_neg = 1 else is_neg = 0
*/

void	ft_di_right(t_fwplc *ptrfwplc, t_flags *ptrflags,
		char *str, int *base_isneg)
{
	int		slen_ps_mw_mwmax_prec[6];

	slen_ps_mw_mwmax_prec[0] = ft_strlen(str);
	slen_ps_mw_mwmax_prec[1] =
	(base_isneg[1] == 0 && (ptrflags->plus || ptrflags->space)) ? 1 : 0;
	slen_ps_mw_mwmax_prec[2] = 0;
	slen_ps_mw_mwmax_prec[3] = (ptrfwplc->precision > slen_ps_mw_mwmax_prec[0])
	? ptrfwplc->precision : slen_ps_mw_mwmax_prec[0];
	slen_ps_mw_mwmax_prec[4] = 0;
	slen_ps_mw_mwmax_prec[5] = base_isneg[1];
	if (ptrfwplc->minw > slen_ps_mw_mwmax_prec[0] && ptrfwplc->precision == -1)
		ft_di_right_minw(ptrfwplc, ptrflags, str, slen_ps_mw_mwmax_prec);
	else if (ptrfwplc->precision > -1)
		ft_di_right_precision(ptrfwplc, ptrflags, str, slen_ps_mw_mwmax_prec);
	else
	{
		ft_di_plus_space(ptrflags, slen_ps_mw_mwmax_prec[5]);
		if (slen_ps_mw_mwmax_prec[5])
			ft_putchar('-');
		ft_putstr(str);
	}
}
