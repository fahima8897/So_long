/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:48:56 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/31 13:36:47 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <X11/X.h>
# include <X11/keysym.h>

#ifndef O_DIRECTORY
# define O_DIRECTORY 00200000
#endif

# define FLOOR "xpm/grass.xpm"
# define WALL "xpm/wall.xpm"
# define PLAYER "xpm/player.xpm"
# define COLLEC "xpm/collectible.xpm"
# define EXIT "xpm/exit.xpm"

typedef struct s_map
{
	int		fd;
	char	*path;
	int		len_line;
	int		count_line;
	int		count_e;
	int		count_c;
	int		count_p;
	int		count_collectible;
	int		exit;
	char	**map;
}	t_map;

typedef struct s_image
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*mouse;
	void	*exit;
	int		width;
	int		height;
}	t_image;

typedef struct s_data
{
	int		i;
	int		j;
	void	*mlx;
	void	*mlx_win;
	int		win_height;
	int		win_width;
	int		position_i;
	int		position_j;
	int		count_moves;
	t_map	map;
	t_image	image;
}	t_data;

	/* so_long.c */
void	ft_check_arg(int ac, char *av);
int		ft_check_extension(char *av);
int		main(int ac, char **av);

	/* win_utils.c */
int		ft_close_escape(int keypress, t_data*win);
int		ft_red_cross(t_data *win);
int		ft_init_window(t_data *data);
void	ft_loop(t_data data);
void	ft_destroy_images(t_data data);

	/* read_map.c */
void	ft_free(char **tab);
int		ft_count_line(char *s);
void	ft_fill_map(int row, int column, int i, t_data *data);
void	ft_create_map(char *s, t_data *data);

	/* utils.c */
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(const char *s);

	/* check_map_struct.c */
int		ft_check_sizeofmap(t_data *data);
int		ft_check_walls(int line, char **map);
int		ft_check_walls_sides(int line_count, char **map);
void	ft_check_map_struct(t_data *data);

	/* check_map_compo.c */
int		ft_check_component(t_data *data);
int		ft_check_other_compo(t_data *data);
void	ft_check_error_compo(t_data *data);
void	ft_check_map_compo(t_data *data);

	/* initialize.c */
void	ft_initialize_map(t_data *data);
void	ft_player_position(t_data *data);
void	ft_initialize_images(t_data *data);

	/* image.c */
void	ft_put_images(t_data *data, int width, int i, int j);
int		ft_image(t_data *data);

	/* moves.c */
int		ft_check_next_compo(t_data *data, char keycode, char component);
void	ft_collectible(t_data *data, char keycode);
int		ft_you_win(t_data *data);
void	ft_moves(t_data *data, char keycode);

#endif