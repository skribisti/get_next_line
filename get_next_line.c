/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:38:08 by norabino          #+#    #+#             */
/*   Updated: 2024/11/19 10:43:27 by norabino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*char	*get_next_line(int fd)
{
	int		line_size;
	char	*line;

	line_size = 0;
	
}

int	main(void)
{
	int		fd;
	int		i;
	char	*res;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("ERREUR OUVERTURE\n");
		return (0);
	}
	i = 0;
	while(get_next_line(fd) != NULL)
	{
		get_next_line(fd);
		i++;
	}
	printf("NB READED LINES :%d\n",i);
}*/

int	ft_size_line(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\n')
		i++;
	return (i - 1);
}

#include <fcntl.h>
int main() 
{
	int	fd;
	int	real_size;
    ssize_t bytesRead;
	
    fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("ERREUR OUVERTURE\n");
		return (0);
	}

    char 	verif[BUFFER_SIZE];

	bytesRead = read(fd, verif, BUFFER_SIZE);
	real_size = ft_size_line(verif);
	char	new[real_size];
	if (bytesRead > real_size)
	{
		bytesRead = read(fd, new, real_size);
		printf("Bytes read : %d\n", (int)bytesRead);
    	printf("NEW = %s", new);  // Afficher les données lues à l'écran
	}
	else
	{
		printf("Bytes read : %d\n", (int)bytesRead);
    	printf("BUFF = %s", verif);  // Afficher les données lues à l'écran
	}
	
    // Lire des données depuis le fichier
    if (bytesRead == -1) 
        printf("Erreur de lecture du fichier");

    close(fd);  // Fermer le fichier
    return 0;
}