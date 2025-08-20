/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:23:17 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/20 17:10:10 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_color color(int r, int g, int b)
{
	t_color dest;

	dest.r = r;
	dest.g = g;
	dest.b = b;
	return (dest);
}

t_color yellow()
{
	t_color dest;

	dest.r = 255;
	dest.g = 255;
	dest.b = 0;
	return (dest);
}
t_color green()
{
	t_color dest;

	dest.r = 0;
	dest.g = 255;
	dest.b = 0;
	return (dest);
}

void ft_put_pixel(t_value *value, int x, int y, t_color color)
{
	if (x < 0 || x >= value->width || y < 0 || y >= value->height)
		return ;
	value->draw[x + y * value->width] = color;
}

void ft_put_square(t_value *value, int x, int y, int size, t_color color)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_put_pixel(value, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
#define PI 3.1415

void ft_put_circle(t_value *value, int x, int y, int size, t_color color)
{
	double angle = 0;
	double i;
	double j;

	(void)size;
	(void)x;
	(void)y;
	x += size / 2;
	y += size / 2;
	while (angle < 360)
	{
		angle += 0.5;
		i = cos((angle / 360) * (2 * PI)) * size;
		j = sin((angle / 360) * (2 * PI)) * size;
		ft_put_pixel(value, x + i, y + j, color);
	}
}
