#include "./ft_printf.h"
#include <stdio.h>
#include <limits.h> 

int main(void)
{
	int	i;
	int x;

	i = ft_printf("ft_printf %p %p \n", ULONG_MAX, -ULONG_MAX);
	x = printf("printf    %p %p \n", ULONG_MAX, -ULONG_MAX);

	printf("ft_printf => %d ; printf => %d\n\n", i, x);

	i = ft_printf("ft_printf %p %p \n", LONG_MIN, LONG_MAX);
	x = printf("printf    %p %p \n", LONG_MIN, LONG_MAX);

	printf("ft_printf => %d ; printf => %d\n\n", i, x);

	i = ft_printf("ft_printf %x %x \n", ULONG_MAX, -ULONG_MAX);
	x = printf("printf    %x %x \n", ULONG_MAX, -ULONG_MAX);

	printf("ft_printf => %d ; printf => %d\n\n", i, x);

	i = ft_printf("ft_printf %x %x \n", LONG_MIN, LONG_MAX);
	x = printf("printf    %x %x \n", LONG_MIN, LONG_MAX);

	printf("ft_printf => %d ; printf => %d\n\n", i, x);

	i = ft_printf("ft_printf %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	x = printf("printf    %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("ft_printf => %d ; printf => %d\n\n", i, x);

	//i = ft_printf("ft_printf %% %c d\n", 'A');
	i = ft_printf("ft_printf %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	x = printf("printf    %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	return (0);
}