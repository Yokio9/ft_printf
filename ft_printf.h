#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_printf(const char *form, ...);
int		ft_convert_type(char letter, va_list *args);
char	*ft_utoa(unsigned int n);
int		ft_putnbr_hexa(int n, char type);
char	*ft_itoa_hexa(int nbr);
char	*ft_utoa_hexa(unsigned int nbr);
char	*ft_switch_cases(char *str);
int		ft_putchar(char c);
int		ft_putstr(char *str);
char	*ft_strdup(const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
char	*ft_itoa_base_printf(unsigned long long value, int base);
int		ft_putptr(void *ptr);

#endif
