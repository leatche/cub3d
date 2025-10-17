/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbehar <sbehar@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:08:18 by sbehar            #+#    #+#             */
/*   Updated: 2025/10/17 18:18:52 by sbehar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_draw_one_minimap_cell(t_value *value, t_minimap *mmap, int x, int y)
{
	t_color	color;

	ft_update_map_pos(value->player, mmap, x, y);
	if (mmap->py >= 0 && mmap->py < mmap->map_height
		&& mmap->px >= 0 && mmap->px < mmap->map_width)
	{
		if (value->parsing->map[mmap->py][mmap->px])
		{
			color = ft_get_minimap_cell_color(value,
					value->parsing->map[mmap->py][mmap->px]);
			value->draw[(mmap->cy + y)
				* value->width + mmap->cx + x] = color;
		}
	}
}
