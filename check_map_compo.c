/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_compo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:16:17 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/26 16:51:18 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_check_component(t_data *data)
{
	while (data->map.map[data->i])
	{
		while (data->map.map[data->i][data->j])
		{
			if (data->map.map[data->i][data->j] == 'E')
				data->map.count_E++;
			else if (data->map.map[data->i][data->j] == 'C')
				data->map.count_C++;
			else if (data->map.map[data->i][data->j] == 'P')
				data->map.count_P++;
			data->j++;
		}
		data->j = 0;
		data->i++;
	}
	if (data->map.count_E == 0 || data->map.count_C == 0 || data->map.count_P == 0)
	{
		printf("Error\nMissing a least one component\n");
		exit(0);
	}
	else
		return(1);
}

int ft_check_other_compo(t_data *data)
{
    int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{	
		while (j < ft_strlen(data->map.map[i]) - 1)
		{
			if (data->map.map[i][j] != '0' && data->map.map[i][j] != '1' &&
			data->map.map[i][j] != 'C' && data->map.map[i][j] != 'E' &&
			data->map.map[i][j] != 'P')
			{
				printf("Error\nComponent not valide\n");
				exit(0);
			}
			j++;
		}
		j = 0;
		i++;
	}
    return (1);
}

void ft_check_error_compo(t_data *data)
{
    if (data->map.count_E == 0)
	{
		printf("Error\nThere is no exit\n");
		exit(0);
	}
    if (data->map.count_C == 0)
	{
		printf("Error\nThere is no collecible\n");
		exit(0);
	}
    if (data->map.count_P > 1)
	{
		printf("Error\nThere is more than one starting position\n");
		exit(0);
	}
}

void    ft_check_map_compo(t_data *data)
{
    ft_check_component(data);
    ft_check_other_compo(data);
    ft_check_error_compo(data);
}
	