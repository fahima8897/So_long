/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:39:28 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/26 19:06:16 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_extension(char *av)
{
	char	*extension;
	int		value;
	int		i;
	int		j;

	extension = "ber";
	value = 0;
	i = 0;
	j = 0;
	while (av[i] != '\0')
	{
		if (av[i] != '.')
			i++;
		else
		{
			i++;
			while (av[i + j] && extension[j] && av[i + j] == extension[j])
				j++;
			if (j == 3 && av[i + 3] == '\0')
				value = 1;
		}
	}
	return (value);
}

void	ft_check_arg(int ac, char *av)
{
	int	extension;
	int	fd;

	extension = 0;
	if (ac != 2)
	{
		printf("Error\nWrong number of arguments\n");
		exit(0);
	}
	extension = ft_check_extension(av);
	if (extension == 0)
	{
		printf("Error\nWrong extension\n");
		exit(0);
	}
	fd = open(av, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		printf("Error\nThis is not a file\n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	ft_check_arg(ac, av[1]);
	ft_create_map(av[1], &data);
	ft_initialize_map(&data);
	ft_check_map_struct(&data);
	ft_init_window(&data);
	return (0);
}
