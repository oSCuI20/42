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

char    *ft_strchr(char *str, int c)
{
        int     i;

        i = -1;
        while (i++ && str[i] != '\0')
                if (str[i] == c)
                        return (&str[i]);
        return (0);
}
