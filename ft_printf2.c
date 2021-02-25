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

 #include "ft_printf.h"
#include "libft/libft.h"

void	ft_init_printf_flags(t_printf *pf)
{
	pf->point = 0;
	pf->minus = 0;
	pf->ast = 0;
	pf->zero = 0;
	pf->cont = 0;
	pf->str_len = 0;
	pf->space = 0;
	pf->index = 0;
	pf->width = 0;
	pf->precision = 0;
	pf->ast_width = 0;//
}

void	ft_flags(t_printf *pf, va_list ap)
{
	while (!ft_strchr(CONVERSIONS, pf->get_args[pf->index]))
	{
		if (ft_strchr("-", pf->get_args[pf->index]))
			pf->minus = 1;
		else if (ft_strchr(".", pf->get_args[pf->index]))
			pf->point = 1;
		else if (ft_strchr("*", pf->get_args[pf->index]))
		{
			pf->ast = 1;
			pf->width = va_arg(ap, int);
			if (pf->width < 0)
			{	
				pf->width = pf->width * -1;
				pf->minus = 1;
			}
		}
		else if (ft_strchr("0", pf->get_args[pf->index]))
		 	pf->zero = 1;
		else if (ft_strchr(WIDTH, pf->get_args[pf->index]) && pf->width <= 0 && !pf->point)
		 	pf->width = ft_atoi(&pf->get_args[pf->index]); //
		else if (ft_strchr(WIDTH, pf->get_args[pf->index]) && pf->point)
		 	pf->precision = ft_atoi(&pf->get_args[pf->index]); //
		pf->index++;
	}
	printf("Preci = %d widht = %d index = %d minus = %d point = %d zero = %d ast = %d\n",pf->precision, pf->width, pf->index, pf->minus, pf->point, pf->zero, pf->ast_width);
}

void	ft_specifiers(t_printf *pf, va_list ap)
{
	if (ft_strchr(FLAGS, pf->get_args[pf->index]))
		ft_flags(pf, ap);
	// else if (ft_strchr(WIDTH, pf->get_args[pf->index]))
	//   	ft_width(pf, ap);
	// if (ft_strchr(PRECISION))
	// 	ft_precision(pf, ap);
	// if (ft_strchr(SIZE))
	// 	ft_size(pf, ap);
}

void	ft_parse(t_printf *pf, va_list ap)
{
	if (ft_strchr(SPECIFIERS, pf->get_args[pf->index]))
		ft_flags(pf, ap);
	if (ft_strchr(CONVERSIONS, pf->get_args[pf->index]))
		ft_minus(pf, ap);//ft_conversions();
}

int	ft_printf(const char *format, ...) /** "qualquer coisa %s",...
%[flags][width][.precision][size]type **/
{
	t_printf pf;
	va_list	ap;
	ft_init_printf_flags(&pf);
	pf.get_args = (char *)format;
	va_start(ap, format);
	while (format[pf.index] != '\0')
	{
		if (format[pf.index] == '%')
		{
			pf.index++;
			ft_parse(&pf, ap);
			// if (format[pf.index] == '%')
			// 	ft_putchar('%'); //index++
			//ft_minus(pf, ap, format[pf.index]);// "%-5.45s\n", "ola"
			// if (ft_strchr(CONVERSION, *format))
			// 	printf("temos conversion\n");
			// if (format[pf.index] == 's')
			// {
			// 	pf.str = va_arg(ap, char *);
			// 	cont3 += ft_strlen(pf.str) - 1; /** cont chars - 1 % **/
			// 	ft_putstr(pf.str);
			// }
			// else if (format[pf.index] == 'd')
			// {
			// 	pf.i = va_arg(ap, int);
			// 	cont++;
			// 	ft_putstr(ft_itoa(pf.i));
			// }
			// else if (format[pf.index] == 'f')
			// {
			// 	pf.d = va_arg(ap, double);
			// 	cont++;
			// 	ft_putstr(ft_ftoa(pf.d));
			// }
			// else if (format[pf.index] == 'c')
			// {
			// 	pf.c = va_arg(ap, int);
			// 	cont++;
			// 	ft_putchar((char)pf.c);
			// }
		}
		else
		{
			ft_putchar(format[pf.index]);
		}
		pf.index++;
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	int c;
	char *flag = "-0.*";
	ft_printf("%*.3s\n",9,"hello world");
	printf("\n");
	c = printf("%*.3s ",9,"hello world");
	printf("%d\n", c);
}