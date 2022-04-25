#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	printf("|%d|--->\n", ft_printf("%u",  -2147483648));
	printf("|%d|--->\n", printf("%u",  -2147483648));
}
