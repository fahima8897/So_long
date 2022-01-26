/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:29:47 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/26 14:14:30 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_characters(t_data *data)
{
	while (data->map.map[data->i])
	{
		while (data->map.map[data->i][data->j])
		{
			if (data->map.map[data->i][data->j] == 'E')
				data->map.count_E++;
			else if (data->map.map[data->i][data->j] == 'C')
				data->map.count_C++;
			else if (data->map.map[data->i][data->j] == 'P')
				data->map.count_P++;
			data->j++;
		}
		data->j = 0;
		data->i++;
	}
	if (data->map.count_E == 0 || data->map.count_C == 0 || data->map.count_P == 0)
	{
		printf("Error\nMissing a least one component\n");
		exit(0);
	}
	else
		return(1);
}


int	ft_check_walls(int line, char **map)
{
	int	i;

	i = 0;
	while (map[line][i] && map[line][i] != '\n')
	{
		if (map[line][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_walls_sides(int count_line, char **map)
{
	int	i;

	i = 1;
	if (ft_check_walls(0, map) == 0 || ft_check_walls(count_line, map) == 0)
	{
		printf("Error\nThere is a hole in the wall\n");
		exit(0);
	}
	while (i < count_line)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 2] != '1')
		{
			printf("Error\nThere is a hole in the wall\n");
			exit(0);
		}
		i++;
	}
	return (1);
}

int	ft_check_sizeofmap(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->map.len_line = ft_strlen(data->map.map[i]) - 1;
	while (data->map.map[i])
	{
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
			j++;
		if (j != data->map.len_line)
		{
			printf("Error\nThe map is not a rectangle\n");
			exit(0);
		}
		j = 0;
		i++;
	}
	return (1);
}

void    ft_check_map(t_data *data)
{
	/*int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{	
		while (j < ft_strlen(data->map.map[i]) - 1)
		{
			if (ft_strchr("01CEP", data->map.map[i][j]) == NULL)
				error_msg(ERROTHER, data);
			j++;
		}
		j = 0;
		i++;
	}*/
	ft_check_sizeofmap(data);
	ft_check_characters(data);
	ft_check_walls_sides(data->map.count_line - 1, data->map.map);
}

/*

int	check_top_bot(int row, char **map)
{
	int	i;

	i = 0;
	while (map[row][i] && map[row][i] != '\n')
	{
		if (map[row][i] != '1')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_edges(int line_count, char **map)
{
	int	i;

	i = 1;
	if (check_top_bot(0, map) == FAILURE
		|| check_top_bot(line_count, map) == FAILURE)
		return (FAILURE);
	while (i < line_count)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 2] != '1')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_rectangle(t_data *data)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	data->map.line_len = ft_strlen(data->map.map[i]) - 1;
	while (data->map.map[i])
	{
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
			j++;
		if (j != data->map.line_len)
			return (FAILURE);
		j = 0;
		i++;
	}
	return (SUCCESS);
}*/