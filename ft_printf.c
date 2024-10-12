#include <stdarg.h>
#include "../libft/libft.h"

static void	type_to_print(char *dup_format)
{
	char	*num;
	char	*character;
	char	*hexa;

	num = ft_strdup("diu");
	character = ft_strdup("cs%");
	hexa = ft_strdup("pXx");
	while (*num)
		if (*dup_format == *num++)
			ft_putendl_fd("found a num", 1);
	while (*character)
		if (*dup_format == *character++)
			ft_putendl_fd("found a character", 1);
	while (*hexa)
		if (*dup_format == *hexa++)
			ft_putendl_fd("found an hexa", 1);
}

static int	count_args(char *format)
{
	int	num_args;
	char *dup_format;

	num_args = 0;
	dup_format = ft_strdup(format);
	while (dup_format)
	{
		dup_format = ft_strchr(dup_format, '%');
		if (!dup_format)
			break;
		num_args++;
		dup_format++;
		type_to_print(dup_format);
		if (*dup_format == '%')
			dup_format++;
	}
	return (num_args);
}

void	ft_printf(char *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = count_args(format);
	j = 0;
	va_start(args, format);
	while (i-- > 0)
	{
		j = va_arg(args, int);
		ft_putendl_fd(ft_itoa(j), 1);
	}
	va_end(args);
}

int main()
{
	int	one = 23;
	int	two = 6;
	int	three = 9;
	ft_printf("%dla%iaj%uef%ckjb%slkb%%bu%pkljbh%Xoizvb%xdf", one, two, three, one, two, three, one, two, three);
	return 0;
}
