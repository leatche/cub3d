/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:42:58 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/23 23:27:04 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define GRID_SIZE 100

void draw_map(t_value *value)
{
	int x;
	int y;
	t_color col;

	y = 0;
	while(value->parsing->map[y])
	{
		x = 0;
		while(value->parsing->map[y][x])
		{
			if (value->parsing->map[y][x] == '1')
				col = green();
			else if (value->parsing->map[y][x] == '0')
				col = yellow();
			else
				col = color(100, 100, 100);
			ft_put_square(value, point(x * GRID_SIZE, y * GRID_SIZE), GRID_SIZE - 1, col);
			x++;
		}
		y++;
	}
	ft_put_circle(value, point(value->parsing->player->pos.x * GRID_SIZE, value->parsing->player->pos.y * GRID_SIZE), 10, color(255, 0, 0), 1);
	double xx = cos(value->parsing->player->orientation / 360 * (2 * PI));
	double yy = -sin(value->parsing->player->orientation / 360 * (2 * PI));
	xx *= GRID_SIZE;
	yy *= GRID_SIZE;
	xx += value->parsing->player->pos.x * GRID_SIZE;
	yy += value->parsing->player->pos.y * GRID_SIZE;
	ft_put_line(value, point(value->parsing->player->pos.x * GRID_SIZE, value->parsing->player->pos.y * GRID_SIZE), point(xx, yy), color(255, 0, 0));
	mlx_put_image_to_window(value->mlx, value->window, value->img, 0, 0);
}
