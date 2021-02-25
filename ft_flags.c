/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:30:44 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/02/25 00:11:09 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversions(t_printf *pf, va_list ap)
{
	if (ft_strchr("c", pf->get_args[pf->index]))
		;//ft_is_c(pf, ap);
	else if (ft_strchr("s", pf->get_args[pf->index]))
		ft_is_str(pf, ap);
	else if (ft_strchr("p", pf->get_args[pf->index])) //
		;//ft_is_p(pf, ap);
	else if (ft_strchr("d", pf->get_args[pf->index])) //
		;//ft_is_p(pf, ap);
	else if (ft_strchr("i", pf->get_args[pf->index])) //
		;//ft_is_p(pf, ap);
	else if (ft_strchr("u", pf->get_args[pf->index])) //
		;//ft_is_p(pf, ap);
	else if (ft_strchr("x", pf->get_args[pf->index])) //
		;//ft_is_p(pf, ap);
	else if (ft_strchr("X", pf->get_args[pf->index])) //
		;//ft_is_p(pf, ap);
	else if (ft_strchr("%", pf->get_args[pf->index])) //
		;//ft_is_p(pf, ap);
}

void	ft_is_str(t_printf *pf, va_list ap)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (pf->get_args[pf->index] == 's')
		pf->str = va_arg(ap, char *);
	pf->str_len = ft_strlen(pf->str);
	if (!pf->precision || (pf->precision < 0))
		pf->precision = pf->str_len;
	pf->retu = ft_calloc(sizeof(char), pf->width + pf->precision + 1);
	while ((pf->str[j] && j < pf->precision) && pf->minus)
		pf->retu[i++] = pf->str[j++];
	while (pf->width-- > pf->precision
		|| pf->str_len - pf->point < pf->width--)
		pf->retu[i++] = 'i';
	while ((pf->str[j] && j < pf->precision) && !pf->minus)
		pf->retu[i++] = pf->str[j++];
	pf->retu[i] = 0;
	pf->cont += ft_strlen(pf->retu);
	ft_putstr(pf->retu);
	free(pf->retu);
	ft_init_printf_flags(pf);
}

/*
ft_minus(pf, ap, format[pf.index]);// "%-5.45s\n", "ola"
if (ft_strchr(CONVERSION, *format))
	printf("temos conversion\n");
if (format[pf.index] == 's')
{
	pf.str = va_arg(ap, char *);
	cont3 += ft_strlen(pf.str) - 1; //cont chars - 1 %
	ft_putstr(pf.str);
}
else if (format[pf.index] == 'd')
{
	pf.i = va_arg(ap, int);
	cont++;
	ft_putstr(ft_itoa(pf.i));
}
else if (format[pf.index] == 'f')
{
	pf.d = va_arg(ap, double);
	cont++;
	ft_putstr(ft_ftoa(pf.d));
}
else if (format[pf.index] == 'c')
{
	pf.c = va_arg(ap, int);
	cont++;
	ft_putchar((char)pf.c);
}*/
