/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:30:28 by jhenriqu          #+#    #+#             */
/*   Updated: 2021/02/10 18:52:58 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*ft_whitestaces(char *str, char flag, int n)
{
	char *temp;
	int i;
	int j;

	i = 0;
	j = 0;
	if (ft_strlen(str) < n)
	{
		temp = ft_calloc(sizeof(char), ft_strlen(str) + n + 1);
		while (str[j] && (ft_strchr(FLAGS, flag)))
			temp[i++] = str[j++];
		while (n-- > ft_strlen(str))
			temp[i++] = 'i';
		while (str[j] && (!ft_strchr(FLAGS, flag)))
			temp[i++] = str[j++];
		temp[i] = 0;
	}
	else
		return (str);
	return (temp);
}

int	ft_printf(const char *format, ...) /** "qualquer coisa %s",...
%[flags][width][.precision][size]type **/
{
	va_list	ap;
	int		i; //struct??
	double	d;
	int		cont;
	int		cont2;
	int		cont3;
	int		c;
	char	*s;
	char	*get_args;

	cont = 0;
	cont2 = 0;
	cont3 = 0;
	va_start(ap, *format);
	while (*format != '\0')
	{
		if (*format == '%') /** conta os % **/
		{
			format++;
			get_args = ft_strdup((char *)&*format);
			cont2++;
			if (*format == '%')
				ft_putchar('%');
			// if (ft_strchr(FLAGS, *format))
			// 	printf("temos flag\n");
			// if (ft_strchr(CONVERSION, *format))
			// 	printf("temos conversion\n");
			if (*format == 's')
			{
				s = va_arg(ap, char *);
				cont3 += ft_strlen(s) - 1; /** cont chars - 1 % **/
				ft_putstr(s);
			}
			else if (*format == 'd')
			{
				i = va_arg(ap, int);
				cont++;
				ft_putstr(ft_itoa(i));
			}
			else if (*format == 'f')
			{
				d = va_arg(ap, double);
				cont++;
				ft_putstr(ft_ftoa(d));
			}
			else if (*format == 'c')
			{
				c = va_arg(ap, int);
				cont++;
				ft_putchar((char)c);
			}
		}
		// else
		// {
		// 	ft_putchar(*format);
		// 	cont3++;
		// }
		format++;
	}
	va_end(ap);
	printf("\n->%s\n", get_args);
	return (cont3);
}

int	main(void)
{
	char *flag = "-0.*"; 
	printf("%s\n", ft_whitestaces("ola",flag[0], 5));
	printf("%s\n", ft_whitestaces("ola",'+', 2));
	//ft_whitestaces("ola","+", 5);
	ft_printf("%-0.5f#*s\n", "ola");
	//ft_printf("%-0.5f#*s%.5f*1c\n\n", "ola", 'c');
	// ft_printf("--> %s\n--> %c\n", "ola", 'c');
	// ft_printf("ola\n");
	// ft_printf("%%");
	// ft_printf("\n\n%d %c %f %f\n", 3, 'a', 1.999, 4.25);
	// ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~','');
	// ft_printf("%c%c%c%c%c%c\n",(char)1,(char)2,(char)3,(char)4,(char)5,(char)10);
	// ft_printf("hello, %s.\n", "gavin");
	// int i = ft_printf("%s len-->", "ola mundo");
	// ft_printf("%d\n", i);
	// int j = printf("%s len-->", "ola mundo");
	// printf("%d", j);
}
