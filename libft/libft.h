/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:49:24 by ebanderas         #+#    #+#             */
/*   Updated: 2022/12/04 14:41:19 by edbander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_tolower(int c);
int		ft_toupper(int c);

size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strnstr(const char *str, const char *sfind, size_t flen);
char	*ft_strrchr(const char *str, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(const char *s1, const char *set);
char	**ft_split(const char *str, char delimiter);
char  *ft_itoa(int n);

int		ft_memcmp(const void *b1, const void *b2, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nelem, size_t size);
void	*ft_memchr(void *v, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
#endif
