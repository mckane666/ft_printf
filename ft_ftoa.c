/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:53:55 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/02/10 18:55:57 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

/*
char	*ft_ftoa(double n, int prec) // .05 ??precision 0
{
	char *str;
	long long int in;
	double fn;

	in = (long long int)n;
	fn = n - (double)in;
	fn = fn * 100000;
	str = ft_strdup((char *)ft_itoa(in));
	if (prec > 0)
		str = ft_strjoin(str, ".");
		str = ft_strjoin(str, ft_substr((char *)ft_itoa(fn), 0 , prec));
	return (str);
}
*/

char	*ft_ftoa(double n) /* .05 ??precision 0 */
{
	char			*str;
	long long int	in;
	double			fn;

	in = (long long int)n;
	fn = n - (double)in;
	fn = fn * 100000;
	str = ft_strdup((char *)ft_itoa(in));
	str = ft_strjoin(str, ".");
	str = ft_strjoin(str, (char *)ft_itoa(fn));
	return (str);
}

// int main()
// {
// 	printf("%s", ft_ftoa(10.20, 2));
// }
