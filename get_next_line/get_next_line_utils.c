/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:40:07 by ebanderas         #+#    #+#             */
/*   Updated: 2023/04/17 14:09:49 by ebanderas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.h"
#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*src;

	src = s;
	i = 0;
	while (i < n)
	{
		src[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t nelem, size_t size)
{
	void	*pointer;

	if (size && (size_t)-1 / size < nelem)
		return (NULL);
	pointer = malloc(nelem * size);
	if (pointer)
		ft_bzero(pointer, nelem * size);
	return (pointer);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t		s1len;
	size_t		s2len;
	char		*joined;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	joined = (char *)ft_calloc(s1len + s2len + 1, sizeof(char));
	if (joined)
	{
		ft_strlcat(joined, s1, s1len + 1);
		ft_strlcat(joined, s2, s1len + s2len + 1);
	}
	return (joined);
}

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
