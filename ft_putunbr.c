#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	char	nbr;
	int		printed;

	printed = (int)ft_strlen(ft_utoa(n));
	if (n == 4294967295)
	{
		write(1, "4294967295", 10);
		return (10);
	}
	if (n > 9)
		ft_putunbr(n / 10);
	nbr = (n % 10) + '0';
	write(1, &nbr, 1);
	return (printed);
}
