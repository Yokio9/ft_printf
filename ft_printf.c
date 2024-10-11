#include <stdarg.h>
#include "../libft/libft.h"

void	ft_printf(char *format, ...)
{
	va_list	args;
	int	i;
	int	j;
	int	num_args;
	char *char_ptr;

	i = 0;
	j = 0;
	num_args = 0;
	char_ptr = ft_strdup(format);
	while (char_ptr)
	{
		char_ptr = ft_strchr(char_ptr, '%');
		if (!char_ptr)
			break;
		num_args++;
		char_ptr++;
	}
	va_start(args, format);
	while (i < num_args)
	{
		j = va_arg(args, int);
		ft_putendl_fd(ft_itoa(j), 1);
		i++;
	}
	va_end(args);
}

int main()
{
	int	one = 23;
	int	two = 6;
	int	three = 9;
	ft_printf("%ladbah%adjanb%aefea", one, two, three);
	return 0;
}
