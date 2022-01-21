/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:48:56 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/21 13:03:41 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

//# include "mlx.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

typedef	struct	s_map
{
	int		fd;
	char	*path;
	int		count_line;
	char	**map;
}	t_map;

typedef	struct	s_data
{
	t_map	map;	
}	t_data;

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

/*typedef struct s_map
{
	char **map;
	int	x_lentgh;
	int	y_wigth;
}	t_map;*/


	/* so_long.c */
void	ft_check_arg(int ac, char *av);
int		ft_check_extension(char *av);

	/* win_utils.c */
/*int		close_escape(int keypress, t_vars *win);
int		red_cross(t_vars *win);
void	ft_init_window(void);*/

	/* read_map.c */
void	ft_free(char **tab);
int		ft_count_line(char *s);
void	ft_fill_map(int row, int column, int i, t_data *data);
void	ft_create_map(char *s, t_data *data);

	/* utils.c */
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(const char *s);

#endif