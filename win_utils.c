/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:20:35 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/27 12:10:37 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_escape(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		data->mlx_win = NULL;
		exit(0);
	}
	return (0);
}

int	red_cross(t_data *data)
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
	mlx_hook(data->mlx_win, 2, 1L << 0, &close_escape, data);
	mlx_hook(data->mlx_win, 17, 0L, &red_cross, data);
	mlx_loop(data->mlx);
	return (0);
}