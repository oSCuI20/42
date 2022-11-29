/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 23:42:27 by ebanderas         #+#    #+#             */
/*   Updated: 2022/11/29 23:55:17 by ebanderas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

char    *ft_strchr(char *str, int c)
{
        int     i;

        i = -1;
        while (i++ && str[i] != '\0')
                if (str[i] == c)
                        return (&str[i]);
        return (0);
}

char    *ft_strrchr(char *str, int c)
{
        int len;

        len = ft_strlen(str);
        while (len > 0) {
                if (str[len] == c)
                        return (&str[len]);
        }

        return (0);
}
