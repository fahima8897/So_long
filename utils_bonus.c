/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fboumell <fboumell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:45:00 by fboumell          #+#    #+#             */
/*   Updated: 2022/02/01 16:49:00 by fboumell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	char	*b;

	b = s;
	while (n)
	{
		*b = '\0';
		b++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	s = (void *)malloc(size * count);
	if (!s)
		return (NULL);
	ft_bzero(s, size * count);
	return (s);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static int	ft_count(int n)
{
	int	size;

	if (n <= 0)
		size = 1;
	else
		size = 0;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char		*new;
	int			len;
	int long	c;

	c = n;
	if (c < 0)
		c = -c;
	len = ft_count(n);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	new[len] = '\0';
	if (c == 0)
		new[0] = '0';
	while ((len - 1) >= 0)
	{
		new[len - 1] = c % 10 + '0';
		c = c / 10;
		len --;
	}
	if (n < 0)
		new[0] = '-';
	return (new);
}
