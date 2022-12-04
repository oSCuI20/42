/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbander <edbander@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:49:28 by edbander          #+#    #+#             */
/*   Updated: 2022/12/04 14:46:10 by edbander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_islower(int c);

int	ft_toupper(int c)
{
	if (ft_isalpha(c) && ft_islower(c))
		return (c - 32);
	return (c);
}

int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
