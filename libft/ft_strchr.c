/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:43:05 by user              #+#    #+#             */
/*   Updated: 2021/02/16 14:33:06 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strchr() function returns a pointer
** to the first occurrence of the character n in the string s.
*/

char	*ft_strchr(const char *s, int n)
{
	while (*s)
	{
		if (*s == (unsigned char)n)
		{
			return ((char *)s);
		}
		s++;
	}
	if ((*s == 0 && n == 0))
		return ((char *)s);
	return (0);
}
