/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:11:21 by bgonzale          #+#    #+#             */
/*   Updated: 2019/03/21 23:33:42 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_o_conv(va_list arg)
{
	unsigned int	i;
	int				str_len;

	str_len = 0;
	i = va_arg(arg, unsigned int);
	str_len += ft_base(i, 8);
	return (str_len);
}
