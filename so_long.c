/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:39:28 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/18 17:31:52 by fboumell         ###   ########.fr       */
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
			printf("Missing one argument\n");
		if (ac > 2)
			printf("Too much arguments\n");
		exit(0);
	}
	while(av[i])
		i++;
	if (av[i - 1] != 'r' && av[i - 2] != 'e' && av[i - 3] != 'b' && av[i - 4] != '.')
	{
		printf("Wrong extension, argument must be a .ber file\n");
		exit(0);
	}
	return (1);
}

int main(int ac, char **av)
{
	check_arg(ac, av[1]);
//	ft_create_map(av[1]);
//	ft_init_window();
	return (0);
}