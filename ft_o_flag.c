/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:11:21 by bgonzale          #+#    #+#             */
/*   Updated: 2019/01/13 20:46:00 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_o_flag(va_list arg)
{
	unsigned int	i;
	int				str_len;

	str_len = 0;
	i = va_arg(arg, unsigned int);
	str_len += ft_base(i, 8);
	return (str_len);
}
