/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:53:37 by ebanderas         #+#    #+#             */
/*   Updated: 2023/04/17 14:09:23 by ebanderas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_UTILS_H
# define GET_NEXT_LINE_UTILS_H

#include <stdlib.h>

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nelem, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);
size_t  ft_strlcat(char *dest, const char *src, size_t size);

#endif
