#include "ft_printf.h"

static int	get_num_length(unsigned long long value, int base)
{
	int	length;

	length = 0;
	if (value == 0)
		return (1);
	while (value > 0)
	{
		value /= base;
		length++;
	}
	return (length);
}

char	*ft_itoa_base_printf(unsigned long long value, int base)
{
	char			*str;
	char			*base_digits;
	int				length;

	base_digits = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	length = get_num_length(value, base);
	str = (char *)malloc(length + 1);
	if (!str)
		return (NULL);
	str[length] = '\0';
	while (length > 0)
	{
		str[--length] = base_digits[value % base];
		value /= base;
	}
	return (str);
}
