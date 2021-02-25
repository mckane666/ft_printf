#include "ft_printf.h"

int	main(void)
{
	int c;
	int d;
	char *flag = "-0.*";
	c = ft_printf("-->%*.*s pastilhas%-15.8s",5,8,"hello world","hey boyzzzz");
	printf("\n");
	d = printf("-->%*.*s pastilhas%-15.8s",5,8,"hello world","hey boyzzzz");
	printf("\n\n");
	printf("ft_printf = %d\nprintf = %d", c, d);
}