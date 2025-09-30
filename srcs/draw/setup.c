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

void	ft_draw_v_wall(t_value *v, int draw_start, int draw_end, t_render3d *r)
{
	t_point	pos;
	int		y;

	y = draw_start;
	while (y <= draw_end && y < r->win_height)
	{
		pos.x = r->x;
		pos.y = y;
		ft_put_pixel(v, pos, r->wall_color);
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

void	ft_draw_v_line(t_value *v, int draw_start, int draw_end, t_render3d *r)
{
	ft_draw_v_ceiling(v, draw_start, r);
	ft_draw_v_wall(v, draw_start, draw_end, r);
	ft_draw_v_floor(v, draw_end, r);
}
