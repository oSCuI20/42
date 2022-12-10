/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:55:32 by ebanderas         #+#    #+#             */
/*   Updated: 2022/12/08 17:55:33 by ebanderas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_intlen(long num);

char	*ft_itoa(int n)
{
	size_t	nlen;
	long	number;
	char	*tochar;

	number = (long) n;
	nlen = ft_intlen(number);
	tochar = (char *)ft_calloc(nlen + 1, sizeof(char));
	if (!tochar)
		return (NULL);
	if (number <= 0)
	{
		number *= -1;
		tochar[0] = '-';
		if (number == 0)
			tochar[0] = '0';
	}
	while (number && nlen--)
	{
		tochar[nlen] = (number % 10) + 48;
		number /= 10;
	}
	return (tochar);
}

static	size_t	ft_intlen(long num)
{
	size_t	len;

	if (num == 0)
		return (1);
	len = 0;
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}
