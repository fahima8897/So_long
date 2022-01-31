/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 11:06:20 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/31 17:07:49 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_next_compo(t_data *data, char keycode, char component)
{
	if ((keycode == 'd'
			&& data->map.map[data->position_i][data->position_j + 1]
		== component) || (keycode == 'a'
		&& data->map.map[data->position_i][data->position_j - 1]
		== component) || (keycode == 's'
		&& data->map.map[data->position_i + 1][data->position_j]
		== component) || (keycode == 'w'
		&& data->map.map[data->position_i - 1][data->position_j] == component))
		return (0);
	else
		return (1);
}

void	ft_collectible(t_data *data, char keycode)
{
	if ((keycode == 'd'
			&& data->map.map[data->position_i][data->position_j + 1] == 'C')
		|| (keycode == 'a'
		&& data->map.map[data->position_i][data->position_j - 1] == 'C')
		|| (keycode == 's'
		&& data->map.map[data->position_i + 1][data->position_j] == 'C')
		|| (keycode == 'w'
		&& data->map.map[data->position_i - 1][data->position_j] == 'C'))
		data->map.count_collectible++;
}

int	ft_you_win(t_data *data)
{
	if (data->map.exit == 1)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		data->mlx_win = NULL;
		return (0);
	}
	else
		return (1);
}

void	ft_moves(t_data *data, char keycode)
{
	if (ft_check_next_compo(data, keycode, '1') == 0
		|| (data->map.exit == 0
			&& ft_check_next_compo(data, keycode, 'E') == 0))
		return ;
	data->count_moves++;
	ft_collectible(data, keycode);
	if (data->map.count_collectible == data->map.count_c)
		data->map.exit = 1;
	data->map.map[data->position_i][data->position_j] = '0';
	if (keycode == 'd')
		data->position_j++;
	else if (keycode == 'a')
		data->position_j--;
	else if (keycode == 's')
		data->position_i++;
	else if (keycode == 'w')
		data->position_i--;
	printf("Number of moves: %d\n", data->count_moves);
	if (data->map.exit == 1
		&& data->map.map[data->position_i][data->position_j] == 'E')
		ft_you_win(data);
	data->map.map[data->position_i][data->position_j] = 'P';
}
