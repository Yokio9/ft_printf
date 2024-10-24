#include "ft_printf.h"

int	ft_printf(const char *format, ...)
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

#include <limits.h>
#include <stdio.h>
int main()
{
	printf("real: %x ", -9);
	ft_printf("mine: %x ", -9);

	return 0;
}

