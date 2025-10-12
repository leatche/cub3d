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
	int	x;
	int	y;
	t_color	c_color;

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
	int	dx;
	int	dy;
	t_color	color;

	color = int_to_t_color(0xFFFF00);
	dx = -2;
	while (dx <= 2)
	{
		dy = -2;
		while (dy <= 2)
		{
			if (dx * dx + dy * dy < 9)
				value->draw[(minimap->cy + dy) * value->width + minimap->cx + dx] = color;
			dy++;
		}
		dx++;
	}
}

int	get_minimap_cell_color(char c)
{
	if (c == '1')
		return (0xAAAAAA);
	return (0x333333);
}


void	update_map_size(t_minimap *minimap, char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	minimap->map_height = height;
	if (height > 0)
		minimap->map_width = (int)ft_strlen(map[0]);
	else
		minimap->map_width = 0;
}

void	update_map_pos(t_player *player, t_minimap *minimap, int offset_x, int offset_y)
{
	minimap->px = (int)(player->pos.x + offset_x / (float)minimap->scale);
	minimap->py = (int)(player->pos.y + offset_y / (float)minimap->scale);
}

void	draw_one_minimap_cell(t_value *value, t_minimap *minimap, int x, int y)
{
	int	col;
	t_color	color;

	update_map_pos(value->player, minimap, x, y);
	if (minimap->py >= 0 && minimap->py < minimap->map_height
		&& minimap->px >= 0 && minimap->px < minimap->map_width)
	{
		if (value->parsing->map[minimap->py][minimap->px])
		{
			col = get_minimap_cell_color(value->parsing->map[minimap->py][minimap->px]);
			color = int_to_t_color(col);
			value->draw[(minimap->cy + y) * value->width + minimap->cx + x] = color;
		}
	}
}

// void	draw_one_minimap_cell(t_value *value, t_minimap *minimap, int x, int y)
// {
// 	int	px;
// 	int	py;
// 	int	col;
// 	t_color	color;
// 	int	map_height;
// 	int	map_width;

// 	map_height = 0;
// 	map_width = 0;
// 	while (value->parsing->map[map_height])
// 		map_height++;
// 	if (map_height > 0)
// 		map_width = (int)ft_strlen(value->parsing->map[0]);
// 	px = (int)(value->player->pos.x + x / (float)minimap->scale);
// 	py = (int)(value->player->pos.y + y / (float)minimap->scale);
// 	if (py >= 0 && py < map_height && px >= 0 && px < map_width)
// 	{
// 		if (value->parsing->map[py][px])
// 		{
// 			col = get_minimap_cell_color(value->parsing->map[py][px]);
// 			color = int_to_t_color(col);
// 			value->draw[(minimap->cy + y) * value->width + minimap->cx + x] = color;
// 		}
// 	}
// }

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
	int	cx;
	int	cy;
	int	r;
	float	a;

	cx = minimap->cx;
	cy = minimap->cy;
	r = minimap->radius + 12;
	a = value->player->orientation * PI / 180.0f;
	mlx_string_put(value->mlx, value->window, cx + (int)(sin(a) * r), cy - (int)(cos(a) * r), 0xFFFFFF, "N");
	mlx_string_put(value->mlx, value->window, cx - (int)(sin(a) * r), cy + (int)(cos(a) * r), 0xFFFFFF, "S");
	mlx_string_put(value->mlx, value->window, cx - (int)(cos(a) * r), cy - (int)(sin(a) * r), 0xFFFFFF, "w");
	mlx_string_put(value->mlx, value->window, cx + (int)(cos(a) * r), cy + (int)(sin(a) * r), 0xFFFFFF, "E");
}
