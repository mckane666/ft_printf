/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:04:53 by jhenriqu          #+#    #+#             */
/*   Updated: 2020/11/10 11:21:07 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The  ft_strdup() function returns a pointer to a new string
** which is a duplicate of the string src.
*/

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*copy;

	i = 0;
	while (src[i] != 0)
	{
		i++;
	}
	copy = (char*)malloc(sizeof(char) * (i + 1));
	if (!copy)
	{
		return (0);
	}
	j = 0;
	while (src[j] != 0)
	{
		copy[j] = src[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}
