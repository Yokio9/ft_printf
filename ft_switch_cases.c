#include "ft_printf.h"

char	*ft_switch_cases(char *str)
{
	int	i;

	i = 0;
	while (((char *)str)[i])
	{
		if (((char *)str)[i] >= 'a' && ((char *)str)[i] <= 'z')
			((char *)str)[i] -= 32;
		i++;
	}
	return (str);
}
