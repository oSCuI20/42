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

/*
 * Validate character
 */
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

/*
 * Manipulate data type
 */
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	**ft_split(const char *str, char delimiter);
char	*ft_strmapi(const char *s, char (*fn)(unsigned int, char));

/*
 * Lists management and struct
 */
typedef struct s_list
{
	void					*content;
	struct s_list			*next;
}								t_list;
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*fn)(void *), void (*del)(void *));

/*
 * Memory functions
 */
int		ft_memcmp(const void *b1, const void *b2, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nelem, size_t size);
void	*ft_memchr(void *v, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

/*
 * Puts strings
 */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/*
 * Strings
 */
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
void	ft_striteri(char *s, void (*fn)(unsigned int, char*));
#endif
