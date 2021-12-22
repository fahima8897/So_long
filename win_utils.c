/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:47:47 by fboumell          #+#    #+#             */
/*   Updated: 2021/12/22 15:17:30 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_win_close(int keycode, t_vars *win)
{
	if (keycode == 53)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		exit(0);
	}
	return (0);	
}

int    ft_init_window()
{
	t_vars  win;
	
	win.mlx = mlx_init();
	if (win.mlx == NULL)
		return (0);
	win.mlx_win = mlx_new_window(win.mlx, 640, 340, "so_long");
	mlx_hook(win.mlx_win, 2, 1L<<0, handle_win_close, &win);
	mlx_loop(win.mlx);
	return (0);
}