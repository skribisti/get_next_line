/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:38:08 by norabino          #+#    #+#             */
/*   Updated: 2024/11/20 10:35:13 by norabino         ###   ########.fr       */
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

char	*ft_strndup(char *str, int n)
{
	char	*tab;
	int		i;

	tab = (char *)malloc(n + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char	*get_next_line(int fd)
{
	char 			*buffer;
	char			*dup;
	int				bytes_read;
	int				size_l;
	static char		*remainder = "";
	int				size_remainder;

	if (fd <= 0)
		return (printf("ERREUR OUVERTURE"), NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (ft_strlen(remainder))
	{
		
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1) 
        return(printf("ERREUR LECTURE"), NULL);
	size_l = ft_size_line(buffer);
	if (bytes_read == size_l)
		return(printf("Bytes read : %d\n", bytes_read), buffer);
	if (bytes_read > size_l)
	{
		size_remainder = bytes_read - size_l;
		remainder = ft_strndup(buffer + size_l, size_remainder);
		if (size_remainder - 1)
			printf("remainder = %s\n", remainder);
		dup = ft_strndup(buffer, bytes_read - size_remainder +1);
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
