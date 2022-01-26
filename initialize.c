/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:23:45 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/26 12:52:36 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize_map(t_data *data)
{
	data->i = 0;
	data->j = 0;
	data->map.count_P = 0;
	data->map.count_E = 0;
	data->map.count_C = 0;
}