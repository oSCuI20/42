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

char	*ft_strrchr(char *str, int c)
{
	int	len;

	if (str)
	{
		len = ft_strlen(str);
		while (len >= 0)
		{
			if (str[len] == (c & 0xff))
				return (&str[len]);
			len--;
		}
	}
	return (NULL);
}
