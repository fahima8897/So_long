/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_of_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:40:43 by fboumell          #+#    #+#             */
/*   Updated: 2021/12/17 14:40:47 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_win(int keycode, t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->mlx_win);
    return (0);
}
