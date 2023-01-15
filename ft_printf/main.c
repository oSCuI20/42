#include "./ft_printf.h"
#include <stdio.h>
#include <limits.h> 

int main(void)
{
	int	i;
	int x;

	i = ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	x = printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	
	printf("ft_printf => %d ; printf => %d\n", i, x);

	i = ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
	x = printf(" %p %p \n", LONG_MIN, LONG_MAX);
	
	printf("ft_printf => %d ; printf => %d\n", i, x);


	i = ft_printf(" %x %x \n", ULONG_MAX, -ULONG_MAX);
	x = printf(" %x %x \n", ULONG_MAX, -ULONG_MAX);
	
	printf("ft_printf => %d ; printf => %d\n", i, x);

	i = ft_printf(" %x %x \n", LONG_MIN, LONG_MAX);
	x = printf(" %x %x \n", LONG_MIN, LONG_MAX);
	
	printf("ft_printf => %d ; printf => %d\n", i, x);
	return (0);
}