#include "ft_printf.h"
#include <stdio.h>

int	ft_print_num(char letter, va_list *args)
{
	int	printed;

	printed = 0;
	if (letter == 'd' || letter == 'i')
		printed += ft_putnbr(va_arg(*args, int));
	return (printed);
}
