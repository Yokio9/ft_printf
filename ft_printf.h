#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include "libft/libft.h"

int		ft_printf(char *form, ...);
int		ft_convert_type(char letter, va_list *args);
int		ft_putunbr(unsigned int n);
char	*ft_utoa(unsigned int n);
int		ft_putnbr_hexa(int n);
char	*ft_itoa_hexa(int nbr);

#endif