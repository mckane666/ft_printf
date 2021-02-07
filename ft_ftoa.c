
#include "ft_printf.h"
#include "libft/libft.h"
#include <math.h>

char	*ft_ftoa(double n) // .05 ??precision 0
{
	char *str;
	long long int in;
	double fn;

	in = (long long int)n;
	fn = n - (double)in;
	fn = fn * 100000;
	str = ft_strdup((char *)ft_itoa(in));
	str = ft_strjoin(str, ".");

	str = ft_strjoin(str, (char *)ft_itoa(fn + 1));
	printf("%s", str);
	return (0);
}

int main()
{
	ft_ftoa(10.70);
	printf("\n%.0f", 1.5);
}
