/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:35:38 by marvin            #+#    #+#             */
/*   Updated: 2025/09/30 23:35:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_draw_v_ceiling(t_value *v, int draw_start, t_render3d *r)
{
	t_point	pos;
	int		y;

	y = 0;
	while (y < draw_start)
	{
		pos.x = r->x;
		pos.y = y;
		ft_put_pixel(v, pos, r->ceiling_color);
		y++;
	}
}

void	ft_draw_v_wall(t_value *v, t_setup *set)
{
	int		y;
	int		wall_height;
	int		tex_y;
	int		color;
	t_point	pos;

	wall_height = set->draw_end - set->draw_start + 1;
	y = set->draw_start;
	while (y <= set->draw_end && y < set->r->win_height)
	{
		tex_y = (int)(((double)(y - set->draw_start)
					/ wall_height) * set->texture.height);
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= set->texture.height)
			tex_y = set->texture.height - 1;
		color = set->texture.data[tex_y * set->texture.width + set->tex_x];
		pos.x = set->r->x;
		pos.y = y;
		ft_put_pixel(v, pos, int_to_t_color(color));
		y++;
	}
}

void	ft_draw_v_floor(t_value *v, int draw_end, t_render3d *r)
{
	t_point	pos;
	int		y;

	y = draw_end + 1;
	while (y < r->win_height)
	{
		pos.x = r->x;
		pos.y = y;
		ft_put_pixel(v, pos, r->floor_color);
		y++;
	}
}

void	ft_draw_v_line(t_value *v, t_setup *set)
{
	ft_draw_v_ceiling(v, set->draw_start, set->r);
	ft_draw_v_wall(v, set);
	ft_draw_v_floor(v, set->draw_end, set->r);
}
