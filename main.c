#include "includes/ft_printf.h"

int	main(void)
{
	printf("%.0g\n", -9.999);
	ft_printf("%.0g", -9.999);
	return (0);
}
