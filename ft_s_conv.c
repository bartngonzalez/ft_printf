/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:02:34 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/07 17:16:38 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_s_conv_help_2(t_fwplc *ptrfwplc, int *i_j_strsize)
{
	char	*new_str;
	char	*temp;

	new_str = (char *)malloc(sizeof(char) *
	(i_j_strsize[2] + ptrfwplc->minw + 1));
	if (new_str == NULL)
		return (NULL);
	new_str[i_j_strsize[2] + ptrfwplc->minw] = '\0';
	temp = new_str;
	free(new_str);
	return (temp);
}

char	*ft_s_conv_help(t_fwplc *ptrfwplc, t_flags *ptrflags,
	int *i_j_strsize, char *str)
{
	char	*new_str;
	char	s_z;

	new_str = ft_s_conv_help_2(ptrfwplc, i_j_strsize);
	if (ptrflags->minus)
	{
		while (i_j_strsize[0] < i_j_strsize[2])
			new_str[i_j_strsize[0]++] = str[i_j_strsize[0]];
		i_j_strsize[0] = i_j_strsize[2];
		if (ptrfwplc->minw > i_j_strsize[2])
			while (i_j_strsize[0] < ptrfwplc->minw)
				new_str[i_j_strsize[0]++] = ' ';
	}
	else
	{
		if (ptrfwplc->minw > i_j_strsize[2])
		{
			s_z = (ptrflags->zero) ? '0' : ' ';
			while (i_j_strsize[0] < ptrfwplc->minw - i_j_strsize[2])
				new_str[i_j_strsize[0]++] = s_z;
		}
		while (i_j_strsize[1] < i_j_strsize[2])
			new_str[i_j_strsize[0] + i_j_strsize[1]++] = str[i_j_strsize[1]];
	}
	return (new_str);
}

int		ft_s_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	int		i_j_strsize[3];
	char	*str;
	char	*new_str;

	i_j_strsize[0] = 0;
	i_j_strsize[1] = 0;
	str = va_arg(arg, char *);
	i_j_strsize[2] = (ptrfwplc->precision > -1) ?
	ptrfwplc->precision : ft_strlen(str);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	new_str = ft_s_conv_help(ptrfwplc, ptrflags, i_j_strsize, str);
	ft_putstr(new_str);
	return (ft_strlen(new_str));
}
