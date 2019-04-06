/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_conv_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:55:59 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/05 21:29:35 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_f_write_2(char *str, int i, int r, int prec)
{
	if (prec)
	{
		while (i >= 0 && r)
		{
			if (str[i] == '9')
				str[i] = '0';
			else if (str[i] != '.')
			{
				str[i] += 1;
				r = 0;
			}
			i--;
		}
		if (r)
			write(1, "1", 1);
	}
}

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (char)c;
	i = 0;
	while (s[i] != ch)
	{
		if (!s[i])
			return (NULL);
		i++;
	}
	return ((char *)(s + i));
}

int			ft_f_write(t_fwplc *ptrfwplc, t_flags *ptrflags,
	char *str, int *varz)
{
	int		r;
	int		i;
	int		str_len;

	i = varz[4] + varz[1] - 2;
	r = (str[i + 1] - 48 >= 5) ? 1 : 0;
	str_len = 0;
	ft_f_write_2(str, i, r, varz[2]);
	if (ptrflags->minus)
		str_len = ft_f_left(ptrfwplc, ptrflags, str, varz);
	else
		str_len = ft_f_right(ptrfwplc, ptrflags, str, varz);
	return (str_len);
}

long long	powk(int x, unsigned int y)
{
	if (y == 0)
		return (1);
	else if (y % 2 == 0)
		return (powk(x, y / 2) * powk(x, y / 2));
	else
		return (x * powk(x, y / 2) * powk(x, y / 2));
}
