/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebanderas <edbander@student.42malaga.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:38:18 by ebanderas         #+#    #+#             */
/*   Updated: 2023/04/17 19:52:25 by ebanderas        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.h"

static char     *read_line(int fd, char *buffer)
{
	char	*tmp;
	int	ret;
	
	while ((ret = read(fd, buffer, BUFFER_SIZE)) < 0)  {
		tmp = ft_strjoin(tmp, buffer);
		if (!buffer || buffer[0] == '\n')
			break ;
        }
	if (ret == 0) 
		tmp = NULL;
	return (tmp);
}


char *get_next_line(int fd) 
{
	static char	*line;
	char 	*buffer;

	buffer = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	if (fd < 0 || !buffer)
		return (NULL);

	line = read_line(fd, buffer);
	return (line);

}

int main(int argc, char **argv)
{
	int	fd;
	char	*line;

	fd = open("test.txt", 'r');
	while ((line = get_next_line(fd))) {
		printf("%s", line);
	}
}
