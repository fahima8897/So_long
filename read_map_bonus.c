/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:44:38 by fboumell          #+#    #+#             */
/*   Updated: 2022/02/01 14:46:41 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}

int	ft_count_line(char *s)
{
	int		fd;
	int		count_line;
	char	*line;

	count_line = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
		printf("Error\nOpen map.ber failed\n");
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			count_line++;
			free(line);
			line = get_next_line(fd);
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
		if (!(data->map.map[row]))
			return (ft_free(data->map.map));
		while (line[i] != '\0')
		{
			data->map.map[row][column] = line[i];
			column++;
			i++;
		}
		data->map.map[row][column] = '\0';
		row++;
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
	if (!(data->map.map))
		return ;
	data->map.fd = open(s, O_RDONLY);
	if (data->map.fd < 0)
		printf("Error\nOpen failed\n");
	else
	{
		ft_fill_map(row, column, i, data);
		close(data->map.fd);
	}
}
