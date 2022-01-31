/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:23:45 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/31 19:30:59 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize_map(t_data *data)
{
	data->i = 0;
	data->j = 0;
	data->map.count_p = 0;
	data->map.count_e = 0;
	data->map.count_c = 0;
	data->count_moves = 0;
	data->map.count_collectible = 0;
	data->map.exit = 0;
	data->win_height = data->map.count_line * 48;
	data->win_width = (ft_strlen(data->map.map[0]) - 1) * 48;
	data->image.width = 48;
	data->image.height = 48;
}

void	ft_player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'P')
			{
				data->position_i = i;
				data->position_j = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_free_images(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->image.floor)
		mlx_destroy_image(data->mlx, data->image.floor);
	if (data->image.wall)
		mlx_destroy_image(data->mlx, data->image.wall);
	if (data->image.player)
		mlx_destroy_image(data->mlx, data->image.player);
	if (data->image.mouse)
		mlx_destroy_image(data->mlx, data->image.mouse);
	if (data->image.exit)
		mlx_destroy_image(data->mlx, data->image.exit);
	mlx_destroy_display(data->mlx);
	data->mlx_win = NULL;
	free(data->mlx);
	ft_free(data->map.map);
	printf("Error\nThis file doesn't exist\n");
	exit(0);
}

void	ft_initialize_images(t_data *data)
{
	data->image.floor = mlx_xpm_file_to_image(data->mlx, FLOOR,
			&data->image.width, &data->image.height);
	if (!data->image.floor)
		ft_free_images(data);
	data->image.wall = mlx_xpm_file_to_image(data->mlx, WALL,
			&data->image.width, &data->image.height);
	if (!data->image.wall)
		ft_free_images(data);
	data->image.player = mlx_xpm_file_to_image(data->mlx, PLAYER,
			&data->image.width, &data->image.height);
	if (!data->image.player)
		ft_free_images(data);
	data->image.mouse = mlx_xpm_file_to_image(data->mlx, COLLEC,
			&data->image.width, &data->image.height);
	if (!data->image.mouse)
		ft_free_images(data);
	data->image.exit = mlx_xpm_file_to_image(data->mlx, EXIT,
			&data->image.width, &data->image.height);
	if (!data->image.exit)
		ft_free_images(data);
}
