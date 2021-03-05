/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:55:57 by jhenriqu          #+#    #+#             */
/*   Updated: 2020/12/06 20:43:48 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strlcat() function appends the NUL-terminated string
** src to the end of dst.  It will append at most size - strlen(dst) - 1.
*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int			i;
	size_t		d;
	size_t		s;

	i = 0;
	d = ft_strlen(dest);
	s = ft_strlen(src);
	if (size == 0)
	{
		return (s);
	}
	if (size < d)
	{
		return (s + size);
	}
	while (src[i] && d + 1 + i < size)
	{
		dest[d + i] = src[i];
		i++;
	}
	dest[d + i] = '\0';
	return (d + s);
}
