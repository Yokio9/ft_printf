#include "ft_printf.h"

static int decimal_counter(unsigned int decimal, unsigned int base_amount)
{
	unsigned int i;

	i = 0;
	while (decimal > 0)
	{
		decimal /= base_amount;
		i++;
	}
	return (i);
}

static char *decimal_to_hexa(unsigned int decimal, char *base_to)
{
	unsigned int counter;
	unsigned int i;

	counter = decimal_counter(decimal, 16);
	char *output = NULL;
	output = (char *)malloc(sizeof(char) * (counter));
	if (!output)
		return (NULL);
	i = counter - 1;
	while (i > 0)
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
		return ("7FFFFFFF");
	base_to = ft_strdup("0123456789ABCDEF");
	output = decimal_to_hexa(nbr, base_to);
	return (output);
}
