/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_conv_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:22:56 by bgonzale          #+#    #+#             */
/*   Updated: 2019/03/26 20:18:23 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_o_left_precision(t_fwplc *ptrfwplc, char *str, int *sl_ih_mw_ps)
{
	if (sl_ih_mw_ps[1])
		ft_putchar('0');
	while (sl_ih_mw_ps[3] < ptrfwplc->precision
		- sl_ih_mw_ps[0] - sl_ih_mw_ps[1])
	{
		ft_putchar('0');
		sl_ih_mw_ps[3]++;
	}
	ft_putstr(str);
	if (ptrfwplc->minw > sl_ih_mw_ps[0] + sl_ih_mw_ps[1] + sl_ih_mw_ps[3])
	{
		sl_ih_mw_ps[2] = sl_ih_mw_ps[0] + sl_ih_mw_ps[1] + sl_ih_mw_ps[3];
		while (sl_ih_mw_ps[2] < ptrfwplc->minw)
		{
			ft_putchar(' ');
			sl_ih_mw_ps[2]++;
		}
	}
}

void	ft_o_left_minw(t_fwplc *ptrfwplc, char *str, int *sl_ih_mw_ps)
{
	if (sl_ih_mw_ps[1])
		ft_putchar('0');
	ft_putstr(str);
	while (sl_ih_mw_ps[2] < ptrfwplc->minw - sl_ih_mw_ps[0] - sl_ih_mw_ps[1])
	{
		ft_putchar(' ');
		sl_ih_mw_ps[2]++;
	}
}

/*
** sl_ih_mw_ps[4]: Break Down
** sl_ih_mw_ps[0] = str_len: string/num length
** sl_ih_mw_ps[1] = is_hash: if hash flag then force precision to add 0
** sl_ih_mw_ps[2] = mwidth: number of times min-width executed
** sl_ih_mw_ps[3] = prec_space: number of times precision executed
*/

void	ft_o_left(t_fwplc *ptrfwplc, t_flags *ptrflags, char *str)
{
	int		sl_ih_mw_ps[4];

	sl_ih_mw_ps[0] = ft_strlen(str);
	sl_ih_mw_ps[1] = ptrflags->hash;
	sl_ih_mw_ps[2] = 0;
	sl_ih_mw_ps[3] = 0;
	if (ptrfwplc->minw > sl_ih_mw_ps[0] && ptrfwplc->precision == -1)
	{
		ft_o_left_minw(ptrfwplc, str, sl_ih_mw_ps);
	}
	else if (ptrfwplc->precision > -1)
	{
		ft_o_left_precision(ptrfwplc, str, sl_ih_mw_ps);
	}
	else
	{
		if (sl_ih_mw_ps[1])
			ft_putchar('0');
		ft_putstr(str);
	}
}
