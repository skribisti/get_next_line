/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: norabino <norabino@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:38:08 by norabino          #+#    #+#             */
/*   Updated: 2024/11/19 12:14:26 by norabino         ###   ########.fr       */
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
	while (buff[i] != '\n' && buff[i])
		i++;
	return (i);
}

#include <fcntl.h>
int main() 
{
	int		fd;
	int		real_fd;
    char 	verif[BUFFER_SIZE];
	int		real_BUFFER_SIZE;
    ssize_t bytesRead;
	ssize_t	real_bytesRead;
	
    fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("ERREUR OUVERTURE\n");
		return (0);
	}


	bytesRead = read(fd, verif, BUFFER_SIZE);
	real_BUFFER_SIZE = ft_size_line(verif);
	char	new[real_BUFFER_SIZE];
	if (bytesRead > real_BUFFER_SIZE)
	{
		real_fd = open("test.txt", O_RDONLY);
		if (real_fd == -1)
			return (0);
		real_bytesRead = read(real_fd, new, real_BUFFER_SIZE);
		printf("Bytes read : %d\n", (int)real_bytesRead);
    	printf("NEW = %s", new);  // Afficher les données lues à l'écran
	}
	else if (bytesRead < real_BUFFER_SIZE && bytesRead > 0)
	{
		real_fd = open("test.txt", O_RDONLY);
		if (real_fd == -1)
		{
			printf("ERREUR OUVERTURE\n");
			return (0);
		}
		real_bytesRead = read(real_fd, new, real_BUFFER_SIZE);
		while (real_bytesRead < real_BUFFER_SIZE)
			real_bytesRead++;
		printf("Bytes read : %d\n", (int)real_bytesRead);
    	printf("NEW = %s", new);  // Afficher les données lues à l'écran
	}
	else if (bytesRead == real_BUFFER_SIZE)
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