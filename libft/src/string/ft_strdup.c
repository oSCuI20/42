/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 03:04:59 by ebanderas         #+#    #+#             */
/*   Updated: 2022/12/05 03:05:02 by ebanderas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char		*pointer;
	size_t		len;

	len = ft_strlen(str) + 1;
	pointer = (char *)ft_calloc(len, sizeof(char));
	if (!pointer)
		return (NULL);
	ft_memcpy(pointer, str, len);
	return (pointer);
}
