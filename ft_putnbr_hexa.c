#include "ft_printf.h"

int	ft_putnbr_hexa(int n, char type)
{
	int		printed;
	char	*hexa;

	printed = 0;
	hexa = ft_strdup(ft_utoa_hexa(n));
	if (!hexa)
		return (0);
	if (type == 'X')
		hexa = ft_switch_cases(hexa);
	printed += ft_putstr(hexa);
	free(hexa);
	return (printed);
}
int	ft_putptr(void *ptr)
{
	int		printed;
	char	*hexa;

	printed = 0;
	hexa = ft_itoa_base_printf((unsigned long long)ptr, 16);
	if (!hexa)
		return (0);
	printed += ft_putstr("0x");
	printed += ft_putstr(hexa);
	free(hexa);
	return (printed);
}
