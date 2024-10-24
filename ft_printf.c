#include "ft_printf.h"

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

/*     printf("Expected: ");
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
    ft_printf("\n"); */

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
