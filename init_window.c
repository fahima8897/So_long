/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:14:31 by fboumell          #+#    #+#             */
/*   Updated: 2021/12/17 12:15:09 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* mlx_init et mlx_new_window permettent d'initialiser et de creer une fenetre qui se ferme 
avec ctrl+c ou en appuyant sur la croix */

/*Pour recevoir des événements, on utilise mlx_loop(). Cette fonction est void. 
C'est une boucle infinie qui attend un événement, puis appelle une fonction définie
par l'utilisateur associée à cet événement */

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    init_image()
{
    t_vars  vars;
    t_vars img;
    

    vars.mlx = mlx_init();
    vars.mlx_win = mlx_new_window(vars.mlx, 640, 340, "so_long");
    img.img.mlx_img = mlx_new_image(vars.mlx, 640, 340);
    img.img.addr = mlx_get_data_addr(img.img.mlx_img, &img.img.bits_per_pixel, &img.img.line_len,
                    &img.img.endian);
    my_mlx_pixel_put(&img.img, 5, 5, 0x0000FF00);
    my_mlx_pixel_put(&img.img, 6, 6, 0x00FF0000);
    mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img.mlx_img, 0, 0);
    mlx_hook(vars.mlx_win, 2, 1L<<0, &close_win, &vars);
    mlx_loop(vars.mlx);
    
}

int main()
{
    t_vars *vars;

    int a = close_win(VK_ESCAPE, vars);
    init_image();

    return (0);
}