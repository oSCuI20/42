#include "libft.h"
#include <string.h>
#include <stdio.h>

void *ft_memmove(void *dst, const void *src, size_t len)
{
  return ft_memcpy(dst, src, len);
}
