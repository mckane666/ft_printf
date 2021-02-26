/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:30:28 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/02/25 00:45:27 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_printf_flags(t_printf *pf)
{
	pf->point = 0;
	pf->minus = 0;
	pf->ast = 0;
	pf->zero = 0;
	pf->str_len = 0;
	pf->width = 0;
	pf->precision = 0;
}

void	ft_save_ast(t_printf *pf, va_list ap)
{
	pf->ast = 1;
	if (ft_strchr(".", pf->get_args[pf->index - 1]))
		pf->precision = va_arg(ap, int);
	else
	{
		pf->width = va_arg(ap, int);
		if (pf->width < 0)
		{
			pf->width = pf->width * -1;
			pf->minus = 1;
		}
	}
}

void	ft_flags(t_printf *pf, va_list ap)
{
	while (!ft_strchr(CONVERSIONS, pf->get_args[pf->index]))
	{
		if (ft_strchr("-", pf->get_args[pf->index]))
			pf->minus = 1;
		else if (ft_strchr(".", pf->get_args[pf->index]))
		{
			if (!ft_strchr(WIDTH, pf->get_args[pf->index + 1]))
			{
				pf->precision = 0;
				pf->zero = 1;
			}
			pf->point = 1;
		}
		else if (ft_strchr("*", pf->get_args[pf->index]))
			ft_save_ast(pf, ap);
		else if (ft_strchr("0", pf->get_args[pf->index]))
			pf->zero = 1;
		else if (ft_strchr(WIDTH, pf->get_args[pf->index])
				&& pf->width <= 0 && !pf->point)
			pf->width = ft_atoi(&pf->get_args[pf->index]);
		else if (ft_strchr(WIDTH, pf->get_args[pf->index]) && pf->point)
			pf->precision = ft_atoi(&pf->get_args[pf->index]);
		pf->index++;
	}
	//printf("\nPreci = %d sign = %d widht = %d index = %d minus = %d point = %d zero = %d ast = %d\n", pf->precision,pf->sign, pf->width, pf->index, pf->minus, pf->point, pf->zero, pf->ast);
}

void	ft_parse(t_printf *pf, va_list ap)
{
	if (ft_strchr(SPECIFIERS, pf->get_args[pf->index]))
		ft_flags(pf, ap);
	if (ft_strchr(CONVERSIONS, pf->get_args[pf->index]))
		ft_conversions(pf, ap);
}

int		ft_printf(const char *format, ...)
{
	t_printf	pf;
	va_list		ap;

	ft_init_printf_flags(&pf);
	pf.index = 0;
	pf.cont = 0;
	pf.get_args = (char *)format;
	va_start(ap, format);
	while (format[pf.index] != '\0')
	{
		// if (format[pf.index] == '%')
		// {
		// 	pf.index++;
		// 	if (format[pf.index] == '%')
		// 		ft_putchar('%');
		// 	else
		// 		ft_parse(&pf, ap);

		if (format[pf.index] == '%')
		{
			if (format[++pf.index] == '%')
				pf.sign = 1;
			ft_parse(&pf, ap);
		}
		else
		{
			ft_putchar(format[pf.index]);
			pf.cont++;
		}
		pf.index++;
	}
	va_end(ap);
	return (pf.cont);
}
