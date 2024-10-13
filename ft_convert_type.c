#include "ft_printf.h"

int	ft_convert_type(char letter, va_list *args)
{
	int	printed;

	printed = 0;
	if (letter == 'c')
		printed += ft_putchar(va_arg(*args, int));
	if (letter == 's')
		printed += ft_putstr(va_arg(*args, char *));
	if (letter == 'd' || letter == 'i')
		printed += ft_putnbr(va_arg(*args, int));
	if (letter == 'u')
		printed += ft_putunbr(va_arg(*args, unsigned int));
	if (letter == '%')
		printed += ft_putchar('%');
	return (printed);
}
