/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:04:13 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/31 12:24:20 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_images(t_data *data, int width, int i, int j)
{
	if (data->map.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->image.wall,
			width, i * 48);
	else if (data->map.map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->image.floor,
			width, i * 48);
	else if (data->map.map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->image.player,
			width, i * 48);
	else if (data->map.map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->image.exit,
			width, i * 48);
	else if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->image.mouse,
			width, i * 48);
}

int	ft_image(t_data *data)
{
	int		i;
	size_t	j;
	int		width;

	if (data->mlx_win == NULL)
		return (0);
	i = 0;
	j = 0;
	width = 0;
	while (data->map.map[i])
	{
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
		{
			ft_put_images(data, width, i, j);
			width += 48;
			j++;
		}
		j = 0;
		width = 0;
		i++;
	}
	return (1);
}
