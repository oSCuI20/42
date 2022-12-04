/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbander <edbander@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:50:55 by edbander          #+#    #+#             */
/*   Updated: 2022/12/04 13:50:06 by edbander         ###   ########.fr       */
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
