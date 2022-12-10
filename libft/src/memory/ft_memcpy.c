/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbander <edbander@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:47:00 by edbander          #+#    #+#             */
/*   Updated: 2022/12/04 17:02:09 by edbander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*cdst;
	const unsigned char	*csrc;

	cdst = dst;
	csrc = src;
	if (len > 0 && src != dst)
	{
		while (len--)
			*cdst++ = *csrc++;
	}
	return (dst);
}
