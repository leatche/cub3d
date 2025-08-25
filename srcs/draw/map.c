/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:42:58 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/25 22:34:58 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_draw_map(t_value *value)
{
	ft_print_map(value);
	ft_print_player(value);
	mlx_put_image_to_window(value->mlx, value->window, value->img, 0, 0);
}

void	ft_print_map(t_value *value)
{
	int		x;
	int		y;
	t_color	col;

	y = 0;
	while (value->parsing->map[y])
	{
		x = 0;
		while (value->parsing->map[y][x])
		{
			if (value->parsing->map[y][x] == '1')
				col = green();
			else if (value->parsing->map[y][x] == '0')
				col = yellow();
			else
				col = color(100, 100, 100);
			ft_put_square(value, point(x * GRID_SIZE, y * GRID_SIZE),
				GRID_SIZE - 1, col);
			x++;
		}
		y++;
	}
}

void	ft_print_player(t_value *value)
{
	double	x;
	double	y;

	ft_put_circle(value, point(value->player->pos.x * GRID_SIZE,
			value->player->pos.y * GRID_SIZE), 10, color(255, 0, 0));
	x = (cos(value->player->orientation / 360 * (2 * PI)));
	y = -(sin(value->player->orientation / 360 * (2 * PI)));
	x *= GRID_SIZE;
	y *= GRID_SIZE;
	x += value->player->pos.x * GRID_SIZE;
	y += value->player->pos.y * GRID_SIZE;
	ft_put_line(value, point(value->player->pos.x * GRID_SIZE,
			value->player->pos.y * GRID_SIZE),
		point(x, y), color(255, 0, 0));
}
