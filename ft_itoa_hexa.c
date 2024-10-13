#include "ft_printf.h"

static int decimal_counter(int decimal, int base_amount)
{
    int i = 0;
    while (decimal > 0)
    {
        decimal /= base_amount;
        i++;
    }
    return (i);
}

static char *decimal_to_hexa(int decimal, char *base_to, int *sign)
{
	int counter;
	int i;

	counter = decimal_counter(decimal, 16);
	i = counter;
	char *output = NULL;
	output = (char *)malloc(sizeof(char) * (counter + *sign + 1));
	if (*sign)
		output[0] = '-';
	i = counter - 1 + *sign;
	while (i >= *sign)
	{
		output[i] = base_to[decimal % 16];
		decimal /= 16;
		i--;
	}
	output[counter + *sign] = '\0';

	return (output);
}

char *ft_itoa_hexa(int nbr)
{
	int sign;
	char *base_to;

	if (nbr == -2147483648)
		return ("-80000000");
	if (nbr == -2147483647)
		return ("-7FFFFFFF");
	if (nbr == 2147483647)
		return ("7FFFFFFF");
	if (nbr < 0)
	{
		sign = 1;
		nbr = -nbr;
	}
	else
		sign = 0;
	base_to = strdup("0123456789ABCDEF");
	char *output = decimal_to_hexa(nbr, base_to, &sign);
	return (output);
}
