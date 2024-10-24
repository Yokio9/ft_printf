#include "ft_printf.h"

char	*ft_strdup(const char *src)
{
	char	*dst;

	dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dst)
		return (NULL);
	if (!ft_strlen(src))
		ft_strlcpy(dst, src, 1);
	else
		ft_strlcpy(dst, src, ft_strlen(src) + 1);
	return (dst);
}
