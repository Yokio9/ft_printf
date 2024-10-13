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
			printed += ft_print_num(format[++i], &args);
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
	int	one = 27;
	int	two = 58;
	unsigned int three = -345;
	printf("theirs: %d\n", printf("printf d: %d i: %i u: %d\n", one, two, three));
	ft_printf("mine: %d\n", ft_printf("printf d: %d i: %i u: %d\n", one, two, three));
	return 0;
}