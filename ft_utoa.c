#include "ft_printf.h"

static int digit_counter(unsigned int decimal, unsigned int base_amount)
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
	base_to = ft_strdup("0123456789abcdef");
	output = decimal_to_hexa(nbr, base_to);
	free(base_to);
	return (output);
}
char	*ft_utoa(unsigned int n)
{
	char			*str;
	int				digits;
	int				i;

	digits = digit_counter(n, 10);
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
