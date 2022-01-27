/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:04:13 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/27 16:13:57 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_data *data)
{
	data->image.floor = mlx_xpm_file_to_image(data->mlx, "xmp/grass.xpm",
			&data->image.width, &data->image.height);
}