/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xs_conv_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 03:46:33 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/01 04:34:15 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_xs_left_precision(t_fwplc *ptrfwplc, char *str, int *sl_ih_mw_ps)
{
	if (sl_ih_mw_ps[1] == 2)
		(ptrfwplc->convtype == 'X') ? ft_putstr("0X") : ft_putstr("0x");
	while (sl_ih_mw_ps[3] < ptrfwplc->precision - sl_ih_mw_ps[0])
	{
		ft_putchar('0');
		sl_ih_mw_ps[3]++;
	}
	ft_putstr(str);
	if (ptrfwplc->minw > sl_ih_mw_ps[0] + sl_ih_mw_ps[3] + sl_ih_mw_ps[1])
	{
		sl_ih_mw_ps[2] = sl_ih_mw_ps[0] + sl_ih_mw_ps[3] + sl_ih_mw_ps[1];
		while (sl_ih_mw_ps[2] < ptrfwplc->minw)
		{
			ft_putchar(' ');
			sl_ih_mw_ps[2]++;
		}
	}
}

void	ft_xs_left_minw(t_fwplc *ptrfwplc, char *str, int *sl_ih_mw_ps)
{
	if (sl_ih_mw_ps[1] == 2)
		(ptrfwplc->convtype == 'X') ? ft_putstr("0X") : ft_putstr("0x");
	ft_putstr(str);
	while (sl_ih_mw_ps[2] < ptrfwplc->minw - sl_ih_mw_ps[0] - sl_ih_mw_ps[1])
	{
		ft_putchar(' ');
		sl_ih_mw_ps[2]++;
	}
}

/*
** sl_ih_mw_ps[4]: Break Down
** sl_ih_mw_ps[0] = str_len: str/num length
** sl_ih_mw_ps[1] = is_hash: is hash flag on for 0x/0X adds (2) if on
** sl_ih_mw_ps[2] = mwidth: number of times min-width executed
** sl_ih_mw_ps[3] = prec_space: number of time precision executed
*/

void	ft_xs_left(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str)
{
	int		sl_ih_mw_ps[4];

	sl_ih_mw_ps[0] = ft_strlen(str);
	sl_ih_mw_ps[1] =
	(ptrflags->hash && ft_strlen(str) > 1 && str[0] != '0') ? 2 : 0;
	sl_ih_mw_ps[2] = 0;
	sl_ih_mw_ps[3] = 0;
	if (ptrfwplc->minw > sl_ih_mw_ps[0] && ptrfwplc->precision == -1)
	{
		ft_xs_left_minw(ptrfwplc, str, sl_ih_mw_ps);
	}
	else if (ptrfwplc->precision > -1)
	{
		ft_xs_left_precision(ptrfwplc, str, sl_ih_mw_ps);
	}
	else
	{
		if (sl_ih_mw_ps[1] == 2)
			(ptrfwplc->convtype == 'X') ? ft_putstr("0X") : ft_putstr("0x");
		ft_putstr(str);
	}
}
