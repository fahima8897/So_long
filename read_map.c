/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:21:33 by fboumell          #+#    #+#             */
/*   Updated: 2021/12/28 12:52:29 by fboumell         ###   ########.fr       */
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