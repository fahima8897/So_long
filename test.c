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