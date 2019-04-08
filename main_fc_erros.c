/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fc_erros.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:45:05 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/08 06:32:52 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	printf("(+d),         0 = [%+d]\n", 0);
	ft_printf("(+d),         0 = [%+d]\n", 0);

	printf("\n");

	ft_printf("@moulitest: [%#.x] [%#.0x]\n", 0, 0);
	printf("@moulitest: [%#.x] [%#.0x]\n", 0, 0);

	printf("\n");

	printf("@moulitest: [%.x] [%.0x]\n", 0, 0);
	ft_printf("@moulitest: [%.x] [%.0x]\n", 0, 0);

	printf("\n");

	printf("@moulitest: [%5.x] [%5.0x]\n", 0, 0);
	ft_printf("@moulitest: [%5.x] [%5.0x]\n", 0, 0);

	printf("\n");

	printf("[%5.2s] is a string\n", "");
	ft_printf("[%5.2s] is a string\n", "");

	printf("\n");

	printf("[%-5.2s] is a string\n", "");
	ft_printf("[%-5.2s] is a string\n", "");

	printf("\n");

	printf("@moulitest: [%s]\n", NULL);
	ft_printf("@moulitest: [%s]\n", NULL);

	printf("\n");

	printf("[%.2c]\n", NULL);
	ft_printf("[%.2c]\n", NULL);

	printf("\n");

	printf("[%s] [%s]\n", NULL, "string");
	ft_printf("[%s] [%s]\n", NULL, "string");

	printf("\n");

	printf("@moulitest: [%c]\n", 0); // Ok
	ft_printf("@moulitest: [%c]\n", 0); // Ok

	printf("\n");

	printf("[%2c]\n", 0); // Ok
	ft_printf("[%2c]\n", 0); // Ok

	printf("\n");

	printf("null [%c] and text\n", 0); // Ok
	ft_printf("null [%c] and text\n", 0); // Ok

	printf("\n");

	printf("[% c]\n", 0); // flag ' ' results in undefined behavior with 'c'
	ft_printf("[% c]\n", 0); // flag ' ' results in undefined behavior with 'c'

	printf("\n");

	printf("@moulitest: [%.o] [%.0o]\n", 0, 0);
	ft_printf("@moulitest: [%.o] [%.0o]\n", 0, 0);

	printf("\n");

	printf("@moulitest: [%5.o] [%5.0o]\n", 0, 0);
	ft_printf("@moulitest: [%5.o] [%5.0o]\n", 0, 0);

	printf("\n");

	printf("@moulitest: [%#.o] [%#.0o]\n", 0, 0);
	ft_printf("@moulitest: [%#.o] [%#.0o]\n", 0, 0);

	printf("\n");

	printf("[%+d]\n", 0);
	ft_printf("[%+d]\n", 0);

	printf("@moulitest: [%#.x] [%#.0x]\n", 0, 0);
	ft_printf("@moulitest: [%#.x] [%#.0x]\n", 0, 0);
	printf("@moulitest: [%.x] [%.0x]\n", 0, 0);
	ft_printf("@moulitest: [%.x] [%.0x]\n", 0, 0);
	printf("@moulitest: [%5.x] [%5.0x]\n", 0, 0);
	ft_printf("@moulitest: [%5.x] [%5.0x]\n", 0, 0);
	printf("@moulitest: [%.o] [%.0o]\n", 0, 0);
	ft_printf("@moulitest: [%.o] [%.0o]\n", 0, 0);
	printf("@moulitest: [%5.o] [%5.0o]\n", 0, 0);
	ft_printf("@moulitest: [%5.o] [%5.0o]\n", 0, 0);
	printf("@moulitest: [%#.o] [%#.0o]\n", 0, 0);
	ft_printf("@moulitest: [%#.o] [%#.0o]\n", 0, 0);

	printf("\n");
	printf("\n");

	printf("[%lld]\n", -9223372036854775808);
	ft_printf("[%lld]\n", -9223372036854775808);
	printf("@moulitest: [%.d] [%.0d]\n", 0, 0);
	ft_printf("@moulitest: [%.d] [%.0d]\n", 0, 0);
	printf("@moulitest: [%5.d] [%5.0d]\n", 0, 0);
	ft_printf("@moulitest: [%5.d] [%5.0d]\n", 0, 0);

	printf("\n");
	printf("\n");

	printf("[%%]\n");
	ft_printf("[%%]\n");
	printf("[%5%]\n");
	ft_printf("[%5%]\n");
	printf("[%-5%]\n");
	ft_printf("[%-5%]\n");
	printf("[%.0%]\n");
	ft_printf("[%.0%]\n");
	printf("[%%]\n", "test");
	ft_printf("[%%]\n", "test");
	printf("[%   %]\n", "test");
	ft_printf("[%   %]\n", "test");

	printf("\n");
	printf("\n");

	printf("[%010s] is a string\n", "this");
	ft_printf("[%010s] is a string\n", "this");
	printf("[%-010s] is a string\n", "this");
	ft_printf("[%-010s] is a string\n", "this");

	printf("\n");
	printf("\n");

	printf("[%lld]\n", -9223372036854775808);
	ft_printf("[%lld]\n", -9223372036854775808);
	return (0);
}
