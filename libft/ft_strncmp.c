#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t len)
{
	size_t i;

  i = 0;
  while (i < len)
  {
    if ((s1[i] & 0xff) != (s2[i] & 0xff))
      return ((s1[i] & 0xff) - (s2[i] & 0xff));
    i++;
  }
  return (0);
}
