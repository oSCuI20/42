/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:49:24 by ebanderas         #+#    #+#             */
/*   Updated: 2022/11/29 23:39:24 by ebanderas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>

int ft_atoi(char *str);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
int	ft_strncmp(char *s1, char *s2, size_t n);
int ft_tolower(int c);
int	ft_toupper(int c);

size_t  ft_strlen(char *str);
size_t  ft_strlcat(char *dest, char *src, size_t size);
size_t  ft_strlcpy(char *dest, char *src, size_t size);

char  *ft_strchr(char *str, int c);
char	*ft_strnstr(char *str, char *sfind, size_t flen);
char  *ft_strrchr(char *str, int c);

void ft_bzero(void *s, size_t n);
int ft_memcmp(const void *b1, const void *b2, size_t len);
void *ft_memchr(void *v, int c, size_t len);
void *ft_memcpy(void *dst, const void *src, size_t len);
void *ft_memmove(void *dst, const void *src, size_t len);
void *ft_memset(void *b, int c, size_t len);
#endif
