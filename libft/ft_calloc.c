/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 03:05:27 by ebanderas         #+#    #+#             */
/*   Updated: 2022/12/05 03:05:28 by ebanderas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t size)
{
	void	*pointer;

	if (nelem == 0 || size == 0)
		return (NULL);
	pointer = malloc(nelem * size);
	if (pointer)
		ft_bzero(pointer, nelem * size);
	return (pointer);
}
