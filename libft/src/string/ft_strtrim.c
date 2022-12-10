/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:39:59 by ebanderas         #+#    #+#             */
/*   Updated: 2022/12/06 10:40:00 by ebanderas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	slen;

	if (s1 && set)
	{
		while (ft_strchr(set, *s1) && *s1)
			s1++;
		slen = ft_strlen(s1);
		while (ft_strrchr(set, s1[slen]))
			slen--;
		return (ft_substr(s1, 0, slen + 1));
	}
	return (NULL);
}
