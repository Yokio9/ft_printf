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
	char one = 'c';
	//char two = '%';
	char *three = "hello";
	printf("theirs: %d\n", printf("c: %c percentage: %% s: %s\n", one, three));
	ft_printf("mine: %d\n", ft_printf("c: %c percentage: %% s: %s\n", one, three));
	return 0;
}