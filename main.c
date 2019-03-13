/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:38:26 by bgonzale          #+#    #+#             */
/*   Updated: 2019/03/12 15:32:48 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	/*
	** printf
	*/

	printf("[printf]\n\n");
	// [c] - Conversion
	// Invalid flags: #, space, +
	printf("[c] - Conversion\n");
	printf("(c),   42 = [%c]\n", 42);
	printf("(5c),  42 = [%5c]\n", 42);
	printf("(-5c), 42 = [%-5c]\n", 42);
	printf("(.c),  42 = [%.c]\n", 42);

	// [s] - Conversion
	// Invalid flags: #, space, +
	printf("\n\n[s] - Conversion\n");
	printf("(s),     42 = [%s]\n", "42");
	printf("(5s),    42 = [%5s]\n", "42");
	printf("(-5s),   42 = [%-5s]\n", "42");
	printf("(-5.0s), 42 = [%-5.0s]\n", "42");
	printf("(-5.1s), 42 = [%-5.1s]\n", "42");
	printf("(-5.s),  42 = [%-5.s]\n", "42");
	printf("(-3.1s), 42 = [%-3.1s]\n", "42");
	printf("(-3.2s), 42 = [%-3.2s]\n", "42");
	printf("(-3.s),  42 = [%-3.s]\n", "42");
	printf("(.s),    42 = [%.s]\n", "42");
	printf("(.0s),   42 = [%.0s]\n", "42");
	printf("(.5s),   42 = [%.5s]\n", "42");
	printf("(3.1s),  42 = [%3.1s]\n", "42");
	printf("(3.2s),  42 = [%3.2s]\n", "42");
	printf("(-3.0s), 42 = [%-3.0s]\n", "42");
	printf("(3.0s),  42 = [%3.0s]\n", "42");
	printf("(3.s),   42 = [%3.s]\n", "42");
	printf("[%2.1s] is a string\n", "Iam");
	printf("[%-2.1s] is a string\n", "Iam");
	printf("[%5.2s] is a string\n", "Iam");
	printf("[%-5.2s] is a string\n", "Iam");
	printf("[%-10s] is a string\n", "");

	// [p] - Conversion
	// Invalid flags: #, space, +
	printf("\n\n[p] - Conversion\n");
	char *pstr = "42";
	printf("(p),     *pstr = [%p]\n", pstr);
	printf("(.p),    *pstr = [%.p]\n", pstr);
	printf("(12p),   *pstr = [%12p]\n", pstr);
	printf("(-12p),  *pstr = [%-12p]\n", pstr);

	// [d] - Conversion
	// Invalid flags: #, '0' is ignored when '-' is present
	printf("\n\n[d] - Conversion\n");
	printf("(d),      42000 = [%d]\n", 42000);
	printf("(9d),     42000 = [%9d]\n", 42000);
	printf("(0d),     42000 = [%0d]\n", 42000);
	printf("(0.d),    42000 = [%0.d]\n", 42000);
	printf("(0.9d),   42000 = [%0.9d]\n", 42000);
	printf("(+d),     42000 = [%+d]\n", 42000);
	printf("(0+d),    42000 = [%0+d]\n", 42000);
	printf("(+9d),    42000 = [%+9d]\n", 42000);
	printf("(0+9d),   42000 = [%0+9d]\n", 42000);
	printf("(+.d),    42000 = [%+.d]\n", 42000);
	printf("(+.9d),   42000 = [%+.9d]\n", 42000);
	printf("(.d),     42000 = [%.d]\n", 42000);
	printf("(.9d),    42000 = [%.9d]\n", 42000);
	printf("(-d),     42000 = [%-d]\n", 42000);
	printf("(-9d),    42000 = [%-9d]\n", 42000);
	printf("(-9.9d),  42000 = [%-9.9d]\n", 42000);
	printf("( d),     42000 = [% d]\n", 42000);
	printf("( 6d),    42000 = [% 6d]\n", 42000);
	printf("( 7d),    42000 = [% 7d]\n", 42000);
	printf("( 07d),   42000 = [% 07d]\n", 42000);
	printf("( 013d),  42000 = [% 013d]\n", 42000);
	printf("( 10.5d),  4242 = [% 10.5d]\n", 4242);
	printf("( 010.5d), 4242 = [% 010.5d]\n", 4242);
	printf("( 010.6d), 4242 = [% 010.6d]\n", 4242);
	printf("[d] - Conversion [42FileChecker Tests]\n");
	printf("(.2d),     4242 = [%.2d]\n", 4242);
	printf("(.10d),    4242 = [%.10d]\n", 4242);
	printf("(10.5d),   4242 = [%10.5d]\n", 4242);
	printf("(-10.5d),  4242 = [%-10.5d]\n", 4242);
	printf("(+10.5d),  4242 = [%+10.5d]\n", 4242);
	printf("(-+10.5d), 4242 = [%-+10.5d]\n", 4242);

	// [i] - Conversion
	// Invalid flags: #, '0' is ignored when '-' is present
	printf("\n\n[i] - Conversion\n");
	printf("(i),      42000 = [%i]\n", 42000);
	printf("(9i),     42000 = [%9i]\n", 42000);
	printf("(0i),     42000 = [%0i]\n", 42000);
	printf("(0.i),    42000 = [%0.i]\n", 42000);
	printf("(0.9i),   42000 = [%0.9i]\n", 42000);
	printf("(+i),     42000 = [%+i]\n", 42000);
	printf("(0+i),    42000 = [%0+i]\n", 42000);
	printf("(+9i),    42000 = [%+9i]\n", 42000);
	printf("(0+9i),   42000 = [%0+9i]\n", 42000);
	printf("(+.i),    42000 = [%+.i]\n", 42000);
	printf("(+.9i),   42000 = [%+.9i]\n", 42000);
	printf("(.i),     42000 = [%.i]\n", 42000);
	printf("(.9i),    42000 = [%.9i]\n", 42000);
	printf("(-i),     42000 = [%-i]\n", 42000);
	printf("(-9i),    42000 = [%-9i]\n", 42000);
	printf("(-9.9i),  42000 = [%-9.9i]\n", 42000);
	printf("( i),     42000 = [% i]\n", 42000);
	printf("( 6i),    42000 = [% 6i]\n", 42000);
	printf("( 7i),    42000 = [% 7i]\n", 42000);
	printf("( 07i),   42000 = [% 07i]\n", 42000);
	printf("( 013i),  42000 = [% 013i]\n", 42000);
	printf("( 10.5i),  4242 = [% 10.5i]\n", 4242);
	printf("( 010.5i), 4242 = [% 010.5i]\n", 4242);
	printf("( 010.6i), 4242 = [% 010.6i]\n", 4242);
	printf("[i] - Conversion [42FileChecker Tests]\n");
	printf("(.2i),     4242 = [%.2i]\n", 4242);
	printf("(.10i),    4242 = [%.10i]\n", 4242);
	printf("(10.5i),   4242 = [%10.5i]\n", 4242);
	printf("(-10.5i),  4242 = [%-10.5i]\n", 4242);
	printf("( 10.5i),  4242 = [% 10.5i]\n", 4242);
	printf("(+10.5i),  4242 = [%+10.5i]\n", 4242);
	printf("(-+10.5i), 4242 = [%-+10.5i]\n", 4242);

	// [o] - Conversion
	// printf("\n\n[o] - Conversion\n");
	// printf("(#),     42 = [%o]\n", 42);
	// printf("(#o),    42 = [%#o]\n", 42);
	// printf("(#-5o),  42 = [%#-5o]\n", 42);
	// printf("(#05o),  42 = [%#05o]\n", 42);
	// printf("(#5o),   42 = [%#5o]\n", 42);
	// printf("(#.5o),  42 = [%#.5o]\n", 42);
	// printf("(#.1o),  42 = [%#.1o]\n", 42);
	// printf("(#.o),   42 = [%#.o]\n", 42);
	// printf("(#.o),   42 = [%#.o]\n", 42);
	// printf("(#0.o),  42 = [%#0.o]\n", 42);

	/*
	** ft_printf
	*/

	printf("\n[ft_printf]\n\n");
	// [c] - Conversion
	// printf("[c] - Conversion\n");
	// ft_printf("(c),   42 = [%c]\n", 42);
	// ft_printf("(5c),  42 = [%5c]\n", 42);
	// ft_printf("(-5c), 42 = [%-5c]\n", 42);
	// ft_printf("(.c),  42 = [%.c]\n", 42);
	// printf("[c] - Conversion [0 flag]\n");
	// ft_printf("(0c),   42 = [%0c]\n", 42);
	// ft_printf("(05c),  42 = [%05c]\n", 42);
	// ft_printf("(0-5c), 42 = [%0-5c]\n", 42);
	// ft_printf("(0.c),  42 = [%0.c]\n", 42);

	// [s] - Conversion
	// printf("\n[s] - Conversion\n");
	// ft_printf("(s),     42 = [%s]\n", "42");
	// ft_printf("(5s),    42 = [%5s]\n", "42");
	// ft_printf("(-5s),   42 = [%-5s]\n", "42");
	// ft_printf("(-5.0s), 42 = [%-5.0s]\n", "42");
	// ft_printf("(-5.1s), 42 = [%-5.1s]\n", "42");
	// ft_printf("(-5.s),  42 = [%-5.s]\n", "42");
	// ft_printf("(-3.1s), 42 = [%-3.1s]\n", "42");
	// ft_printf("(-3.2s), 42 = [%-3.2s]\n", "42");
	// ft_printf("(-3.s),  42 = [%-3.s]\n", "42");
	// ft_printf("(.s),    42 = [%.s]\n", "42");
	// ft_printf("(.0s),   42 = [%.0s]\n", "42");
	// ft_printf("(.5s),   42 = [%.5s]\n", "42");
	// ft_printf("(3.1s),  42 = [%3.1s]\n", "42");
	// ft_printf("(3.2s),  42 = [%3.2s]\n", "42");
	// ft_printf("(-3.0s), 42 = [%-3.0s]\n", "42");
	// ft_printf("(3.0s),  42 = [%3.0s]\n", "42");
	// ft_printf("(3.s),   42 = [%3.s]\n", "42");
	// ft_printf("[%2.1s] is a string\n", "Iam");
	// ft_printf("[%-2.1s] is a string\n", "Iam");
	// ft_printf("[%5.2s] is a string\n", "Iam");
	// ft_printf("[%-5.2s] is a string\n", "Iam");
	// ft_printf("[%-10s] is a string\n", "");
	// printf("[s] - Conversion [0 flag]\n");
	// ft_printf("(0s),     42 = [%0s]\n", "42");
	// ft_printf("(05s),    42 = [%05s]\n", "42");
	// ft_printf("(0-5s),   42 = [%0-5s]\n", "42");
	// ft_printf("(0-5.0s), 42 = [%0-5.0s]\n", "42");
	// ft_printf("(0-5.1s), 42 = [%0-5.1s]\n", "42");
	// ft_printf("(0-5.s),  42 = [%0-5.s]\n", "42");
	// ft_printf("(0-3.1s), 42 = [%0-3.1s]\n", "42");
	// ft_printf("(0-3.2s), 42 = [%0-3.2s]\n", "42");
	// ft_printf("(0-3.s),  42 = [%0-3.s]\n", "42");
	// ft_printf("(0.s),    42 = [%0.s]\n", "42");
	// ft_printf("(0.0s),   42 = [%0.0s]\n", "42");
	// ft_printf("(0.5s),   42 = [%0.5s]\n", "42");
	// ft_printf("(03.1s),  42 = [%03.1s]\n", "42");
	// ft_printf("(03.2s),  42 = [%03.2s]\n", "42");
	// ft_printf("(0-3.0s), 42 = [%0-3.0s]\n", "42");
	// ft_printf("(03.0s),  42 = [%03.0s]\n", "42");
	// ft_printf("(03.s),   42 = [%03.s]\n", "42");
	// ft_printf("[%02.1s] is a string\n", "Iam");
	// ft_printf("[%0-2.1s] is a string\n", "Iam");
	// ft_printf("[%05.2s] is a string\n", "Iam");
	// ft_printf("[%0-5.2s] is a string\n", "Iam");
	// ft_printf("[%0-10s] is a string\n", "");

	// [p] - Conversion
	// printf("\n\n[p] - Conversion\n");
	// ft_printf("(p),     *pstr = [%p]\n", pstr);
	// ft_printf("(.p),    *pstr = [%.p]\n", pstr);
	// ft_printf("(12p),   *pstr = [%12p]\n", pstr);
	// ft_printf("(-12p),  *pstr = [%-12p]\n", pstr);
	// ft_printf("(.1p),   *pstr = [%.1p]\n", pstr);
	// ft_printf("(16p),   *pstr = [%16p]\n", pstr);
	// ft_printf("(-16p),  *pstr = [%-16p]\n", pstr);
	// ft_printf("(016p),  *pstr = [%016p]\n", pstr);
	// ft_printf("(-016p), *pstr = [%-016p]\n", pstr);
	return (0);
}
