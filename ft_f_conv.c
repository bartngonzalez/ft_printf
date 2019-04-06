/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 23:17:01 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/05 21:29:25 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define ABS(i)  ((i < 0) ? (-i) : (i))

/*
** temp helper. this is the base for the whole number to store into temp.
** also adds a '-' only if the number is < 0 (negative).
*/

char		*ft_f_temp_base(long long nbr)
{
	int			flag;
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
		str[0] = '-';
	return (str);
}

/*
** Creates temp string and calls ft_f_base_2 function to get the whole
** number and store it into temp. then it loops throuht temp and saves
** into str adds a '.' depending on flags that are on.
*/

int			ft_f_temp(t_flags *ptrflags, char *str,
		long double nbr, int *varz)
{
	int		i;
	int		is_neg;
	int		len;
	int		prec_2;
	char	*temp;

	i = 0;
	is_neg = varz[1];
	len = varz[4];
	prec_2 = varz[3];
	str[len + is_neg] = '\0';
	temp = ft_f_temp_base((long long)nbr);
	while (temp[i] != '\0')
	{
		str[i] = temp[i];
		i++;
	}
	if (ptrflags->hash == 1)
		str[i] = '.';
	else if (prec_2 == 0 && ptrflags->hash == 0)
		ptrflags->hash = ptrflags->hash;
	else
		str[i] = '.';
	return (i);
}

/*
** Gets the length/size needed to malloc the string
*/

int			ft_f_len(long double nbr, int prec)
{
	int		len;
	long	nbr_temp;

	len = 1;
	nbr_temp = (long)nbr;
	while (nbr_temp /= 10)
		len++;
	if (prec)
		len += prec + 1;
	return (len);
}

/*
** varz[5]: Break Down
** varz[0] = i: position in str
** varz[1] = is_neg: is it a negative numer 1 or 0
** varz[2] = prec: precision modified
** varz[3] = prec_2: precision origional
** varz[4] = length: size needed to malloc the str
*/

int			ft_f_base(t_fwplc *ptrfwplc, t_flags *ptrflags,
		long double nbr, long long *mut_mul)
{
	int					varz[5];
	unsigned long long	after_point_ld;
	long				xy;
	static char			*str;

	varz[0] = 0;
	varz[1] = (nbr < 0) ? 1 : 0;
	varz[2] = (ptrfwplc->precision == -1) ? 7 : ptrfwplc->precision + 1;
	varz[3] = ptrfwplc->precision;
	varz[4] = ft_f_len(nbr, varz[2]);
	if (!(str = (char *)malloc(sizeof(char) * (varz[4] + varz[1] + 1))))
		return (0);
	varz[0] = ft_f_temp(ptrflags, str, nbr, varz);
	after_point_ld = (unsigned long long)ABS(nbr * powk(10, varz[2]));
	mut_mul[1] = powk(10, (varz[2] - 1));
	xy = 0;
	while (xy++ < varz[2])
	{
		mut_mul[0] = (after_point_ld / mut_mul[1]);
		mut_mul[0] = ABS(mut_mul[0] % 10);
		str[++varz[0]] = (char)mut_mul[0] + 48;
		mut_mul[1] /= 10;
	}
	return (ft_f_write(ptrfwplc, ptrflags, str, varz));
}

/*
** mut_mul[2]: Break Down
** mut_mul[0] = muted
** mut_mul[1] = mult
*/

int			ft_f_conv(t_fwplc *ptrfwplc, t_flags *ptrflags,
		va_list arg)
{
	long double		nbr;
	long long		mut_mul[2];

	nbr = (long double)va_arg(arg, double);
	mut_mul[0] = 0;
	mut_mul[1] = 0;
	return (ft_f_base(ptrfwplc, ptrflags, nbr, mut_mul));
}
