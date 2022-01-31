/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:20:35 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/31 11:49:45 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_escape(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		data->mlx_win = NULL;
		exit(0);
	}
	else if (keycode == 'a' || keycode == 'd' || keycode == 's' || keycode == 'w')
		ft_moves(data, keycode);
	return (0);
}

int	ft_red_cross(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	data->mlx_win = NULL;
	exit(0);
}

int	ft_init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (-1);
	data->mlx_win = mlx_new_window(data->mlx, data->win_width, data->win_height, "so_long");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_win);
		return (-1);
	}
	return (0);
}

void	ft_loop(t_data data)
{
	mlx_loop_hook(data.mlx, &ft_image, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, &ft_close_escape, &data);
	mlx_hook(data.mlx_win, 17, 0L, &ft_red_cross, &data);
	mlx_loop(data.mlx);
}

void	ft_destroy_images(t_data data)
{
	mlx_destroy_image(data.mlx, data.image.wall);
	mlx_destroy_image(data.mlx, data.image.floor);
	mlx_destroy_image(data.mlx, data.image.player);
	mlx_destroy_image(data.mlx, data.image.exit);
	mlx_destroy_image(data.mlx, data.image.mouse);
	mlx_destroy_display(data.mlx);
}