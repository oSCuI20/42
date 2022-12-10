/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbander <edbander@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:10:34 by edbander          #+#    #+#             */
/*   Updated: 2022/12/04 14:10:35 by edbander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	n;
	size_t	dlen;
	size_t	slen;

	n = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dest);
	if (size <= dlen)
		return (slen + size);
	while ((n + dlen) < (size - 1) && src[n] != '\0')
	{
		dest[dlen + n] = src[n];
		n++;
	}
	dest[dlen + n] = '\0';
	return (slen + dlen);
}
