/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:56:33 by jhenriqu          #+#    #+#             */
/*   Updated: 2020/12/16 18:12:20 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strlcpy() function copy strings.
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	if (!dest || !src)
		return (0);
	while (src[len])
		len++;
	if (size == 0)
		return (len);
	i = 0;
	while (src[i] != 0 && i < size - 1)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = 0;
	return (len);
}
