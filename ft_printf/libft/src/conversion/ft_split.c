/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:11:57 by ebanderas         #+#    #+#             */
/*   Updated: 2023/01/31 17:27:44 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_split(const char *str, char c);
static size_t	ft_strlen_by_delimiter(const char *str, char c);
static char		*ft_substr_split(const char *str, size_t start, char c);

char	**ft_split(const char *str, char c)
{
	size_t	i;
	size_t	start;
	char	**split;

	split = (char **)ft_calloc(ft_strlen_split(str, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	start = 0;
	while (str[start] != '\0')
	{
		while (str[start] == c)
			start++;
		if (!str[start])
			continue ;
		split[i] = ft_substr_split(str, start, c);
		if (!split[i])
			return (NULL);
		start = start + ft_strlen(split[i]);
		i++;
	}
	split[i] = NULL;
	return (split);
}

static char	*ft_substr_split(const char *str, size_t start, char c)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen_by_delimiter(&str[start], c);
	ptr = ft_substr(str, start, len);
	if (ptr)
		ptr[len] = '\0';
	return (ptr);
}

static size_t	ft_strlen_split(const char *str, char c)
{
	size_t	slen;
	size_t	i;

	i = 0;
	slen = 0;
	if (!str[i])
		return (slen);
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i] == c)
				i++;
			if (str[i])
				slen++;
			continue ;
		}
		i++;
	}
	return (slen + 1);
}

static size_t	ft_strlen_by_delimiter(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}
