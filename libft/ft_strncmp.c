/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbander <edbander@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:20:00 by edbander          #+#    #+#             */
/*   Updated: 2022/12/04 14:20:01 by edbander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if ((s1[i] & 0xff) != (s2[i] & 0xff))
			return ((s1[i] & 0xff) - (s2[i] & 0xff));
		i++;
	}
	return (0);
}
