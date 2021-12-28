/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:39:28 by fboumell          #+#    #+#             */
/*   Updated: 2021/12/28 12:48:03 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_arg(int ac, char *av)
{
	int i;

	i = 0;
	if (ac != 2)
	{
		if (ac < 2)
			write(1, "Missing one argument\n", 22);
		if (ac > 2)
			write(1, "Too much arguments\n", 19);
		exit(0);
	}
	while(av[i])
		i++;
	if (av[i - 1] != 'r' && av[i - 2] != 'e' && av[i - 3] != 'b' && av[i - 4] != '.')
	{
		write(1, "Wrong extension, argument must be a .ber file\n", 46);
		exit(0);
	}
	return (1);
}

int main(int ac, char **av)
{
	check_arg(ac, av[1]);
	ft_read(av[1]);
//	ft_init_window();
	return (0);
}