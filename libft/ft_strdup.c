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

char	*ft_strdup(const char *str)
{
	char		*pointer;
	size_t		len;

	len = ft_strlen(str) + 1;
	pointer = (char *)ft_calloc(len, sizeof(char *));
	if (!pointer)
		return (NULL);
	ft_memcpy(pointer, str, len);
	return (pointer);
}
