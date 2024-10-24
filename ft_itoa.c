#include "ft_printf.h"

static void	change_n(int *n, int *sign, unsigned int *nb)
{
	if (*n < 0)
	{
		*sign = 1;
		*nb = -(*n);
	}
	else
	{
		*nb = *n;
		*sign = 0;
	}
}

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

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*str;
	int				digits;
	int				sign;
	int				i;

	change_n(&n, &sign, &nb);
	digits = ft_digits(nb);
	str = malloc(sizeof(char) * (digits + sign + 1));
	if (!str)
		return (NULL);
	if (sign)
	{
		str[0] = '-';
		i = digits;
	}
	else
		i = digits - 1;
	while (i >= sign)
	{
		str[i--] = nb % 10 + '0';
		nb /= 10;
	}
	str[digits + sign] = '\0';
	return (str);
}
