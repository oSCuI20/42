/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbander <edbander@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:46:27 by edbander          #+#    #+#             */
/*   Updated: 2022/12/04 17:38:27 by edbander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*cdst;
	const unsigned char	*csrc;

	csrc = src;
	cdst = dst;
	if (dst > src)
	{
		while (len--)
			*(unsigned char *)(cdst + len) = *(unsigned char *)(csrc + len);
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
