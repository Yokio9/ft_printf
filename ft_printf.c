/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatayi <dimatayi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:17:37 by dimatayi          #+#    #+#             */
/*   Updated: 2024/10/26 18:17:38 by dimatayi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_type(char letter, va_list *args)
{
	int	printed;

	printed = 0;
	if (letter == 'c')
		printed += ft_putchar(va_arg(*args, int));
	if (letter == 's')
		printed += ft_putstr(va_arg(*args, char *));
	if (letter == 'p')
		printed += ft_putptr(va_arg(*args, void *));
	if (letter == 'x' || letter == 'X')
		printed += ft_putnbr_hexa(va_arg(*args, int), letter);
	if (letter == 'd' || letter == 'i')
		printed += ft_putnbr(va_arg(*args, int));
	if (letter == 'u')
		printed += ft_putunbr(va_arg(*args, unsigned int));
	if (letter == '%')
		printed += ft_putchar('%');
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed;

	i = 0;
	printed = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			printed += ft_convert_type(format[++i], &args);
		else
			printed += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (printed);
}
