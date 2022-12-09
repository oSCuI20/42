/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 03:04:42 by ebanderas         #+#    #+#             */
/*   Updated: 2022/12/05 03:04:43 by ebanderas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;
	size_t		slen;

	slen = ft_strlen(s);
	if (start < slen)
	{
		if (len > (slen - start))
			len = slen - start;
		sub = ft_calloc(len + 1, sizeof(char));
		i = 0;
		while (sub && start < slen && len--)
		{
			sub[i] = s[start];
			start++;
			i++;
		}
		return (sub);
	}
	sub = ft_calloc(1, 1);
	return (sub);
}
