#include "libft.h"

void  *ft_memchr(void *str, int c, size_t len)
{
  size_t  i;
  unsigned char *s;

  s = str;
  i = 0;
  while (i < len)
  {
    if ((s[i] & 0xff) == (c & 0xff))
      return ((void *)&s[i]);
    i++;
  }
  return (NULL);
}
