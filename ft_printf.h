/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 22:11:43 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/02/04 19:08:36 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
#include <string.h>

#define CONVERSIONS "cspdiuxX%"
#define FLAGS "-0.*"

/*
** 1st part
*/
char	*ft_ftoa(double n);
int	ft_printf(const char *format, ...);

/*
** bonus part
*/


#endif
