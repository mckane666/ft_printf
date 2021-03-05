#include "ft_printf.h"

int	main(void)
{
	int a;
	int b;

	int c;
	int d;

	int e;
	int f;

	int g;
	int h;
	char *flag = "-0.*";
	printf("\n");
	// a = ft_printf("%p %15p %-15p", -2, -2, -2);
	// b = printf("%p %15p %-15p", -2, -2, -2);
	// printf("\n");
	// printf("\nft_printf = %d\nprintf = %d\n", a, b);

	// c = ft_printf("%p %15p %-15p", 0, 0, 0);
	// d = printf("%p %15p %-15p", 0, 0, 0);
	// printf("\n");
	// printf("\nft_printf = %d\nprintf = %d\n", c, d);

	// e = ft_printf("%p %15p %-15p", 2, 2, 2);
	// f = printf("%p %15p %-15p", 2, 2, 2);
	// printf("\n");
	// printf("\nft_printf = %d\nprintf = %d", e, f);

	g = ft_printf("%*p %*p",20, &flag,-20, &flag);
	h = printf("%*p %*p",20, &flag,-20, &flag);
	printf("\n");
	printf("\nft_printf = %d\nprintf = %d", g, h);
}
	
