/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatayi <dimatayi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:14:32 by dimatayi          #+#    #+#             */
/*   Updated: 2024/10/26 18:14:42 by dimatayi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit_counter(unsigned long long decimal, unsigned int base_amount)
{
	unsigned int	i;

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

char	*ft_utoa_hexa(unsigned int nbr)
{
	char			*str;
	char			*base_digits;
	int				digits;

	base_digits = "0123456789abcdef";
	digits = digit_counter(nbr, 16);
	str = (char *)malloc(digits + 1);
	if (!str)
		return (NULL);
	str[digits] = '\0';
	while (digits > 0)
	{
		str[--digits] = base_digits[nbr % 16];
		nbr /= 16;
	}
	return (str);
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
	while (digits > 0)
	{
		str[--digits] = n % 10 + '0';
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
