/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_manipulation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:13:40 by ebanderas         #+#    #+#             */
/*   Updated: 2022/11/29 23:42:14 by ebanderas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	ft_toupper(int c)
{
	if (ft_isalpha(c))
		return (c - 32);
	return (c);
}

int	ft_tolower(int c)
{
	if (ft_isalpha(c))
		return (c + 32);
	return (c);
}
