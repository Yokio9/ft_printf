#include "ft_printf.h"

static int	ft_digits(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	char			*str;
	int				digits;
	int				i;

	digits = ft_digits(n);
	str = malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	else
		i = digits - 1;
	while (i >= 0)
	{
		str[i--] = n % 10 + '0';
		n /= 10;
	}
	str[digits] = '\0';
	return (str);
}