#include "libft.h"

int ft_atoi(char *str)
{
  int n;
  int i;
  int sign;

  i = 0;
  sign = 1;
  while (str[i] == ' ')
    i++;
  if (str[i] == '-')
    sign *= -1;
  while (ft_isdigit(str[++i]))
    n = (n * 10) + str[i] - 48;
  return (n * sign);
}
