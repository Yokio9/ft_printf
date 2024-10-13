#include "ft_printf.h"

int	ft_printf(char *format, ...)
{
	va_list	args;
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			printed += ft_convert_type(format[++i], &args);
		else
			printed += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (printed);
}

#include <stdio.h>
int main()
{
	int nbr = -42;
	int *nbr1 = &nbr;
	printf("theirs: %d\n", printf("1: %p 2: %p\n", &nbr, nbr1));
	ft_printf("mine: %d\n", ft_printf("1: %p 2: %p\n", &nbr, nbr1));
	return 0;
}