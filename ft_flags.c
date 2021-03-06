/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:30:44 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/03/01 11:41:41 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversions(t_printf *pf, va_list ap)
{
	if (ft_strchr("c", pf->get_args[pf->index]))
		ft_is_c(pf, ap);
	else if (ft_strchr("s", pf->get_args[pf->index]))
		ft_is_str(pf, ap);
	else if (ft_strchr("p", pf->get_args[pf->index])) //
		ft_is_p(pf, ap);
	// else if (ft_strchr("d", pf->get_args[pf->index])) //
	// 	ft_is_d(pf, ap);
	// else if (ft_strchr("i", pf->get_args[pf->index])) //
	// 	ft_is_i(pf, ap);
	// else if (ft_strchr("u", pf->get_args[pf->index])) //
	// 	ft_is_u(pf, ap);
	else if (ft_strchr("x", pf->get_args[pf->index])) //
	 	ft_is_x(pf, ap);
	// else if (ft_strchr("X", pf->get_args[pf->index])) //
	// 	ft_is_X(pf, ap);
	else if (ft_strchr("%", pf->get_args[pf->index])) //
	 	ft_is_percent(pf);
}

void	ft_is_str(t_printf *pf, va_list ap)
{
	if (pf->get_args[pf->index] == 's')
		pf->str = va_arg(ap, char *);
	if (!pf->str)
		pf->str = "(null)";
	pf->str_len += ft_strlen(pf->str);
	if (((pf->width || !pf->width) && pf->precision < 0) || (!pf->point)) //
		pf->precision = pf->str_len;
	pf->retu = ft_calloc(sizeof(char), pf->str_len + pf->width + pf->point + 1 + pf->ast);
	while ((pf->str[pf->j] && pf->j < pf->precision) && pf->minus)
		pf->retu[pf->k++] = pf->str[pf->j++];
	while (pf->width-- > pf->precision - ((pf->precision > pf->str_len))
		|| (pf->str_len - pf->point++ < (pf->width--)))
		pf->retu[pf->k++] = ' ';
	while ((pf->str[pf->j] && pf->j < pf->precision) && !pf->minus)
		pf->retu[pf->k++] = pf->str[pf->j++];
	pf->retu[pf->k] = 0;
	pf->cont += ft_strlen(pf->retu);
	ft_putstr(pf->retu);
	ft_init_printf_flags(pf);
	free(pf->retu);
}

void	ft_is_c(t_printf *pf, va_list ap)
{
	if (pf->get_args[pf->index] == 'c')
		pf->c = va_arg(ap, int);
	if (pf->width)
	{
		pf->retu = ft_calloc(sizeof(char), pf->width + 1);
		pf->cont += pf->width;
		if (pf->minus)
			write(1, &pf->c,1);
		while (--pf->width)
			write(1, " ",1);
		if (!pf->minus)
			write(1, &pf->c,1);
		pf->retu[pf->k++] = 0;
		ft_putstr(pf->retu);
		ft_init_printf_flags(pf);
		free(pf->retu);
	}
	else
	{
		ft_putchar(pf->c);
		pf->cont += pf->width + 1;
		ft_init_printf_flags(pf);
	}
}

void	ft_is_percent(t_printf *pf)
{
	if (pf->sign)
		ft_putchar('%');
	else if (pf->width)
	{
		pf->retu = ft_calloc(sizeof(char), pf->width + 1);
		if (pf->minus)
		{
			pf->retu[pf->k++] = '%';
			pf->zero = 0;
		}
		while (--pf->width)
			pf->retu[pf->k++] = ZERO_NO[pf->zero];
		if (!pf->minus)
			pf->retu[pf->k++] = '%';
		pf->retu[pf->k++] = 0;
		ft_putstr(pf->retu);
		ft_init_printf_flags(pf);
		free(pf->retu);
	}
	pf->cont += pf->width + 1;
}

void	ft_hexa(unsigned long n, t_printf *pf)
{
	int i;
    unsigned long nn;

	i = 1;
    nn = n;
	if (!n)
		pf->str = "0";
	else
	{
		while (nn/=16)
			++i;
		pf->str = ft_calloc(sizeof(char), i + 1);
		pf->str[i] = 0;
		while (n)
		{
			if (!pf->lower)
				pf->str[--i] = HEXAB[n % 16];
			else
				pf->str[--i] = HEXA[n % 16];
			n/=16;
		}
	}
}

void	ft_is_p(t_printf *pf, va_list ap)
{
	if (pf->get_args[pf->index] == 'p')
		pf->p = va_arg(ap, unsigned long);
	ft_hexa(pf->p, pf);
	pf->str_len = ft_strlen(pf->str) + 1;
	pf->retu = ft_strjoin("0x", pf->str);
	pf->cont += pf->width + pf->str_len + 1;
	while (--pf->width > pf->k + pf->str_len && !pf->minus)
		write(1, " ",1);
	ft_putstr(pf->retu);
	while (--pf->width >= pf->k + pf->str_len && pf->minus)
	 	write(1, " ",1);
	pf->cont -= pf->width - pf->k + 2;
	free(pf->str);
	ft_init_printf_flags(pf);
	free(pf->retu);
}

void	ft_is_x(t_printf *pf, va_list ap)
{
	pf->lower = 1;
	if (pf->get_args[pf->index] == 'x')
		pf->x = va_arg(ap, unsigned long);
	ft_hexa(pf->x, pf);
	pf->str_len += ft_strlen(pf->str);
	if (((pf->width || !pf->width) && pf->precision < 0) || (!pf->point))
		pf->precision = pf->str_len;
	pf->retu = ft_calloc(sizeof(char), pf->str_len + pf->width + pf->point + 1 + pf->ast);
	while ((pf->str[pf->j] && pf->j < pf->precision) && pf->minus)
		pf->retu[pf->k++] = pf->str[pf->j++];
	while (pf->width-- > pf->precision - ((pf->precision > pf->str_len))
		|| (pf->str_len - pf->point++ < (pf->width--)))
		pf->retu[pf->k++] = ' ';
	while ((pf->str[pf->j] && pf->j < pf->precision) && !pf->minus)
		pf->retu[pf->k++] = pf->str[pf->j++];
	pf->retu[pf->k] = 0;
	pf->cont += ft_strlen(pf->retu);
	ft_putstr(pf->retu);
	ft_init_printf_flags(pf);
	free(pf->retu);
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
}*/