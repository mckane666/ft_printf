/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 14:35:47 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/02/08 08:05:21 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The atoi() function converts the initial portion
** of the string pointed to by str to int.
*/

int	ft_atoi(const char *str)
{
	long int	num;
	int			i;

	num = 0;
	i = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' && (*str++) + 42)
		i *= -1;
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		if ((num * i) > 2147483647)
			return (-1);
		if ((num * i) < -2147483648)
			return (0);
		str++;
	}
	return (num * i);
}
