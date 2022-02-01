/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:44:29 by fboumell          #+#    #+#             */
/*   Updated: 2022/02/01 18:12:43 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_display_counter(t_data *data)
{
	char	*moves;

	mlx_put_image_to_window(data->mlx,
		data->mlx_win, data->image.wall, 0, 0);
	moves = ft_itoa(data->count_moves);
	mlx_string_put(data->mlx, data->mlx_win, 20, 20, 0x000000, moves);
	free(moves);
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
