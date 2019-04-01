/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convtype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 04:22:54 by bgonzale          #+#    #+#             */
/*   Updated: 2019/01/26 15:33:35 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convtype_2(char *str, t_fwplc *ptrfwplc)
{
	int pos;

	pos = ptrfwplc->pos;
	if (str[pos] == 'o')
		ptrfwplc->convtype = 'o';
	else if (str[pos] == 'u')
		ptrfwplc->convtype = 'u';
	else if (str[pos] == 'x')
		ptrfwplc->convtype = 'x';
	else if (str[pos] == 'X')
		ptrfwplc->convtype = 'X';
	else if (str[pos] == 'f')
		ptrfwplc->convtype = 'f';
}

void	ft_convtype(char *str, t_fwplc *ptrfwplc)
{
	int pos;

	pos = ptrfwplc->pos;
	if (str[pos] == 'c')
		ptrfwplc->convtype = 'c';
	else if (str[pos] == 's')
		ptrfwplc->convtype = 's';
	else if (str[pos] == 'p')
		ptrfwplc->convtype = 'p';
	else if (str[pos] == 'd')
		ptrfwplc->convtype = 'd';
	else if (str[pos] == 'i')
		ptrfwplc->convtype = 'i';
	else
		ft_convtype_2(str, ptrfwplc);
	pos += 1;
	ptrfwplc->pos = pos;
}
