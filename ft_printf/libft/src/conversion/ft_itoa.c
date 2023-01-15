/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbander <edbander@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:55:32 by ebanderas         #+#    #+#             */
/*   Updated: 2023/01/09 07:49:22 by edbander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*_ft_tostr(unsigned long long number, int base, int lower);

char	*ft_itoa(int n)
{
	return (_ft_tostr((long long) n, 10, 1));
}

char	*ft_itoa_unsinged_int(unsigned int n)
{
	return (_ft_tostr((long long) n, 10, 1));
}

char	*ft_itoahex(long long number, char *format, int lower)
{
	char	*ptr;

	ptr = _ft_tostr(number, 16, lower);
	return (ft_strjoin(format, ptr));
}

char	*ft_itoahex_unsigned_long(
								unsigned long long number,
								char *format,
								int lower)
{
	char	*ptr;

	ptr = _ft_tostr(number, 16, lower);
	return (ft_strjoin(format, ptr));
}

static char	*_ft_tostr(unsigned long long number, int base, int lower)
{
	size_t	nlen;
	char	*tochar;

	nlen = ft_intlen(number, base);
	tochar = (char *)ft_calloc(nlen + 1, sizeof(char));
	if (!tochar)
		return (NULL);
	if (number <= 0)
	{
		number *= -1;
		if (base == 10)
			tochar[0] = '-';
		else
			nlen--;
		if (number == 0)
			tochar[0] = '0';
	}
	while (number && nlen--)
	{
		tochar[nlen] = ft_tobase((unsigned long long) number, base, lower);
		number /= base;
	}
	return (tochar);
}
