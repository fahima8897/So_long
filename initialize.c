/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:23:45 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/27 17:06:36 by fboumell         ###   ########.fr       */
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
	data->win_height = data->map.count_line * 64;
	data->win_width = (ft_strlen(data->map.map[0]) - 1) * 48;
	data->image.width = 64;
	data->image.height = 64;
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

void	ft_initialize_images(t_data *data)
{
	data->image.floor = mlx_xpm_file_to_image(data->mlx, FLOOR,
			&data->image.width, &data->image.height);
}
