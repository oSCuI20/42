/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbander <edbander@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:50:13 by edbander          #+#    #+#             */
/*   Updated: 2022/12/01 19:50:42 by edbander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int c)
{
	size_t	i;
	size_t	len;

	if (str)
	{
		i = 0;
		len = ft_strlen(str);
		while (i <= len)
		{
			if (str[i] == (c & 0xff))
				return (&str[i]);
			i++;
		}
	}
	return (NULL);
}
