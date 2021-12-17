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

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void    init_image()
{
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 640, 340, "so_long");
    img.img = mlx_new_image(mlx, 640, 340);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                    &img.endian);
    my_mlx_pixel_put(&img, 5, 5, 0x0000FF00);
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
    
}

int main()
{
    init_image();
    return (0);
}