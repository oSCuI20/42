/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbander <edbander@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:47:32 by edbander          #+#    #+#             */
/*   Updated: 2022/12/04 13:48:18 by edbander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t				i;
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = b1;
	s2 = b2;
	i = 0;
	while (i < len)
	{
		if ((s1[i] & 0xff) != (s2[i] & 0xff))
			return ((s1[i] & 0xff) - (s2[i] & 0xff));
		i++;
	}
	return (0);
}
