/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:44:28 by jhenriqu          #+#    #+#             */
/*   Updated: 2020/12/06 20:43:17 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_memccpy() function copies no more than n bytes from memory area
** src to memory area dest, stopping when the character c is found.
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((const char *)src)[i];
		if ((char)c == ((char *)src)[i])
		{
			return (&((char *)dest)[i + 1]);
		}
		i++;
	}
	return (0);
}
