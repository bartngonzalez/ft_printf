/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgonzale <bgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 22:28:26 by bgonzale          #+#    #+#             */
/*   Updated: 2019/04/05 21:41:34 by bgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	/*
	** printf && ft_printf
	*/

	printf("[f] Conversion\n");
	printf("[%d]\n", printf("(-+f),                            42.00 = [%-+f]\n", 42.00));
	printf("[%d]\n", ft_printf("(-+f),                            42.00 = [%-+f]\n", 42.00));
	printf("[%d]\n", printf("(-+f),                           -42.00 = [%-+f]\n", -42.00));
	printf("[%d]\n", ft_printf("(-+f),                           -42.00 = [%-+f]\n", -42.00));
	printf("[%d]\n", printf("(- f),                            42.00 = [%- f]\n", 42.00));
	printf("[%d]\n", ft_printf("(- f),                            42.00 = [%- f]\n", 42.00));
	printf("[%d]\n", printf("(- f),                           -42.00 = [%- f]\n", -42.00));
	printf("[%d]\n", ft_printf("(- f),                           -42.00 = [%- f]\n", -42.00));

	printf("\n");

	printf("[%d]\n", printf("(-f),                             42.00 = [%-f]\n", 42.00));
	printf("[%d]\n", ft_printf("(-f),                             42.00 = [%-f]\n", 42.00));
	printf("[%d]\n", printf("(-f),                            -42.00 = [%-f]\n", -42.00));
	printf("[%d]\n", ft_printf("(-f),                            -42.00 = [%-f]\n", -42.00));
	printf("[%d]\n", printf("(-#f),                            42.00 = [%-#f]\n", 42.00));
	printf("[%d]\n", ft_printf("(-#f),                            42.00 = [%-#f]\n", 42.00));
	printf("[%d]\n", printf("(-#f),                           -42.00 = [%-#f]\n", -42.00));
	printf("[%d]\n", ft_printf("(-#f),                           -42.00 = [%-#f]\n", -42.00));
	printf("[%d]\n", printf("(-#20f),                          42.00 = [%-#20f]\n", 42.00));
	printf("[%d]\n", ft_printf("(-#20f),                          42.00 = [%-#20f]\n", 42.00));
	printf("[%d]\n", printf("(-#20f),                         -42.00 = [%-#20f]\n", -42.00));
	printf("[%d]\n", ft_printf("(-#20f),                         -42.00 = [%-#20f]\n", -42.00));
	printf("[%d]\n", printf("(-20f),                           42.00 = [%-20f]\n", 42.00));
	printf("[%d]\n", ft_printf("(-20f),                           42.00 = [%-20f]\n", 42.00));
	printf("[%d]\n", printf("(-20f),                          -42.00 = [%-20f]\n", -42.00));
	printf("[%d]\n", ft_printf("(-20f),                          -42.00 = [%-20f]\n", -42.00));
	printf("[%d]\n", printf("(-#20.f),                         42.00 = [%-#20.f]\n", 42.00));
	printf("[%d]\n", ft_printf("(-#20.f),                         42.00 = [%-#20.f]\n", 42.00));
	printf("[%d]\n", printf("(-#20.f),                        -42.00 = [%-#20.f]\n", -42.00));
	printf("[%d]\n", ft_printf("(-#20.f),                        -42.00 = [%-#20.f]\n", -42.00));

	printf("[%d]\n", printf("(-20.f),                          42.00 = [%-20.f]\n", 42.00));
	printf("[%d]\n", ft_printf("(-20.f),                          42.00 = [%-20.f]\n", 42.00));
	printf("[%d]\n", printf("(-20.f),                         -42.00 = [%-20.f]\n", -42.00));
	printf("[%d]\n", ft_printf("(-20.f),                         -42.00 = [%-20.f]\n", -42.00));

	printf("[%d]\n", printf("(-20.1f),                         42.00 = [%-20.1f]\n", 42.00));
	printf("[%d]\n", ft_printf("(-20.1f),                         42.00 = [%-20.1f]\n", 42.00));
	printf("[%d]\n", printf("(-20.1f),                        -42.00 = [%-20.1f]\n", -42.00));
	printf("[%d]\n", ft_printf("(-20.1f),                        -42.00 = [%-20.1f]\n", -42.00));
	printf("[%d]\n", printf("(-#20.3f),                        42.00 = [%-#20.3f]\n", 42.00));
	printf("[%d]\n", ft_printf("(-#20.3f),                        42.00 = [%-#20.3f]\n", 42.00));
	printf("[%d]\n", printf("(-#20.3f),                       -42.00 = [%-#20.3f]\n", -42.00));
	printf("[%d]\n", ft_printf("(-#20.3f),                       -42.00 = [%-#20.3f]\n", -42.00));
	printf("[%d]\n", printf("(-#25.15f),                       42.00 = [%-#25.15f]\n", 42.00));
	printf("[%d]\n", ft_printf("(-#25.15f),                       42.00 = [%-#25.15f]\n", 42.00));
	printf("[%d]\n", printf("(-#25.15f),                      -42.00 = [%-#25.15f]\n", -42.00));
	printf("[%d]\n", ft_printf("(-#25.15f),                      -42.00 = [%-#25.15f]\n", -42.00));
	printf("[%d]\n", printf("(-+#25.15f),                      42.00 = [%-+#25.15f]\n", 42.00));
	printf("[%d]\n", ft_printf("(-+#25.15f),                      42.00 = [%-+#25.15f]\n", 42.00));
	printf("[%d]\n", printf("(-+#25.15f),                     -42.00 = [%-+#25.15f]\n", -42.00));
	printf("[%d]\n", ft_printf("(-+#25.15f),                     -42.00 = [%-+#25.15f]\n", -42.00));
	printf("[%d]\n", printf("(- #25.15f),                      42.00 = [%- #25.15f]\n", 42.00));
	printf("[%d]\n", ft_printf("(- #25.15f),                      42.00 = [%- #25.15f]\n", 42.00));
	printf("[%d]\n", printf("(- #25.15f),                     -42.00 = [%- #25.15f]\n", -42.00));
	printf("[%d]\n", ft_printf("(- #25.15f),                     -42.00 = [%- #25.15f]\n", -42.00));

	printf("\n[42.42] {START}\n");

	printf("[%d]\n", printf("(-+f),                            42.42 = [%-+f]\n", 42.42));
	printf("[%d]\n", ft_printf("(-+f),                            42.42 = [%-+f]\n", 42.42));
	printf("[%d]\n", printf("(-+f),                           -42.42 = [%-+f]\n", -42.42));
	printf("[%d]\n", ft_printf("(-+f),                           -42.42 = [%-+f]\n", -42.42));
	printf("[%d]\n", printf("(- f),                            42.42 = [%- f]\n", 42.42));
	printf("[%d]\n", ft_printf("(- f),                            42.42 = [%- f]\n", 42.42));
	printf("[%d]\n", printf("(- f),                           -42.42 = [%- f]\n", -42.42));
	printf("[%d]\n", printf("(- f),                           -42.42 = [%- f]\n", -42.42));

	printf("\n");

	printf("[%d]\n", printf("(-f),                             42.42 = [%-f]\n", 42.42));
	printf("[%d]\n", ft_printf("(-f),                             42.42 = [%-f]\n", 42.42));
	printf("[%d]\n", printf("(-f),                            -42.42 = [%-f]\n", -42.42));
	printf("[%d]\n", ft_printf("(-f),                            -42.42 = [%-f]\n", -42.42));
	printf("[%d]\n", printf("(-#f),                            42.42 = [%-#f]\n", 42.42));
	printf("[%d]\n", ft_printf("(-#f),                            42.42 = [%-#f]\n", 42.42));
	printf("[%d]\n", printf("(-#f),                           -42.42 = [%-#f]\n", -42.42));
	printf("[%d]\n", ft_printf("(-#f),                           -42.42 = [%-#f]\n", -42.42));
	printf("[%d]\n", printf("(-#20f),                          42.42 = [%-#20f]\n", 42.42));
	printf("[%d]\n", ft_printf("(-#20f),                          42.42 = [%-#20f]\n", 42.42));
	printf("[%d]\n", printf("(-#20f),                         -42.42 = [%-#20f]\n", -42.42));
	printf("[%d]\n", ft_printf("(-#20f),                         -42.42 = [%-#20f]\n", -42.42));
	printf("[%d]\n", printf("(-20f),                           42.42 = [%-20f]\n", 42.42));
	printf("[%d]\n", ft_printf("(-20f),                           42.42 = [%-20f]\n", 42.42));
	printf("[%d]\n", printf("(-20f),                          -42.42 = [%-20f]\n", -42.42));
	printf("[%d]\n", ft_printf("(-20f),                          -42.42 = [%-20f]\n", -42.42));
	printf("[%d]\n", printf("(-#20.f),                         42.42 = [%-#20.f]\n", 42.42));
	printf("[%d]\n", ft_printf("(-#20.f),                         42.42 = [%-#20.f]\n", 42.42));
	printf("[%d]\n", printf("(-#20.f),                        -42.42 = [%-#20.f]\n", -42.42));
	printf("[%d]\n", ft_printf("(-#20.f),                        -42.42 = [%-#20.f]\n", -42.42));
	printf("[%d]\n", printf("(-20.1f),                         42.42 = [%-20.1f]\n", 42.42));
	printf("[%d]\n", ft_printf("(-20.1f),                         42.42 = [%-20.1f]\n", 42.42));
	printf("[%d]\n", printf("(-20.1f),                        -42.42 = [%-20.1f]\n", -42.42));
	printf("[%d]\n", ft_printf("(-20.1f),                        -42.42 = [%-20.1f]\n", -42.42));
	printf("[%d]\n", printf("(-#20.3f),                        42.42 = [%-#20.3f]\n", 42.42));
	printf("[%d]\n", ft_printf("(-#20.3f),                        42.42 = [%-#20.3f]\n", 42.42));
	printf("[%d]\n", printf("(-#20.3f),                       -42.42 = [%-#20.3f]\n", -42.42));
	printf("[%d]\n", ft_printf("(-#20.3f),                       -42.42 = [%-#20.3f]\n", -42.42));
	printf("[%d]\n", printf("(-#25.16f),                       42.42 = [%-#25.16f]\n", 42.42));
	printf("[%d]\n", ft_printf("(-#25.16f),                       42.42 = [%-#25.16f]\n", 42.42));
	printf("[%d]\n", printf("(-#25.16f),                      -42.42 = [%-#25.16f]\n", -42.42));
	printf("[%d]\n", ft_printf("(-#25.16f),                      -42.42 = [%-#25.16f]\n", -42.42));
	printf("[%d]\n", printf("(-#25.15f),                       42.42 = [%-#25.15f]\n", 42.42));
	printf("[%d]\n", ft_printf("(-#25.15f),                       42.42 = [%-#25.15f]\n", 42.42));
	printf("[%d]\n", printf("(-#25.15f),                      -42.42 = [%-#25.15f]\n", -42.42));
	printf("[%d]\n", ft_printf("(-#25.15f),                      -42.42 = [%-#25.15f]\n", -42.42));
	printf("[%d]\n", printf("(-+#25.15f),                      42.42 = [%-+#25.15f]\n", 42.42));
	printf("[%d]\n", ft_printf("(-+#25.15f),                      42.42 = [%-+#25.15f]\n", 42.42));
	printf("[%d]\n", printf("(-+#25.15f),                     -42.42 = [%-+#25.15f]\n", -42.42));
	printf("[%d]\n", ft_printf("(-+#25.15f),                     -42.42 = [%-+#25.15f]\n", -42.42));
	printf("[%d]\n", printf("(- #25.15f),                      42.42 = [%- #25.15f]\n", 42.42));
	printf("[%d]\n", ft_printf("(- #25.15f),                      42.42 = [%- #25.15f]\n", 42.42));
	printf("[%d]\n", printf("(- #25.15f),                     -42.42 = [%- #25.15f]\n", -42.42));
	printf("[%d]\n", ft_printf("(- #25.15f),                     -42.42 = [%- #25.15f]\n", -42.42));

	printf("\n");
	printf("\n");
	printf("\n");

	printf("[%d]\n", printf("(+f),                            42.00 = [%+f]\n", 42.00));
	printf("[%d]\n", ft_printf("(+f),                            42.00 = [%+f]\n", 42.00));
	printf("[%d]\n", printf("(+f),                           -42.00 = [%+f]\n", -42.00));
	printf("[%d]\n", ft_printf("(+f),                           -42.00 = [%+f]\n", -42.00));
	printf("[%d]\n", printf("( f),                            42.00 = [% f]\n", 42.00));
	printf("[%d]\n", ft_printf("( f),                            42.00 = [% f]\n", 42.00));
	printf("[%d]\n", printf("( f),                           -42.00 = [% f]\n", -42.00));
	printf("[%d]\n", ft_printf("( f),                           -42.00 = [% f]\n", -42.00));

	printf("\n");

	printf("[%d]\n", printf("(f),                             42.00 = [%f]\n", 42.00));
	printf("[%d]\n", ft_printf("(f),                             42.00 = [%f]\n", 42.00));
	printf("[%d]\n", printf("(f),                            -42.00 = [%f]\n", -42.00));
	printf("[%d]\n", ft_printf("(f),                            -42.00 = [%f]\n", -42.00));
	printf("[%d]\n", printf("(#f),                            42.00 = [%#f]\n", 42.00));
	printf("[%d]\n", ft_printf("(#f),                            42.00 = [%#f]\n", 42.00));
	printf("[%d]\n", printf("(#f),                           -42.00 = [%#f]\n", -42.00));
	printf("[%d]\n", ft_printf("(#f),                           -42.00 = [%#f]\n", -42.00));
	printf("[%d]\n", printf("(#20f),                          42.00 = [%#20f]\n", 42.00));
	printf("[%d]\n", ft_printf("(#20f),                          42.00 = [%#20f]\n", 42.00));
	printf("[%d]\n", printf("(#20f),                         -42.00 = [%#20f]\n", -42.00));
	printf("[%d]\n", ft_printf("(#20f),                         -42.00 = [%#20f]\n", -42.00));
	printf("[%d]\n", printf("(20f),                           42.00 = [%20f]\n", 42.00));
	printf("[%d]\n", ft_printf("(20f),                           42.00 = [%20f]\n", 42.00));
	printf("[%d]\n", printf("(20f),                          -42.00 = [%20f]\n", -42.00));
	printf("[%d]\n", ft_printf("(20f),                          -42.00 = [%20f]\n", -42.00));
	printf("[%d]\n", printf("(#20.f),                         42.00 = [%#20.f]\n", 42.00));
	printf("[%d]\n", ft_printf("(#20.f),                         42.00 = [%#20.f]\n", 42.00));
	printf("[%d]\n", printf("(#20.f),                        -42.00 = [%#20.f]\n", -42.00));
	printf("[%d]\n", ft_printf("(#20.f),                        -42.00 = [%#20.f]\n", -42.00));

	printf("[%d]\n", printf("(20.f),                          42.00 = [%20.f]\n", 42.00));
	printf("[%d]\n", ft_printf("(20.f),                          42.00 = [%20.f]\n", 42.00));
	printf("[%d]\n", printf("(20.f),                         -42.00 = [%20.f]\n", -42.00));
	printf("[%d]\n", ft_printf("(20.f),                         -42.00 = [%20.f]\n", -42.00));

	printf("[%d]\n", printf("(20.1f),                         42.00 = [%20.1f]\n", 42.00));
	printf("[%d]\n", ft_printf("(20.1f),                         42.00 = [%20.1f]\n", 42.00));
	printf("[%d]\n", printf("(20.1f),                        -42.00 = [%20.1f]\n", -42.00));
	printf("[%d]\n", ft_printf("(20.1f),                        -42.00 = [%20.1f]\n", -42.00));
	printf("[%d]\n", printf("(#20.3f),                        42.00 = [%#20.3f]\n", 42.00));
	printf("[%d]\n", ft_printf("(#20.3f),                        42.00 = [%#20.3f]\n", 42.00));
	printf("[%d]\n", printf("(#20.3f),                       -42.00 = [%#20.3f]\n", -42.00));
	printf("[%d]\n", ft_printf("(#20.3f),                       -42.00 = [%#20.3f]\n", -42.00));
	printf("[%d]\n", printf("(#25.15f),                       42.00 = [%#25.15f]\n", 42.00));
	printf("[%d]\n", ft_printf("(#25.15f),                       42.00 = [%#25.15f]\n", 42.00));
	printf("[%d]\n", printf("(#25.15f),                      -42.00 = [%#25.15f]\n", -42.00));
	printf("[%d]\n", ft_printf("(#25.15f),                      -42.00 = [%#25.15f]\n", -42.00));
	printf("[%d]\n", printf("(+#25.15f),                      42.00 = [%+#25.15f]\n", 42.00));
	printf("[%d]\n", ft_printf("(+#25.15f),                      42.00 = [%+#25.15f]\n", 42.00));
	printf("[%d]\n", printf("(+#25.15f),                     -42.00 = [%+#25.15f]\n", -42.00));
	printf("[%d]\n", ft_printf("(+#25.15f),                     -42.00 = [%+#25.15f]\n", -42.00));
	printf("[%d]\n", printf("( #25.15f),                      42.00 = [% #25.15f]\n", 42.00));
	printf("[%d]\n", ft_printf("( #25.15f),                      42.00 = [% #25.15f]\n", 42.00));
	printf("[%d]\n", printf("( #25.15f),                     -42.00 = [% #25.15f]\n", -42.00));
	printf("[%d]\n", ft_printf("( #25.15f),                     -42.00 = [% #25.15f]\n", -42.00));

	printf("\n[42.42] {START}\n");

	printf("[%d]\n", printf("(+f),                            42.42 = [%+f]\n", 42.42));
	printf("[%d]\n", ft_printf("(+f),                            42.42 = [%+f]\n", 42.42));
	printf("[%d]\n", printf("(+f),                           -42.42 = [%+f]\n", -42.42));
	printf("[%d]\n", ft_printf("(+f),                           -42.42 = [%+f]\n", -42.42));
	printf("[%d]\n", printf("( f),                            42.42 = [% f]\n", 42.42));
	printf("[%d]\n", ft_printf("( f),                            42.42 = [% f]\n", 42.42));
	printf("[%d]\n", printf("( f),                           -42.42 = [% f]\n", -42.42));
	printf("[%d]\n", printf("( f),                           -42.42 = [% f]\n", -42.42));

	printf("\n");

	printf("[%d]\n", printf("(f),                             42.42 = [%f]\n", 42.42));
	printf("[%d]\n", ft_printf("(f),                             42.42 = [%f]\n", 42.42));
	printf("[%d]\n", printf("(f),                            -42.42 = [%f]\n", -42.42));
	printf("[%d]\n", ft_printf("(f),                            -42.42 = [%f]\n", -42.42));
	printf("[%d]\n", printf("(#f),                            42.42 = [%#f]\n", 42.42));
	printf("[%d]\n", ft_printf("(#f),                            42.42 = [%#f]\n", 42.42));
	printf("[%d]\n", printf("(#f),                           -42.42 = [%#f]\n", -42.42));
	printf("[%d]\n", ft_printf("(#f),                           -42.42 = [%#f]\n", -42.42));
	printf("[%d]\n", printf("(#20f),                          42.42 = [%#20f]\n", 42.42));
	printf("[%d]\n", ft_printf("(#20f),                          42.42 = [%#20f]\n", 42.42));
	printf("[%d]\n", printf("(#20f),                         -42.42 = [%#20f]\n", -42.42));
	printf("[%d]\n", ft_printf("(#20f),                         -42.42 = [%#20f]\n", -42.42));
	printf("[%d]\n", printf("(20f),                           42.42 = [%20f]\n", 42.42));
	printf("[%d]\n", ft_printf("(20f),                           42.42 = [%20f]\n", 42.42));
	printf("[%d]\n", printf("(20f),                          -42.42 = [%20f]\n", -42.42));
	printf("[%d]\n", ft_printf("(20f),                          -42.42 = [%20f]\n", -42.42));
	printf("[%d]\n", printf("(#20.f),                         42.42 = [%#20.f]\n", 42.42));
	printf("[%d]\n", ft_printf("(#20.f),                         42.42 = [%#20.f]\n", 42.42));
	printf("[%d]\n", printf("(#20.f),                        -42.42 = [%#20.f]\n", -42.42));
	printf("[%d]\n", ft_printf("(#20.f),                        -42.42 = [%#20.f]\n", -42.42));
	printf("[%d]\n", printf("(20.1f),                         42.42 = [%20.1f]\n", 42.42));
	printf("[%d]\n", ft_printf("(20.1f),                         42.42 = [%20.1f]\n", 42.42));
	printf("[%d]\n", printf("(20.1f),                        -42.42 = [%20.1f]\n", -42.42));
	printf("[%d]\n", ft_printf("(20.1f),                        -42.42 = [%20.1f]\n", -42.42));
	printf("[%d]\n", printf("(#20.3f),                        42.42 = [%#20.3f]\n", 42.42));
	printf("[%d]\n", ft_printf("(#20.3f),                        42.42 = [%#20.3f]\n", 42.42));
	printf("[%d]\n", printf("(#20.3f),                       -42.42 = [%#20.3f]\n", -42.42));
	printf("[%d]\n", ft_printf("(#20.3f),                       -42.42 = [%#20.3f]\n", -42.42));
	printf("[%d]\n", printf("(#25.16f),                       42.42 = [%#25.16f]\n", 42.42));
	printf("[%d]\n", ft_printf("(#25.16f),                       42.42 = [%#25.16f]\n", 42.42));
	printf("[%d]\n", printf("(#25.16f),                      -42.42 = [%#25.16f]\n", -42.42));
	printf("[%d]\n", ft_printf("(#25.16f),                      -42.42 = [%#25.16f]\n", -42.42));
	printf("[%d]\n", printf("(#25.15f),                       42.42 = [%#25.15f]\n", 42.42));
	printf("[%d]\n", ft_printf("(#25.15f),                       42.42 = [%#25.15f]\n", 42.42));
	printf("[%d]\n", printf("(#25.15f),                      -42.42 = [%#25.15f]\n", -42.42));
	printf("[%d]\n", ft_printf("(#25.15f),                      -42.42 = [%#25.15f]\n", -42.42));
	printf("[%d]\n", printf("(+#25.15f),                      42.42 = [%+#25.15f]\n", 42.42));
	printf("[%d]\n", ft_printf("(+#25.15f),                      42.42 = [%+#25.15f]\n", 42.42));
	printf("[%d]\n", printf("(+#25.15f),                     -42.42 = [%+#25.15f]\n", -42.42));
	printf("[%d]\n", ft_printf("(+#25.15f),                     -42.42 = [%+#25.15f]\n", -42.42));
	printf("[%d]\n", printf("( #25.15f),                      42.42 = [% #25.15f]\n", 42.42));
	printf("[%d]\n", ft_printf("( #25.15f),                      42.42 = [% #25.15f]\n", 42.42));
	printf("[%d]\n", printf("( #25.15f),                     -42.42 = [% #25.15f]\n", -42.42));
	printf("[%d]\n", ft_printf("( #25.15f),                     -42.42 = [% #25.15f]\n", -42.42));


	printf("[%d]\n", printf("( #025.15f),                     42.42 = [% #025.15f]\n", 42.42));
	printf("[%d]\n", ft_printf("( #025.15f),                     42.42 = [% #025.15f]\n", 42.42));
	printf("[%d]\n", printf("( #025.15f),                    -42.42 = [% #025.15f]\n", -42.42));
	printf("[%d]\n", ft_printf("( #025.15f),                    -42.42 = [% #025.15f]\n", -42.42));
	return (0);
}
