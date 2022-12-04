/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbander <edbander@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:11:36 by edbander          #+#    #+#             */
/*   Updated: 2022/12/04 14:11:37 by edbander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *sfind, size_t flen)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (str[i] && sfind[len])
	{
		len = 0;
		while (sfind[len] && str[i + len] == sfind[len])
			len++;
		if (len + i > flen || !str[i + 1])
			return (NULL);
		if (sfind[len])
			i++;
	}
	return (&str[i]);
}
