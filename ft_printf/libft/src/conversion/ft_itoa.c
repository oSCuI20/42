/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbander <edbander@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:55:32 by ebanderas         #+#    #+#             */
/*   Updated: 2023/01/22 22:03:56 by edbander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*_ft_tostr(long number, int base, int lower);
static char	*_ft_tostr_unsigned(unsigned long long number, int base, int lower);

char	*ft_itoa(int n)
{
	return (_ft_tostr((long long) n, 10, 1));
}

char	*ft_itoa_unsinged_int(unsigned int n)
{
	return (_ft_tostr_unsigned((unsigned long) n, 10, 1));
}

char	*ft_itoahex_unsigned_long(
								unsigned long long number,
								char *format,
								int lower)
{
	char	*ptr;

	ptr = _ft_tostr_unsigned(number, 16, lower);
	return (ft_strjoin(format, ptr));
}

static char	*_ft_tostr(long number, int base, int lower)
{
	size_t	nlen;
	int		negative_flag;
	char	*tochar;

	negative_flag = 0;
	if (number < 0)
	{
		number *= -1;
		negative_flag = 1;
	}
	nlen = ft_intlen(number, base) + negative_flag;
	tochar = (char *)ft_calloc(nlen + 1, sizeof(char));
	if (!tochar)
		return (NULL);
	if (base == 10 && negative_flag == 1)
		tochar[0] = '-';
	if (number == 0)
		tochar[0] = '0';
	while (number && nlen--)
	{
		tochar[nlen] = ft_tobase(number, base, lower);
		number /= base;
	}
	return (tochar);
}

static char	*_ft_tostr_unsigned(unsigned long long number, int base, int lower)
{
	size_t	nlen;
	char	*tochar;

	nlen = ft_intlen_unsigned(number, base);
	tochar = (char *)ft_calloc(nlen + 1, sizeof(char));
	if (!tochar)
		return (NULL);
	if (number == 0)
		tochar[0] = '0';
	while (number && nlen--)
	{
		tochar[nlen] = ft_tobase(number, base, lower);
		number /= base;
	}
	return (tochar);
}
