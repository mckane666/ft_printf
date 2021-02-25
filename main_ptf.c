#include "ft_printf.h"

int	main(void)
{
	int c;
	int d;
	char *flag = "-0.*";
	// c = ft_printf("-->%*.*s pastilhas%*.*s",5,8,"hello world",-15,8,"hey boyzzzz");
	// printf("\n");
	// d = printf("-->%*.*s pastilhas%*.*s",5,8,"hello world",-15,8,"hey boyzzzz");
	// printf("\n\n");
	// printf("ft_printf = %d\nprintf = %d", c, d);
	c = ft_printf("%1.s", "");
	printf("\n");
	d = printf("%1.s", "");
	printf("\n\n");
	//printf("ft_printf = %d\nprintf = %d", c, d);
	
}