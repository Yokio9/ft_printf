#include "ft_printf.h"

int	ft_putnbr_hexa(int n, char type)
{
	int		printed;
	char	*hexa;

	printed = 0;
	hexa = ft_utoa_hexa(n);
	if (type == 'x')
		hexa = ft_switch_cases(hexa);
	if (type == 'p')
		printed += ft_putstr("0x");
	printed += ft_putstr(hexa);
	free(hexa);
	return (printed);
}
