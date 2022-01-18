/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:21:33 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/18 16:51:39 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

//lire ligne par ligne puis mettre dans un double tableau??
//lire dans une boucle puis compter le nb de lignes en meme temps
//creer tableau avec nb de lignes et nb colonnes

int	ft_count_line(char *s)
{
	int fd;
	int count_line;

	count_line = 0;
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		write(1, "open map.ber failed\n", 20);
	s = get_next_line(fd);
//	printf("first line : %s", s);
	while(s != NULL)
	{
		count_line++;
//		printf("%d\n", count_line);
		s = get_next_line(fd);
//		printf("other lines : %s\n", s);
	}
	close(fd);
	return (count_line);
}

char	**ft_create_map(char *s)
{
	int line;
	char **map;
	
	line = ft_count_line(s);
	printf("dans create_map : %d\n", line); 
	map = malloc(sizeof(char *) * (line + 1));
	if (!map)
		return (NULL);
	return (map);
}

void	ft_read_map(char *s)
{
	int	column;
	int	line;
	int	fd;
	char **map;

	line = ft_count_line(s);
	map = ft_create_map(s);
	fd = open("map.ber", O_RDONLY);
	if (fd == -1)
		write(1, "open map.ber failed\n", 20);
	map = get_next_line(fd);
	while(map != NULL)
	{
		map[]
	}
	
}


void	create_map(char *path, t_data *data)
{
	int		row;
	int		i;
	size_t	column;

	i = 0;
	row = 0;
	column = 0;
	data->map.line_count = retrieve_line_number(path);
	data->map.path = path;
	data->map.map = ft_calloc(data->map.line_count + 1, sizeof(char *));
	if (!(data->map.map))
		return ;
	data->map.fd = open(path, O_RDONLY);
	if (data->map.fd < 0)
		printf("\e[31mError: open failed\e[0m\n");
	else
	{
		put_input_in_map(row, column, i, data);
		close(data->map.fd);
	}
}


void	put_input_in_map(int row, int column, int i, t_data *data)
{
	char	*line;

	line = get_next_line(data->map.fd);
	while (line != NULL)
	{
		data->map.map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->map.map[row])
			return (ft_free(data->map.map));
		while (line[i] != '\0')
			data->map.map[row][column++] = line[i++];
		data->map.map[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(data->map.fd);
	}
	data->map.map[row] = NULL;
}