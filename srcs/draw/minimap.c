/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:21:13 by marvin            #+#    #+#             */
/*   Updated: 2025/10/12 15:21:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_minimap_circle(t_value *value, t_minimap *minimap, int color)
{
	t_color	c_color;
	int		x;
	int		y;

	c_color = int_to_t_color(color);
	y = -minimap->radius;
	while (y <= minimap->radius)
	{
		x = -minimap->radius;
		while (x <= minimap->radius)
		{
			if (x * x + y * y <= minimap->radius * minimap->radius)
			{
				value->draw[(minimap->cy + y) * value->width
					+ minimap->cx + x] = c_color;
			}
			x++;
		}
		y++;
	}
}

void	draw_minimap_player(t_value *value, t_minimap *minimap)
{
	int		dx;
	int		dy;
	t_color	color;

	color = int_to_t_color(0xFFFF00);
	dx = -2;
	while (dx <= 2)
	{
		dy = -2;
		while (dy <= 2)
		{
			if (dx * dx + dy * dy < 9)
				value->draw[(minimap->cy + dy)
					* value->width + minimap->cx + dx] = color;
			dy++;
		}
		dx++;
	}
}

void	draw_minimap_cells(t_value *value, t_minimap *minimap)
{
	int	x;
	int	y;
	int	r;

	r = minimap->radius;
	y = -r;
	while (y <= r)
	{
		x = -r;
		while (x <= r)
		{
			if (x * x + y * y <= r * r)
				draw_one_minimap_cell(value, minimap, x, y);
			x++;
		}
		y++;
	}
}

void	draw_minimap_map(t_value *value, t_minimap *minimap)
{
	draw_minimap_cells(value, minimap);
	draw_minimap_player(value, minimap);
}

void	draw_minimap_compass(t_value *value, t_minimap *minimap)
{
	int		cx;
	int		cy;
	int		r;
	float	a;

	cx = minimap->cx;
	cy = minimap->cy;
	r = minimap->radius + 12;
	a = value->player->orientation * PI / 180.0f;
	mlx_string_put(value->mlx, value->window, cx + (int)(sin(a) * r),
		cy - (int)(cos(a) * r), 0xFFFFFF, "N");
	mlx_string_put(value->mlx, value->window, cx - (int)(sin(a) * r),
		cy + (int)(cos(a) * r), 0xFFFFFF, "S");
	mlx_string_put(value->mlx, value->window, cx - (int)(cos(a) * r),
		cy - (int)(sin(a) * r), 0xFFFFFF, "w");
	mlx_string_put(value->mlx, value->window, cx + (int)(cos(a) * r),
		cy + (int)(sin(a) * r), 0xFFFFFF, "E");
}
