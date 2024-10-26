/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatayi <dimatayi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:14:07 by dimatayi          #+#    #+#             */
/*   Updated: 2024/10/26 18:14:43 by dimatayi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	change_n(&n, &sign, &nb);
	digits = ft_digits(nb);
	str = malloc(sizeof(char) * (digits + sign + 1));
	if (!str)
		return (NULL);
	str[digits + sign] = '\0';
	if (sign)
		str[0] = '-';
	else
		digits -= 1;
	while (digits >= sign)
	{
		str[digits--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
