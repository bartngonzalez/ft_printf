/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_conv_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:02:40 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/02 22:57:14 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_di_plus_space(t_flags *ptrflags, int is_neg)
{
	if (is_neg == 0 && (ptrflags->plus || ptrflags->space))
	{
		if (ptrflags->plus)
			ft_putchar('+');
		else if (ptrflags->space)
			ft_putchar(' ');
		return (1);
	}
	return (0);
}

int		ft_di_left_precision(t_fwplc *ptrfwplc, char *str,
	int *strlen_mw_ps_neg)
{
	if (ptrfwplc->precision > strlen_mw_ps_neg[0])
	{
		while (strlen_mw_ps_neg[1] < ptrfwplc->precision - strlen_mw_ps_neg[0])
		{
			ft_putchar('0');
			strlen_mw_ps_neg[1]++;
		}
	}
	ft_putstr(str);
	if (ptrfwplc->minw > strlen_mw_ps_neg[1] +
		strlen_mw_ps_neg[0] + strlen_mw_ps_neg[2] + strlen_mw_ps_neg[3])
	{
		strlen_mw_ps_neg[1] += strlen_mw_ps_neg[0]
		+ strlen_mw_ps_neg[2] + strlen_mw_ps_neg[3];
		while (strlen_mw_ps_neg[1] < ptrfwplc->minw)
		{
			ft_putchar(' ');
			strlen_mw_ps_neg[1]++;
		}
		strlen_mw_ps_neg[1] -= strlen_mw_ps_neg[0]
		+ strlen_mw_ps_neg[2] + strlen_mw_ps_neg[3];
	}
	return (strlen_mw_ps_neg[0] + strlen_mw_ps_neg[1]);
}

int		ft_di_left_minw(t_fwplc *ptrfwplc, char *str, int *strlen_mw_ps_neg)
{
	ft_putstr(str);
	while (strlen_mw_ps_neg[1] < ptrfwplc->minw -
		strlen_mw_ps_neg[0] - strlen_mw_ps_neg[2] - strlen_mw_ps_neg[3])
	{
		ft_putchar(' ');
		strlen_mw_ps_neg[1]++;
	}
	return (strlen_mw_ps_neg[0] + strlen_mw_ps_neg[1]);
}

/*
** strlen_mw_ps_neg[4]: Break Down
** strlen_mw_ps_neg[0] = str_len: size of the string/num
** strlen_mw_ps_neg[1] = mwidth: number of times width space executed
** strlen_mw_ps_neg[2] = plus_space_sign: is there a space or plus sign
** strlen_mw_ps_neg[3] = is_neg: is the number a negative
*/

int		ft_di_left(t_fwplc *ptrfwplc, t_flags *ptrflags,
		char *str, int *base_isneg)
{
	int		strlen_mw_ps_neg[4];
	int		total;

	strlen_mw_ps_neg[0] = ft_strlen(str);
	strlen_mw_ps_neg[1] = 0;
	strlen_mw_ps_neg[2] =
	(base_isneg[1] == 0 && (ptrflags->plus || ptrflags->space)) ? 1 : 0;
	strlen_mw_ps_neg[3] = base_isneg[1];
	total = 0 + base_isneg[1];
	if (ptrfwplc->minw > strlen_mw_ps_neg[0] && ptrfwplc->precision == -1)
	{
		total += ft_di_plus_space(ptrflags, base_isneg[1]);
		total += ft_di_left_minw(ptrfwplc, str, strlen_mw_ps_neg);
	}
	else if (ptrfwplc->precision > -1)
	{
		total += ft_di_plus_space(ptrflags, base_isneg[1]);
		total += ft_di_left_precision(ptrfwplc, str, strlen_mw_ps_neg);
	}
	else
	{
		total += ft_di_plus_space(ptrflags, base_isneg[1]) + ft_strlen(str);
		ft_putstr(str);
	}
	return (total);
}
