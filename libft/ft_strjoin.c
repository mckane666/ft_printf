/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:48:46 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/02/17 20:56:21 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		t;
	char	*joined;

	if (!s1 || !s2)
		return (0);
	joined = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!joined)
		return (NULL);
	*joined = 0;
	i = 0;
	while (s1[i] != '\0')
	{
		joined[i] = s1[i];
		i++;
	}
	t = 0;
	while (s2[t] != '\0')
	{
		joined[i + t] = s2[t];
		t++;
	}
	joined[i + t] = '\0';
	return (joined);
}
