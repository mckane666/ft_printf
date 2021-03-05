/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:33:12 by jhenriqu          #+#    #+#             */
/*   Updated: 2020/12/16 15:36:21 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_memchr() function scans the initial n bytes of the
** memory area pointed to by s for the first instance of c.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*us;
	size_t			i;

	uc = c;
	us = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (us[i] == uc)
		{
			return (&us[i]);
		}
		i++;
	}
	return (0);
}
