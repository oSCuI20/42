/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:18:13 by ebanderas         #+#    #+#             */
/*   Updated: 2022/12/08 22:18:14 by ebanderas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*fn)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		fn(i, &s[i]);
		i++;
	}
}
