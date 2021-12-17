/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:48:56 by fboumell          #+#    #+#             */
/*   Updated: 2021/12/17 12:14:54 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include <mlx.h>

typedef struct  s_data
{
    void    *img;
    char    *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}   t_data;

#endif