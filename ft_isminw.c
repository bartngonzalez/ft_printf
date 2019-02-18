/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isminw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 00:47:11 by bgonzale          #+#    #+#             */
/*   Updated: 2019/02/03 22:20:28 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_isminw(char *str, t_fwplc *ptrfwplc)
{
	int		pos;
	int		i;
	char	numbrs_str[1000];

	i = 0;
	pos = ptrfwplc->pos;
	ptrfwplc->minw = 0;
	if (str[pos] >= '0' && str[pos] <= '9')
	{
		while (str[pos] >= '0' && str[pos] <= '9')
		{
			numbrs_str[i] = str[pos];
			i++;
			pos++;
		}
	}
	numbrs_str[i] = '\0';
	ptrfwplc->minw = ft_atoi(numbrs_str);
	ptrfwplc->pos = pos;
}
