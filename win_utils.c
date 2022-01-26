/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:20:35 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/26 19:07:39 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_escape(int keycode, t_vars *win)
{
	if (keycode == 53)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		exit(0);
	}
	return (0);
}

int	red_cross(t_vars *win)
{
	mlx_destroy_window(win->mlx, win->mlx_win);
	exit(0);
}

int	ft_init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (0);
	data->mlx_win = mlx_new_window(data->win_mlx, data->win_width, data->win_height, "so_long");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_win == NULL)
		return (-1);
	}
	return (0);
/*	mlx_hook(win.mlx_win, 2, 1L << 0, close_escape, &win);
	mlx_hook(win.mlx_win, 17, 0L, red_cross, &win);
	mlx_loop(win.mlx);*/
}
