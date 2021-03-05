/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 09:45:39 by tisantos          #+#    #+#             */
/*   Updated: 2021/02/17 20:57:50 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int		i;
	int					source;
	int					destination;

	i = 0;
	destination = 0;
	source = 0;
	while (dest[destination] != '\0')
	{
		destination++;
	}
	while (i < nb && src[source] != '\0')
	{
		dest[destination] = src[source];
		i++;
		destination++;
		source++;
	}
	dest[destination] = '\0';
	return (dest);
}
