/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 22:11:43 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/02/15 16:34:28 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
#include <string.h>
#include "libft/libft.h"

#define CONVERSIONS "cspdiuxX%"
#define FLAGS "-0.*"
#define WIDTH "0123456789"
#define SIZE "0123456789"
#define SPECIFIERS "-0.*0123456789"

/*
** 1st part
*/

typedef struct  s_printf
{
    int i;
    double d;
    int u;
    int x;
    char c;
    char *str;
    int str_len;
    char *get_args;
    char *retu;
    int index;

    int cont;
    int zero;
    int ast;
    int point;
    int width;
    int minus;
    int precision;
}               t_printf;


char	*ft_ftoa(double n);
int    ft_printf(const char *fmt, ...);
void	ft_is_str(t_printf *pf, va_list ap);
void	ft_init_printf_flags(t_printf *pf);
/*
** bonus part
*/


#endif
