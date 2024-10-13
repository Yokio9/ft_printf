#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int		printed;

	printed = ft_putstr(ft_utoa(n));
	return (printed);
}
