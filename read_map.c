/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:21:33 by fboumell          #+#    #+#             */
/*   Updated: 2021/12/27 17:26:57 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read(t_map *map)
{
	int     fd;
	int		i;
	
	i = 0;
	fd = open("map.ber", O_RDONLY);
	map->map = get_next_line(fd);
	while (map->map[i] != NULL)
		i++;
	map->y_wigth = i;
	i = 0;
	while (map->map[0][i] != NULL)
		i++;
	map->x_lentgh = i;
}