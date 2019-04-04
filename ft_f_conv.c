/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 23:17:01 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/04 02:59:20 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define ABS(i)  ((i < 0) ? (-i) : (i))

long long powk(int x, unsigned int y)
{
	if (y == 0)
	{
		return (1);
	}
	else if (y % 2 == 0)
	{
		return (powk(x, y / 2) * powk(x, y / 2));
	}
	else
	{
		return (x * powk(x, y / 2) * powk(x, y / 2));
	}
}

char	*ft_f_base_2(long long nbr)
{
	int flag;
	int			len;
	long long	tmp;
	char		*str;
	char		num;

	flag = (nbr < 0) ? 1 : 0;
	len = 1 + flag;
	tmp = nbr;
	while (tmp /= 10)
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (0);
	str[len] = '\0';
	while (len-- > flag)
	{
		num = ("0123456789abcdef"[ABS(nbr % 10)]);
		str[len] = num;
		nbr /= 10;
	}
	if (flag)
	{
		str[0] = '-';
	}
	return (str);
}

void					ft_print_f(char *str, int len, int is_neg, int prec)
{
	int					r;
	int					i;

	i = len + is_neg - 2;
	r = (str[i + 1] - 48 >= 5) ? 1 : 0;
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
	write(1, str, len + is_neg - 1);
	len = len + is_neg - 1;
	printf("*** %d ***\n", len); // this is the total length of the number + is_neg
}

int ft_f_base(t_fwplc *ptrfwplc, t_flags *ptrflags,
	long double nbr, long long mult, long long muted, int prec)
{
	int len;
	long nbr_temp;
	unsigned long long after_point_ld;
	long xy;
	char *str;
	int i;
	int is_neg;

	i = 0;
	is_neg = (nbr < 0) ? 1 : 0;
	len = 1;
	nbr_temp = (long)nbr;
	while (nbr_temp /= 10)
	{
		len++;
	}
	if (prec)
	{
		len += prec + 1;
	}
	// len += (ptrfwplc->precision > -1) ? (ptrfwplc->precision + 1) : 0;
	// printf("*** [%d] ***\n", len);
	if (!(str = (char *)malloc(sizeof(char) * (len + is_neg + 1))))
	{
		return (0);
	}

	char *temp;
	str[len + is_neg] = '\0';
	temp = ft_f_base_2((long long)nbr);
	while (temp[i] != '\0')
	{
		str[i] = temp[i];
		i++;
	}
	if (ptrflags->hash == 1)
		str[i] = '.';
	else if (ptrfwplc->precision == 0 && ptrflags->hash == 0)
		ptrflags->hash = ptrflags->hash;
	else
		str[i] = '.';

	after_point_ld = (unsigned long long)ABS(nbr * powk(10, prec));
	// printf("*** [%d] ***\n", prec);
	mult = powk(10, (prec - 1));
	xy = 0;
	while (xy++ < prec)
	{
		muted = (after_point_ld / mult);
		muted = ABS(muted % 10);
		str[++i] = (char)muted + 48;
		mult /= 10;
	}
	// ft_putstr(str);
	ft_print_f(str, len, is_neg, prec);
	return (0);
}

int ft_f_conv(t_fwplc *ptrfwplc, t_flags *ptrflags, va_list arg)
{
	long double nbr;
	int prec;

	prec = (ptrfwplc->precision == -1) ? 7 : ptrfwplc->precision + 1;
	nbr = (long double)va_arg(arg, double);
	ft_f_base(ptrfwplc, ptrflags, nbr, 0, 0, prec);
	return (1);
}
