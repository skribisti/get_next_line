/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:38:08 by norabino          #+#    #+#             */
/*   Updated: 2024/11/20 11:55:03 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

int	ft_size_line(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;

	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
/*char	*ft_read_file(int fd, char *res)
{
	char	*buffer;
	int		bytes_read;

	if (!res)
		res = (char *)ft_calloc(1, sizeof(char));
	buffer = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while
	
}*/

char	*get_next_line(int fd)
{
	char 			*buffer;
	char			*dup;
	int				bytes_read;
	int				size_l;
	static char		*remainder = "";
	int				size_remainder;

	if (fd < 0)
	{
		free(remainder);
		buffer = NULL;
		return (NULL);
	}
	//buffer = ft_read_file(fd, buffer);
	
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1) 
        return(printf("ERREUR LECTURE"), NULL);
	size_l = ft_size_line(buffer);
	if (bytes_read == size_l)
		return(printf("Bytes read : %d\n", bytes_read), buffer);
	if (bytes_read > size_l)
	{
		size_remainder = bytes_read - size_l;
		remainder = ft_substr(buffer, size_l + 1, size_remainder);
		if (size_remainder - 1)
			printf("remainder = %s\n\n", remainder);
		dup = ft_substr(buffer, 0, bytes_read - size_remainder + 1);
		return (printf("Bytes read : %d\n", bytes_read - size_remainder), dup);
	}
	return (printf("Bytes read : %d\n", bytes_read), buffer);
}

#include <fcntl.h>
int main() 
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("Buffer : %s;", get_next_line(fd));
	close(fd);
    return 0;
}
