/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:21:33 by fboumell          #+#    #+#             */
/*   Updated: 2021/12/28 12:47:34 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

//lire ligne par ligne puis mettre dans un double tableau??
//lire dans une boucle puis compter le nb de lignes en meme temps
//creer tableau avec nb de lignes et nb colonnes

int	ft_read(char *s)
{
	int fd;
	int count_line;

	count_line = 0;
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		write(1, "open map.ber failed\n", 20);
	s = get_next_line(fd);
//	printf("%s", s);
	while(s != NULL)
	{
		count_line++;
	//	printf("%d\n", count_line);
		s = get_next_line(fd);
//		printf("%s", s);
	}
	close(fd);
	return (count_line);
}
//pas ma version (en dessous)
/*
int	retrieve_line_number(char *path)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		printf("\e[31mError: open failed\e[0m\n");
	else
	{
		line = get_next_line(fd);
		printf("%s", line);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
			printf("%s", line);
		}
		close(fd);
	}
	printf("%d\n", line_count);
	return (line_count);
}*/