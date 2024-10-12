#include "ft_printf.h"

static int	count_args(char *form)
{
	int	num_args;

	num_args = 0;
	while (form)
	{
		form = ft_strchr(form, '%');
		if (!form)
			break;
		num_args++;
		form++;
		if (*form == '%')
			form++;
	}
	return (num_args);
}

void	ft_printf(char *form, ...)
{
	va_list	args;
	int	i;
	int	printed;

	i = 0;
	printed = 0;
	va_start(args, form);
	while (form[i])
	{
		if (form[i] == '%')
		{
			i++;
			printed += ft_print_num(form[i], &args);
		}
		else
			printed += ft_putchar_fd(form[i], 1);
		i++;
	}
	va_end(args);
}

#include <stdio.h>
int main()
{
	int	one = 27;
	int	two = 58;
	unsigned int three = -345;
	ft_printf("d: %d i: %i u: %d\n", one, two, three);
	printf("d: %d i: %i u: %d\n", one, two, three);
	return 0;
}