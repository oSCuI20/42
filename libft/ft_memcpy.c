#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t	i;
	unsigned char *cdst;
	const unsigned char *csrc;

	cdst = dst;
	csrc = src;
	if (len > 0 && src != dst)
	{
		i = 0;
		while (i < len)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	return (dst);
}
