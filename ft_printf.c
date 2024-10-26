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
	int	i;
	int	printed;

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
#include <stdio.h>

int main()
{
	printf("Character: %c", 'A');
	printf("\n");
	printf("String: %s", "Hello, World!");
	printf("\n");
	printf("Pointer: %p", (void *)0x12345678);
	printf("\n");
	printf("Hexadecimal (lowercase): %x", 255);
	printf("\n");
	printf("Hexadecimal (uppercase): %X", 255);
	printf("\n");
	printf("Integer: %d", 42);
	printf("\n");
	printf("Integer: %i", -42);
	printf("\n");
	printf("Unsigned: %u", 42);
	printf("\n");
	printf("Percent: %%");
	printf("\n");
	printf("Multiple: %c %s %p %x %X %d %i %u %%", 'A', "Hello", (void *)0x12345678, 255, 255, 42, -42, 42);
	printf("\n");
	printf("Edge case INT_MAX: %d", INT_MAX);
	printf("\n");
	printf("Edge case INT_MIN: %d", INT_MIN);
	printf("\n");
	printf("Edge case UINT_MAX: %u", UINT_MAX);
	printf("\n");

	ft_printf("mine");
	printf("\n");
	ft_printf("Character: %c", 'A');
	printf("\n");
	ft_printf("String: %s", "Hello, World!");
	printf("\n");
	ft_printf("Pointer: %p", (void *)0x12345678);
	printf("\n");
	ft_printf("Hexadecimal (lowercase): %x", 255);
	printf("\n");
	ft_printf("Hexadecimal (uppercase): %X", 255);
	printf("\n");
	ft_printf("Integer: %d", 42);
	printf("\n");
	ft_printf("Integer: %i", -42);
	printf("\n");
	ft_printf("Unsigned: %u", 42);
	printf("\n");
	ft_printf("Percent: %%");
	printf("\n");

	ft_printf("Multiple: %c %s %p %x %X %d %i %u %%", 'A', "Hello", (void *)0x12345678, 255, 255, 42, -42, 42);

	printf("\n");
	ft_printf("Edge case INT_MAX: %d", INT_MAX);
	printf("\n");
	ft_printf("Edge case INT_MIN: %d", INT_MIN);
	printf("\n");
	ft_printf("Edge case UINT_MAX: %u", UINT_MAX);
	printf("\n");

	return 0;
}

/*
#include <limits.h>
#include <stdio.h>

int main()
{
    printf("Expected: ");
    printf(" %x ", 0);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", 0);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", -1);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", -1);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", 1);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", 1);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", 9);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", 9);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", 10);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", 10);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", 11);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", 11);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", 15);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", 15);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", 16);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", 16);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", 17);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", 17);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", 99);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", 99);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", 100);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", 100);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", 101);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", 101);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", -9);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", -9);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", -10);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", -10);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", -11);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", -11);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", -14);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", -14);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", -15);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", -15);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", -16);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", -16);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", -99);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", -99);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", -100);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", -100);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", -101);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", -101);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", INT_MAX);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", INT_MAX);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", INT_MIN);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", INT_MIN);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", LONG_MAX);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", LONG_MAX);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", LONG_MIN);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", LONG_MIN);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", UINT_MAX);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", UINT_MAX);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", UINT_MAX);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", UINT_MAX);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", ULONG_MAX);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", ULONG_MAX);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", 9223372036854775807LL);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", 9223372036854775807LL);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", 42);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", 42);
    ft_printf("\n");

    printf("Expected: ");
    printf(" %x ", -42);
    printf("\n");
    ft_printf("Actual: ");
    ft_printf(" %x ", -42);
    ft_printf("\n");

    return 0;
}
 */
