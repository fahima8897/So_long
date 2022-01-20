/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:21:33 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/20 12:34:32 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//lire ligne par ligne puis mettre dans un double tableau??
//lire dans une boucle puis compter le nb de lignes en meme temps
//creer tableau avec nb de lignes et nb colonnes

int	ft_count_line(char *s)
{
	int fd;
	int count_line;

	count_line = 0;
	fd = open("map.ber", O_RDONLY);
	if (fd < 0)
		printf("open map.ber failed\n");
	else
	{
		s = get_next_line(fd);
		while(s != NULL)
		{
			count_line++;
			s = get_next_line(fd);
		}
		close(fd);
	}
	return (count_line);
}

void	ft_fill_map(int row, int column, int i, t_data *data)
{
	char	*line;
	
	line = get_next_line(data->map.fd);
	while (line != NULL)
	{
		data->map.map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!data->map.map[row])
			return(free(data->map.map));
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

void	ft_create_map(char *s, t_data *data)
{
	int	row;
	int	i;
	int	column;

	row = 0;
	i = 0;
	column = 0;
	data->map.count_line = ft_count_line(s);
	data->map.path = s;
	data->map.map = ft_calloc(data->map.count_line + 1, sizeof(char *));
	if (!data->map.map)
		return ;
	data->map.fd = open("map.ber", O_RDONLY);
	if (data->map.fd < 0)
		printf("Error : open failed\n");
	else
	{
		ft_fill_map(row, column, i, data);
		close(data->map.fd);
	}
}
