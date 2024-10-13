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
	unsigned int x = 255;

	printf("real: %d\n", (printf("Hex (lower): %x, Hex (upper): %X\n", x, x)));
	ft_printf("real: %d\n", (ft_printf("Hex (lower): %x, Hex (upper): %X\n", x, x)));

	return 0;
}