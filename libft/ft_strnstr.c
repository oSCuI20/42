#include "libft.h"

char	*ft_strnstr(char *str, char *sfind, size_t flen)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (str[i] && sfind[len])
	{
		len = 0;
		while (sfind[len] && str[i + len] == sfind[len])
			len++;
		if (len + i > flen || !str[i + 1])
			return (NULL);
		if (sfind[len])
			i++;
	}
	return (&str[i]);
}
