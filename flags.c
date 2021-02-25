/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:30:44 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/02/22 10:30:57 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_minus(t_printf *pf, va_list ap)
{
	char *temp;
	int i;
	int j;

	i = 0;
	j = 0;
	if (pf->get_args[pf->index] == 's') //mover para funcoes!!
		pf->str = va_arg(ap, char *);
	pf->str_len = ft_strlen(pf->str);
	if (!pf->precision)
		pf->precision = pf->str_len;
	temp = ft_calloc(sizeof(char), pf->width + pf->precision + 1);
	while ((pf->str[j] && j < pf->precision) && (pf->minus))
		temp[i++] = pf->str[j++];
	while (pf->width-- > pf->precision)
		temp[i++] = 'i'; //
	while ((pf->str[j] && j < pf->precision) && (!pf->minus))
			temp[i++] = pf->str[j++];
	temp[i] = 0;
	pf->cont = ft_strlen(temp) + 1;
	printf("%s", temp);
	printf(" %d", pf->cont);
	free(temp);
}