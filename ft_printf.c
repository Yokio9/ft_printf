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
	unsigned int	one = 27;
	unsigned int	two = 58;
	unsigned int	three = 345;
	printf("theirs: %d\n", printf("printf u: %u u: %u u: %u\n", one, two, three));
	ft_printf("mine: %d\n", ft_printf("printf u: %u u: %u u: %u\n", one, two, three));
	return 0;
}