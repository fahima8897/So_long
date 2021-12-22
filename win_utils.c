/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:20:35 by fboumell          #+#    #+#             */
/*   Updated: 2021/12/22 16:15:01 by fboumell         ###   ########.fr       */
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

int    ft_init_window()
{
	t_vars  win;
	
	win.mlx = mlx_init();
	if (win.mlx == NULL)
		return (0);
	win.mlx_win = mlx_new_window(win.mlx, 640, 340, "so_long");
	mlx_hook(win.mlx_win, 2, 1L<<0, close_escape, &win);
	mlx_hook(win.mlx_win, 17, 0L, red_cross, &win);
	mlx_loop(win.mlx);
	return (0);
}