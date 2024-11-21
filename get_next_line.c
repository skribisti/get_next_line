/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:38:08 by norabino          #+#    #+#             */
/*   Updated: 2024/11/21 09:04:41 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_read_to_remainder(int fd, char *remainder)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(remainder, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (free(buffer), NULL);
		buffer[read_bytes] = 0;
		remainder = ft_strjoin(remainder, buffer);
	}
	free(buffer);
	return (remainder);
}
char	*ft_get_a_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = ft_substr(str, 0, i + 1);
	return (line);
	
}
char	*ft_new_remainder(char *remainder)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(remainder) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (remainder[i])
		str[j++] = remainder[i++];
	str[j] = '\0';
	free(remainder);
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*remainder;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = ft_read_to_remainder(fd, remainder);
	if (!remainder)
		return (NULL);
	line = ft_get_a_line(remainder);
	remainder = ft_new_remainder(remainder);
	return (line);
}

#include <fcntl.h>
int main() 
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("LINE1 = %s;\n", get_next_line(fd));
	printf("LINE2 = %s;\n", get_next_line(fd));
	close(fd);
    return 0;
}
