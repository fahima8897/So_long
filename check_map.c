/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:29:47 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/26 12:33:02 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long"

int ft_check_characters(t_data *data)
{
    while (data->map.map[data->i])
    {
        if (data->map.map[data->i][data->j] == 'E')
            data->map.count_E++;
        if (data->map.map[data->i][data->j] == 'C')
            data->map.count_C++;
        if (data->map.map[data->i][data->j] == 'P')
            data->map.count_P++;
        data->j++;
    }
    data->j = 0;
    data->i++;
    if (data->count_E == 0 || data->count_C == 0 || data->count_P == 0)
    {
        printf("Error\nMissing component\n");
        exit(0);
    }
    else
        return(1);
}