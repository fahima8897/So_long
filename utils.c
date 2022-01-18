/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:24:09 by fboumell          #+#    #+#             */
/*   Updated: 2022/01/18 17:24:26 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = (void *)malloc(size * count);
	if (!s)
		return (NULL);
	ft_bzero(s, size * count);
	return (s);
}