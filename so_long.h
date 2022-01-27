/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:48:56 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/27 16:14:26 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

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

typedef	struct	s_map
{
	int		fd;
	char	*path;
	int		len_line;
	int		count_line;
	int		count_e;
	int		count_c;
	int		count_p;
	char	**map;
}	t_map;

typedef struct s_image
{
	void	*floor;
	int		width;
	int		height;
}	t_image;

typedef	struct	s_data
{
	int	i;
	int	j;
	void	*mlx;
	void	*mlx_win;
	int		win_height;
	int		win_width;
	int		position_i;
	int		position_j;
	t_map	map;
	t_image	image;
}	t_data;

	/* so_long.c */
void	ft_check_arg(int ac, char *av);
int		ft_check_extension(char *av);

	/* win_utils.c */
int		close_escape(int keypress, t_data*win);
int		red_cross(t_data *win);
int		ft_init_window(t_data *data);

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
void    ft_check_map_struct(t_data *data);

	/*check_map_compo.c */
int		ft_check_component(t_data *data);
int		ft_check_other_compo(t_data *data);
void	ft_check_error_compo(t_data *data);
void    ft_check_map_compo(t_data *data);

	/* initialize.c */
void	ft_initialize_map(t_data *data);
void	ft_player_position(t_data *data);

	/* image.c */
void	init_images(t_data *data);


#endif