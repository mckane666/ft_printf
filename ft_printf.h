/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 22:11:43 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/02/25 00:37:54 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"

# define CONVERSIONS "cspdiuxX%"
# define FLAGS "-0.*"
# define WIDTH "0123456789"
# define SIZE "0123456789"
# define SPECIFIERS "-0.*0123456789"
# define ZERO_NO " 0"
# define HEXA "0123456789abcdef"

/*
** 1st part
*/

typedef struct	s_printf
{
	int					i;
	double				d;
	int					u;
	int					x;
	char				c;
	long				p;
	char				*str;
	int					str_len;
	char				*get_args;
	char				*retu;
	int					index;
	int					sign;

	int					cont;
	int					zero;
	int					ast;
	int					point;
	int					width;
	int					minus;
	int					precision;
}				t_printf;

char			*ft_ftoa(double n);
void			ft_hexa(unsigned long n, t_printf *pf);
int				ft_printf(const char *fmt, ...);
void			ft_is_str(t_printf *pf, va_list ap);
void			ft_is_c(t_printf *pf, va_list ap);
void			ft_is_i(t_printf *pf, va_list ap);
void			ft_is_p(t_printf *pf, va_list ap);
void			ft_is_percent(t_printf *pf);
void			ft_is_d(t_printf *pf, va_list ap);
void			ft_is_c(t_printf *pf, va_list ap);
void			ft_init_printf_flags(t_printf *pf);
void			ft_conversions(t_printf *pf, va_list ap);
/*
** bonus part
*/

#endif
