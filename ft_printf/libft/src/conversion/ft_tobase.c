/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tobase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 07:30:38 by ebanderas         #+#    #+#             */
/*   Updated: 2023/02/01 19:38:18 by antgalan         ###   ########.fr       */
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
	if (lower)
		x = blower[number % base];
	else
		x = bupper[number % base];
	return (x);
}
