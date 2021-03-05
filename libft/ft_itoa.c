/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 20:17:09 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/02/08 14:13:24 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The itoa() function converts int to string.
*/

int	str_alloc_mem(char **str, int n, int count)
{
	while (n / 10)
	{
		n = n / 10;
		count++;
	}
	*str = malloc(sizeof(char) * count);
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			count;
	long long	ln;

	count = 1;
	ln = n;
	count = str_alloc_mem(&str, n, count);
	if (!(str))
		return (NULL);
	if (ln == 0)
		str[0] = '0';
	if (ln < 0)
	{
		str[0] = '-';
		ln = ln * -1;
		count++;
	}
	str[count] = '\0';
	while (ln > 0)
	{
		str[--count] = ln % 10 + '0';
		ln = ln / 10;
	}
	return (str);
}
