/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 10:52:58 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/02/17 21:13:04 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	look(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*new;
	int		len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && look((char)s1[i], set))
		i++;
	while (len > i && look((char)s1[len - 1], set))
		len--;
	new = malloc(sizeof(*s1) * (len - i + 1));
	if (!new)
		return (NULL);
	j = 0;
	while (i < len)
	{
		new[j] = s1[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
