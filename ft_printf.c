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
	int	num;

	i = count_args(form);
	va_start(args, form);
	while (i-- > 0)
	{
		while (*form != '%')
		{
			ft_putchar_fd(*form, 1);
			form++;
		}
		if (*form == '%')
		{
			form++;
			if (*form == 'd' || *form == 'i' || *form == 'u')
			{
				num = va_arg(args, int);
				ft_print_num(*form, num);
				form++;
			}
		}



		/*if (*form == 'c' || *form == '%')
			ft_print_char(*form);
		if (*form == 's')
			ft_print_str(*form);
		if (*form == 'X' || *form == 'x')
			ft_print_hexa(*form);
		if (*form == 'p')
			ft_print_adress(*form); */
	}
	va_end(args);
}

int main()
{
	int	one = 27;
	int	two = 2024;
	ft_printf("j'ai eu %d ans en %d\n", one, two);
	return 0;
}
