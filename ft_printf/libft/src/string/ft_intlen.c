/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbander <edbander@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 07:42:01 by edbander          #+#    #+#             */
/*   Updated: 2023/01/08 19:15:09 by edbander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(long long num, int base)
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
		num /= base;
		len++;
	}
	return (len);
}
