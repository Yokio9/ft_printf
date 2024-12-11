/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatayi <dimatayi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:16:31 by dimatayi          #+#    #+#             */
/*   Updated: 2024/12/11 21:48:09 by dimatayi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

int		ft_printf(const char *form, ...);
int		ft_convert_type(char letter, va_list *args);
char	*ft_utoa(unsigned int n);
int		ft_putnbr_hexa(int n, char type);
char	*ft_itoa_hexa(int nbr);
char	*ft_utoa_hexa(unsigned int nbr);
char	*ft_switch_cases(char *str);
char	*ft_itoa(int n);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
char	*ft_ulltoa_hexa(unsigned long long value, int base);
int		ft_putptr(void *ptr);

#endif
