/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:38:26 by bgonzale          #+#    #+#             */
/*   Updated: 2019/02/16 00:52:02 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	// [c] - Conversion
	printf("[c] - Conversion\n");
	printf("(c),   42 = [%c]\n", 42);
	printf("(5c),  42 = [%5c]\n", 42);
	printf("(-5c), 42 = [%-5c]\n", 42);
	printf("(.c),  42 = [%.c]\n", 42);

	// [s] - Conversion
	printf("\n\n[s] - Conversion\n");
	printf("(s),     42 = [%s]\n", "42");
	printf("(5s),    42 = [%5s]\n", "42");
	printf("(-5s),   42 = [%-5s]\n", "42");
	printf("(-5.s),  42 = [%-5.0s]\n", "42");
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
	printf("[%-.2s] is a string\n", "I am");
	printf("[%-10s] is a string\n", "");

	// [o] - Conversion
	printf("\n\n[o] - Conversion\n");
	printf("(#o),    42 = [%#o]\n", 42);
	printf("(#-5o),  42 = [%#-5o]\n", 42);
	printf("(#05o),  42 = [%#05o]\n", 42);
	printf("(#5o),   42 = [%#5o]\n", 42);
	printf("(#.5o),  42 = [%#.5o]\n", 42);
	printf("(#.1o),  42 = [%#.1o]\n", 42);
	printf("(#.o),   42 = [%#.o]\n", 42);
	printf("(#.o),   42 = [%#.o]\n", 42);
	printf("(#0.o),  42 = [%#0.o]\n", 42);

	//ft_printf("\nft_printf = [%## -+0.1230llc] | test = [%## -+0.1230llc]\n", 'a', 'b');
	printf("\nft_printf\n");
	printf("\n[c] - Conversion\n");
	ft_printf("(c),   42 = [%c]\n", 42);
	ft_printf("(5c),  42 = [%5c]\n", 42);
	ft_printf("(-5c), 42 = [%-5c]\n", 42);
	ft_printf("(.c),  42 = [%.c]\n", 42);

	printf("\n[s] - Conversion\n");
	ft_printf("(s),     42 = [%s]\n", "42");
	ft_printf("(5s),    42 = [%5s]\n", "42");
	ft_printf("(-5s),   42 = [%-5s]\n", "42");
	ft_printf("(-5.s),  42 = [%-5.0s]\n", "42");
	ft_printf("(-5.1s), 42 = [%-5.1s]\n", "42");
	return (0);
}
