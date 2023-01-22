/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tobase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbander <edbander@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 07:30:38 by ebanderas         #+#    #+#             */
/*   Updated: 2023/01/22 21:53:10 by edbander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_tobase(unsigned long long number, int base, int lower)
{
	char	x;
	char	*bupper;
	char	*blower;

	blower = "0123456789abcdef";
	bupper = "0123456789ABCDEF";
	x = bupper[number % base];
	if (lower)
		x = blower[number % base];
	return (x);
}
