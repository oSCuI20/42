/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 07:15:44 by ebanderas         #+#    #+#             */
/*   Updated: 2022/12/05 07:15:46 by ebanderas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t		s1len;
	size_t		s2len;
	char		*joined;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	joined = (char *)ft_calloc(s1len + s2len + 1, sizeof(char));
	if (joined)
	{
		ft_strlcat(joined, s1, s1len + 1);
		ft_strlcat(joined, s2, s1len + s2len + 1);
	}
	return (joined);
}
