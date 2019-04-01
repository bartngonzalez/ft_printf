/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 02:25:25 by bgonzale          #+#    #+#             */
/*   Updated: 2019/02/03 21:55:41 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_isprec(char *str, t_fwplc *ptrfwplc)
{
	int		i;
	int		pos;
	char	numbrs_str[1000];

	i = 0;
	ptrfwplc->precision = -1;
	pos = ptrfwplc->pos;
	if (str[pos] == '.')
	{
		pos++;
		while (str[pos] >= '0' && str[pos] <= '9')
		{
			numbrs_str[i] = str[pos];
			pos++;
			i++;
		}
		numbrs_str[i] = '\0';
		ptrfwplc->precision = ft_atoi(numbrs_str);
	}
	ptrfwplc->pos = pos;
}
