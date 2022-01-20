#include <mlx.h>
/*
typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}
*/
int	main(void)
{
	void	*mlx;
	void	*img;
	void	*img_v;
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	img = mlx_new_window(mlx, 640, 340, "so_long");
	img_v = mlx_xpm_file_to_image(mlx, "./img/bg.png", &img_width, &img_height);
	//mlx_put_image_to_window(mlx, img, img_v, 0, 0);
	mlx_loop(mlx);
}//./ress/img_16/wall16.xpm 
/*
int main()
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;  // 이미지를 저장할 포인터
    int width;  // 이미지의 너비
    int height; // 이미지의 높이

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "load image!");
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./img/bg.png", &width, &height);
    //mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
    mlx_loop(mlx_ptr);
    return (0);
}*/

void	fill_map(char **tab, int row, int column)
{
	char **map;
	int i;
	
	i = 0;
	while (tab[row] != NULL)
	map[row] = calloc(4 + 1, sizeof(char));
	if (!map)
		return ;
	while (tab[row][column] != '\0')
		map[row][column++] = tab[row][i++];
	map[row][column] = '\0';
	row++;
	column = 0;
	i = 0;
}

int main()
{
	int row = 0;
	int column = 0;
	char **map;
	char tab[5][4] = "1111, 1001, 1001, 1001, 1111";
	map = fill_map(tab, row, column);
	while (row > 6 && column > 5)
	{
		printf("%s\n", map[row][column]);
		row++;
		column++;
	}
}