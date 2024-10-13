#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

int	ft_printf(char *form, ...);
int	ft_print_num(char letter, va_list *args);

#endif