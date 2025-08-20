/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:42:58 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/20 17:23:07 by tcherepoff       ###   ########.fr       */
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
			ft_put_square(value, x * GRID_SIZE, y * GRID_SIZE, GRID_SIZE - 1, col);
			x++;
		}
		y++;
	}
	ft_put_circle(value, value->parsing->player->pos_x * GRID_SIZE - (GRID_SIZE / 16), value->parsing->player->pos_y * GRID_SIZE - (GRID_SIZE / 16), GRID_SIZE / 8, color(255, 0, 0));
}
