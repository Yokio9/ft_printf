#include "ft_printf.h"

char	*ft_switch_cases(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' || str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}