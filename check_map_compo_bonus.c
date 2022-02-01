/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_compo_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:43:53 by fboumell          #+#    #+#             */
/*   Updated: 2022/02/01 14:46:57 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_error_compo(t_data *data)
{
	if (data->map.count_e == 0)
	{
		printf("Error\nThere is no exit\n");
		ft_free(data->map.map);
		exit(0);
	}
	if (data->map.count_c == 0)
	{
		printf("Error\nThere is no collecible\n");
		ft_free(data->map.map);
		exit(0);
	}
	if (data->map.count_p == 0)
	{
		printf("Error\nThere is no starting position\n");
		ft_free(data->map.map);
		exit(0);
	}
	if (data->map.count_p > 1)
	{
		printf("Error\nThere is more than one starting position\n");
		ft_free(data->map.map);
		exit(0);
	}
}

int	ft_check_component(t_data *data)
{
	while (data->map.map[data->i])
	{
		while (data->map.map[data->i][data->j])
		{
			if (data->map.map[data->i][data->j] == 'E')
				data->map.count_e++;
			else if (data->map.map[data->i][data->j] == 'C')
				data->map.count_c++;
			else if (data->map.map[data->i][data->j] == 'P')
				data->map.count_p++;
			data->j++;
		}
		data->j = 0;
		data->i++;
	}
	if (!data->map.count_c || !data->map.count_e || !data->map.count_p
		|| data->map.count_p > 1)
		ft_check_error_compo(data);
	return (1);
}

int	ft_check_other_compo(t_data *data)
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
				printf("Error\n At least one of the component is not valide\n");
				ft_free(data->map.map);
				exit(0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void	ft_check_map_compo(t_data *data)
{
	ft_check_component(data);
	ft_check_other_compo(data);
}
