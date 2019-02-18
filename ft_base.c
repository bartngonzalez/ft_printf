/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:44:49 by bgonzale          #+#    #+#             */
/*   Updated: 2019/02/02 16:10:25 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_base(unsigned long nbr, int base)
{
	unsigned long	i;
	unsigned long	len;
	char			*str;
	char			num;
	int				str_len;

	i = 0;
	len = ft_nbr_len(nbr, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	str[len] = '\0';
	while (nbr != 0)
	{
		len--;
		num = ("0123456789abcdef"[nbr % base]);
		str[len] = num;
		nbr /= base;
		i++;
	}
	ft_putstr(str);
	str_len = ft_strlen(str);
	free(str);
	return (str_len);
}
