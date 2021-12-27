/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:48:56 by fboumell          #+#    #+#             */
/*   Updated: 2021/12/27 16:59:44 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>



/*
typedef struct  s_data
{
	void    *mlx_img;
	char    *addr;
	int bits_per_pixel;
	int line_len;
	int endian;
}   t_data;
*/
typedef struct s_vars
{
	void    *mlx;
	void    *mlx_win;
}   t_vars;

	/* so_long.c */
int		check_arg(int ac, char *av);

	/* win_utils.c */
int		close_escape(int keypress, t_vars *win);
int		red_cross(t_vars *win);
void	ft_init_window(void);


#endif