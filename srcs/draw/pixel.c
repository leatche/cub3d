/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:23:17 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/25 22:42:16 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_put_pixel(t_value *value, t_point pos, t_color color)
{
	if (pos.x < 0 || pos.x >= value->width || pos.y < 0
		|| pos.y >= value->height)
		return ;
	value->draw[(int)pos.x + (int)pos.y * value->width] = color;
}

void	ft_put_square(t_value *value, t_point pos, int size, t_color color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_put_pixel(value, point(pos.x + j, pos.y + i), color);
			j++;
		}
		i++;
	}
}

void	ft_put_circle(t_value *value, t_point pos, int size, t_color color)
{
	double	angle;
	double	i;
	double	j;
	double	x;

	x = -size - 1;
	angle = 0;
	while (x <= size)
	{
		angle = 0;
		while (angle < 360)
		{
			angle += (1.0 / size);
			i = cos((angle / 360) * (2 * PI)) * x;
			j = sin((angle / 360) * (2 * PI)) * x;
			ft_put_pixel(value, point(pos.x + i, pos.y + j), color);
		}
		x++;
	}
}

void	ft_put_line(t_value *value, t_point start, t_point end, t_color color)
{
	double	dx;
	double	dy;
	int		step;
	int		i;

	dx = end.x - start.x;
	dy = end.y - start.y;
	if (abs((int)dx) > abs((int)dy))
		step = abs((int)dx);
	else
		step = abs((int)dy);
	dx /= step;
	dy /= step;
	i = 0;
	while (i < step)
	{
		ft_put_pixel(value, point(round(start.x + (dx * i)),
				round(start.y + (dy * i))), color);
		i++;
	}
}
