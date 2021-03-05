/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:04:35 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/02/14 21:46:37 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strrchr() function returns a pointer
** to the last occurrence of the character n in the string s.
*/

char	*ft_strrchr(const char *s, int n)
{
	char	*last;

	last = 0;
	while (*s)
	{
		if (*s == (char)n)
		{
			last = ((char *)s);
		}
		s++;
	}
	if (*s == 0 && n == 0)
		return ((char *)s);
	return (last);
}
