/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbehar <sbehar@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:05:58 by sbehar            #+#    #+#             */
/*   Updated: 2025/10/17 18:07:19 by sbehar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_minimap_zoom_in(t_minimap *minimap)
{
	if (minimap->scale > 1)
		minimap->scale--;
}

void	ft_minimap_zoom_out(t_minimap *minimap)
{
	if (minimap->scale < 20)
		minimap->scale++;
}

void	ft_update_map_size(t_minimap *minimap, char **map)
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

void	ft_update_map_pos(t_player *player, t_minimap *mmap, int off_x, int off_y)
{
	mmap->px = (int)(player->pos.x + off_x / (float)mmap->scale);
	mmap->py = (int)(player->pos.y + off_y / (float)mmap->scale);
}

t_color	ft_get_minimap_cell_color(t_value *value, char c)
{
	if (c == '1')
		return (value->parsing->ceiling);
	return (value->parsing->floor);
}
