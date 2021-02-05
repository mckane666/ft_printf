/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:30:28 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/02/03 18:19:06 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

 int	ft_printf(const char *tipo, ...) //qq "coisa %s",ola
{
	va_list ap;
	int i;
	double d;
	int cont, cont2;
	int c;
	char *s;

	cont = 0;
	cont2 = 0;
	va_start(ap, *tipo);
	while (*++tipo != '\0')
	{
		if (*tipo == '%') // conta os %
			tipo++;
			cont2++;
		if (*tipo == 's')
		{
			s = va_arg(ap, char *);
			cont++;
			ft_putstr("*char ");	//
			ft_putstr(s);		//
			printf("\n");
		}
		else if (*tipo == 'd')
		{
			i = va_arg(ap, int);
			cont++;
			ft_putstr("int ");		//
			ft_putstr(ft_itoa(i));	//
			printf("\n");
		}
		else if (*tipo == 'f')
		{
			d = va_arg(ap, double);
			cont++;
			printf("int %f\n", d);
		}
		else if (*tipo == 'c')
		{
			c = va_arg(ap, int);
			cont++;
			ft_putstr("char ");		//
			ft_putchar((char)c);
			printf("\n");
		}
	}
	va_end(ap);
	printf("cont %d cont2 %d\n\n",cont, cont2);
}


int main()
{
	ft_printf("%s", "ola");
	ft_printf("%d%c%f%f", 3, 'a', 1.999, 4.25);
}
