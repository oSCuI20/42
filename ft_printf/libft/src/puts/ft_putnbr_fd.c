/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:37:41 by ebanderas         #+#    #+#             */
/*   Updated: 2022/12/08 22:37:42 by ebanderas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	number;

	number = (long) n;
	if (number < 0)
	{
		number *= -1;
		ft_putchar_fd('-', fd);
	}
	if (number > 9)
	{
		ft_putnbr_fd(number / 10, fd);
		ft_putchar_fd((char )(number % 10) + 48, fd);
	}
	else
		ft_putchar_fd((char )(number) + 48, fd);
}
