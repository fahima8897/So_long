/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:39:28 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/20 17:47:14 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_arg(int ac, char *av) //voir clg
{
	int i;
	int	len;

	i = 0;
	len = ft_strlen(av);
	if (ac != 2)  //attention segfault quand ac == 1!!!
	{
		if (ac < 2)
			printf("Error\nMissing one argument\n");
		if (ac > 2)
			printf("Error\nToo many arguments\n");
		exit(0);
	}
	if (av[len - 3] != 'b' && av[len - 2] != 'e' && av[len - 1] != 'r' && av[len - 4] != '.')
	{
		printf("Wrong extension, argument must be a .ber file\n");
		exit(0);
	}
	return (1);
}

int main(int ac, char **av)
{
	t_data	data;
	
	check_arg(ac, av[1]);
	ft_create_map(av[1], &data);
//	ft_init_window();
	return (0);
}