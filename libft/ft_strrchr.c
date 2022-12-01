/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edbander <edbander@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:50:55 by edbander          #+#    #+#             */
/*   Updated: 2022/12/01 19:50:56 by edbander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
