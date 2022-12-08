/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:53:25 by ebanderas         #+#    #+#             */
/*   Updated: 2022/12/08 18:53:27 by ebanderas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*fn)(unsigned int, char))
{
	size_t	slen;
	char	*ptr;

	slen = ft_strlen(s);
	ptr = (char *)ft_calloc(slen + 1, sizeof(char));
	while (slen--)
		ptr[slen] = fn(slen, s[slen]);
	return (ptr);
}
