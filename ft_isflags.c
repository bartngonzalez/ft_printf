/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:11:35 by bgonzale          #+#    #+#             */
/*   Updated: 2019/02/02 00:20:03 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Turn flag in structure to 1 if any of the flags exist
*/

void	ft_flagson(t_fwplc *ptrfwplc, t_flags *ptrflags)
{
	if (ptrflags->hash == 1 || ptrflags->minus == 1 ||
			ptrflags->plus == 1 || ptrflags->space == 1 ||
			ptrflags->zero == 1)
		ptrfwplc->flags = 1;
}

/*
** Initialize flags #, -, +, space, 0
*/

void	ft_setflags(t_flags *ptrflags)
{
	ptrflags->hash = 0;
	ptrflags->minus = 0;
	ptrflags->plus = 0;
	ptrflags->space = 0;
	ptrflags->zero = 0;
}

/*
** Check for flags #, -, +, space, 0
*/

void	ft_isflags(char *str, t_fwplc *ptrfwplc, t_flags *ptrflags)
{
	int pos;

	pos = ptrfwplc->pos;
	ptrfwplc->flags = 0;
	ft_setflags(ptrflags);
	while (str[pos] && (str[pos] == '#' || str[pos] == '-' ||
				str[pos] == '+' || str[pos] == ' ' || str[pos] == '0'))
	{
		if (str[pos] == '#')
			ptrflags->hash = 1;
		if (str[pos] == '-')
			ptrflags->minus = 1;
		if (str[pos] == '+')
			ptrflags->plus = 1;
		if (str[pos] == ' ')
			ptrflags->space = 1;
		if (str[pos] == '0')
			ptrflags->zero = 1;
		pos++;
	}
	ft_flagson(ptrfwplc, ptrflags);
	ptrfwplc->pos = pos;
}
