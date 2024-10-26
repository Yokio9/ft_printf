#include "ft_printf.h"

char	*ft_switch_cases(char *str)
{
	int	i;

	i = 0;
	while (((char *)str)[i])
	{
		if (((char *)str)[i] >= 'a' && ((char *)str)[i] <= 'z')
			((char *)str)[i] -= 32;
		i++;
	}
	return (str);
}

int	ft_putnbr_hexa(int n, char type)
{
	int		printed;
	char	*hexa;

	printed = 0;
	hexa = ft_utoa_hexa(n);
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
int	ft_putunbr(unsigned int n)
{
	int		printed;
	char	*s;

	s = ft_utoa(n);
	printed = ft_putstr(s);
	free(s);
	return (printed);
}

int	ft_putnbr(int n)
{
	int		printed;
	char	*s;

	s = ft_itoa(n);
	printed = ft_putstr(s);
	free(s);
	return (printed);
}
