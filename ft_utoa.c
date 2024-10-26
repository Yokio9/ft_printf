#include "ft_printf.h"

static int digit_counter(unsigned long long decimal, unsigned int base_amount)
{
	unsigned int i;

	i = 0;
	if (decimal == 0)
		return (1);
	while (decimal > 0)
	{
		decimal /= base_amount;
		i++;
	}
	return (i);
}

static char *decimal_to_hexa(unsigned int decimal, char *base_to)
{
	unsigned int	counter;
	int	i;
	unsigned int	n;
	char			*output;

	counter = digit_counter(decimal, 16);
	output = (char *)malloc(sizeof(char) * (counter + 1));
	if (!output)
		return (NULL);
	n = counter;
	while (n--)
		output[n] = 0;
	i = counter - 1;
	while (i >= 0)
	{
		output[i] = base_to[decimal % 16];
		decimal /= 16;
		i--;
	}
	output[counter] = '\0';
	return (output);
}

char *ft_utoa_hexa(unsigned int nbr)
{
	char *base_to;
	char *output;

	if (nbr == 2147483647)
		return (ft_strdup("7fffffff"));
	base_to = "0123456789abcdef";
	output = decimal_to_hexa(nbr, base_to);
	return (output);
}
char	*ft_utoa(unsigned int n)
{
	char			*str;
	int				digits;

	digits = digit_counter(n, 10);
	str = malloc(sizeof(char) * (digits + 1));
	if (!str)
		return (NULL);
	str[digits] = '\0';
	while (--digits >= 0)
	{
		str[digits] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
char	*ft_ulltoa_hexa(unsigned long long nbr, int base)
{
	char			*str;
	char			*base_digits;
	int				digits;

	base_digits = "0123456789abcdef";
	digits = digit_counter(nbr, base);
	str = (char *)malloc(digits + 1);
	if (!str)
		return (NULL);
	str[digits] = '\0';
	while (digits > 0)
	{
		str[--digits] = base_digits[nbr % base];
		nbr /= base;
	}
	return (str);
}
