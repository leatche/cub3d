/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbehar <sbehar@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:08:18 by sbehar            #+#    #+#             */
/*   Updated: 2025/10/13 13:15:17 by sbehar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_one_minimap_cell(t_value *value, t_minimap *minimap, int x, int y)
{
	t_color	color;

	update_map_pos(value->player, minimap, x, y);
	if (minimap->py >= 0 && minimap->py < minimap->map_height
		&& minimap->px >= 0 && minimap->px < minimap->map_width)
	{
		if (value->parsing->map[minimap->py][minimap->px])
		{
			color = get_minimap_cell_color(value,
					value->parsing->map[minimap->py][minimap->px]);
			value->draw[(minimap->cy + y)
				* value->width + minimap->cx + x] = color;
		}
	}
}
