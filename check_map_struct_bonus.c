/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_struct_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:44:04 by fboumell          #+#    #+#             */
/*   Updated: 2022/02/01 14:46:55 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			ft_free(data->map.map);
			exit(0);
		}
		j = 0;
		i++;
	}
	return (1);
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
		ft_free(map);
		exit(0);
	}
	while (i < count_line)
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 2] != '1')
		{
			printf("Error\nThere is a hole in the wall\n");
			ft_free(map);
			exit(0);
		}
		i++;
	}
	return (1);
}

void	ft_check_map_struct(t_data *data)
{
	ft_check_sizeofmap(data);
	ft_check_walls_sides(data->map.count_line - 1, data->map.map);
	ft_check_map_compo(data);
}
