/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:24:57 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/02/17 21:20:54 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	long int	l;

	l = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		l = -l;
	}
	if (nb / 10)
	{
		ft_putnbr(l / 10);
	}
	ft_putchar(l % 10 + '0');
}
