/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbander <edbander@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:43:58 by edbander          #+#    #+#             */
/*   Updated: 2022/12/04 13:45:06 by edbander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *str, int c, size_t len)
{
	size_t			i;
	unsigned char	*s;

	s = str;
	i = 0;
	while (i < len)
	{
		if ((s[i] & 0xff) == (c & 0xff))
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
