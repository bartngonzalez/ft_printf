/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 03:01:36 by bgonzale          #+#    #+#             */
/*   Updated: 2019/01/26 15:19:42 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Checks for length modifiers hh, h, ll, l, L
** hh = 1, h = 2, ll = 3. l = 4, L = 5
*/

void	ft_islen(char *str, t_fwplc *ptrfwplc)
{
	int	pos;

	pos = ptrfwplc->pos;
	ptrfwplc->length = 0;
	if (str[pos] == 'h' && str[pos + 1] == 'h')
		ptrfwplc->length = 1;
	else if (str[pos] == 'h')
		ptrfwplc->length = 2;
	else if (str[pos] == 'l' && str[pos + 1] == 'l')
		ptrfwplc->length = 3;
	else if (str[pos] == 'l')
		ptrfwplc->length = 4;
	else if (str[pos] == 'L')
		ptrfwplc->length = 5;
	if (ptrfwplc->length == 1 || ptrfwplc->length == 3)
		pos += 2;
	else if (ptrfwplc->length == 2 || ptrfwplc->length == 4
			|| ptrfwplc->length == 5)
		pos += 1;
	ptrfwplc->pos = pos;
}
