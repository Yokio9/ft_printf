#include "ft_printf.h"

int	ft_convert_type(char letter, va_list *args)
{
	int	printed;

	printed = 0;
	if (letter == 'd' || letter == 'i')
		printed += ft_putnbr(va_arg(*args, int));
	if (letter == 'u')
		printed += ft_putunbr(va_arg(*args, int));
	return (printed);
}
