/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:04:13 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/27 16:44:02 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_images(t_data *data, int width, int i, int j)
{
	if (data->map.map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->image.floor,
			width, i * 64);
}

int	ft_image(t_data *data)
{
	int		i;
	int     j;
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
			width += 64;
			j++;
		}
		j = 0;
		width = 0;
		i++;
	}
	return (1);
}