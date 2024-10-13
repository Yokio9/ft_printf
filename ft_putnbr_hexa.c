#include "ft_printf.h"

int	ft_putnbr_hexa(int n)
{
	int		printed;
	char	*hexa;

	printed = 0;
	hexa = ft_itoa_hexa(n);
	printed += ft_putstr("0x");
	printed += ft_putstr(hexa);
	return (printed);
}