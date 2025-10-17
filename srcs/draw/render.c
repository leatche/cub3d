/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:43:00 by marvin            #+#    #+#             */
/*   Updated: 2025/09/30 23:43:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_color	int_to_t_color(int rgb)
{
	t_color	color;

	color.r = (rgb >> 16) & 0xFF;
	color.g = (rgb >> 8) & 0xFF;
	color.b = rgb & 0xFF;
	return (color);
}

void	ft_setup_render3d(t_value *v, t_render3d *r)
{
	r->fov = 60.0;
	r->rays = v->width;
	r->start_angle = v->player->orientation - r->fov / 2.0;
	r->player_angle_rad = ft_deg_to_rad(v->player->orientation);
	r->win_height = v->height;
	r->floor_color = v->parsing->floor;
	r->ceiling_color = v->parsing->ceiling;
}

double	ft_normalize_angle(double angle_deg)
{
	while (angle_deg < 0)
		angle_deg += 360;
	while (angle_deg >= 360)
		angle_deg -= 360;
	return (angle_deg);
}

void	ft_draw_wall_column(t_value *v, t_render3d *r, int i)
{
	t_draw	d;
	t_setup	set;

	d.value = *v;
	d.r = r;
	d.i = i;
	ft_calc_ray_params(&d);
	ft_calc_draw_params(&d);
	set.draw_start = d.draw_start;
	set.draw_end = d.draw_end;
	set.r = r;
	set.tex_x = d.tex_x;
	set.texture = d.texture;
	ft_draw_v_line(v, &set);
}

void	ft_draw_walls(t_value *v)
{
	t_render3d	*r;
	int			i;

	r = &v->render3d;
	i = 0;
	ft_setup_render3d(v, r);
	while (i < r->rays)
	{
		r->x = i;
		ft_draw_wall_column(v, r, i);
		i++;
	}
}
