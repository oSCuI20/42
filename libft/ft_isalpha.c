#include "libft.h"

int	ft_isalpha(int c)
{
	return (
		((c & 0xff) >= 'a' && (c & 0xff) <= 'z')
		|| ((c & 0xff) >= 'A' && (c & 0xff) <= 'Z')
	);
}
