/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:05:02 by fboumell          #+#    #+#             */
/*   Updated: 2021/12/17 11:31:32 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

/* Before we can do anything with the MiniLibX library we must include 
the <mlx.h> header to access all the functions and we should execute 
the mlx_init function. This will establish a connection to the correct 
graphical system and will return a void * which holds the location of 
our current MLX instance. To initialize MiniLibX one could do the following: */

/* When you run the code, you can’t help but notice that nothing pops up and 
that nothing is being rendered. Well, this obviously has something to do with 
the fact that you are not creating a window yet, so let’s try initializing a tiny 
window which will stay open forever. You can close it by pressing CTRL + C in your 
terminal. To achieve this, we will simply call the mlx_new_window function, which 
will return a pointer to the window we have just created. We can give the window 
height, width and a title. We then will have to call mlx_loop to initiate the 
window rendering. Let’s create a window with a width of 1920, a height of 1080 
and a name of “Hello world!”: */

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 840, 460, "Hello world!");
	mlx_loop(mlx);
}