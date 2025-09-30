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

double	ft_calc_ray_angle(t_render3d *r, int i);
double	ft_cast_ray(t_value *v, double ray_angle);
double	ft_calc_corr_dist(double dist, double ray_angle_rad, double player_ang);
void	ft_calc_draw_lim(t_render3d *r, double c_dst, int *draw_s, int *draw_e);

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
	r->rays = WIN_WIDTH;
	r->start_angle = v->player->orientation - r->fov / 2.0;
	r->player_angle_rad = ft_deg_to_rad(v->player->orientation);
	r->win_height = WIN_HEIGHT;
	r->wall_color = int_to_t_color(COLOR_WALL);
	r->floor_color = v->parsing->floor_color;
	r->ceiling_color = v->parsing->ceiling_color;
}

void	ft_draw_wall_column(t_value *v, t_render3d *r, int i)
{
	double	ray_angle;
	double	dist;
	double	corrected_dist;
	int		draw_start;
	int		draw_end;

	ray_angle = ft_calc_ray_angle(r, i);
	dist = ft_cast_ray(v, ray_angle);
	corrected_dist = ft_calc_corr_dist(dist, ft_deg_to_rad(ray_angle),
			r->player_angle_rad);
	ft_calc_draw_lim(r, corrected_dist, &draw_start, &draw_end);
	ft_draw_v_line(v, draw_start, draw_end, r);
}

void	ft_draw_walls(t_value *v)
{
	t_render3d	r;
	int			i;

	i = 0;
	ft_setup_render3d(v, &r);
	while (i < r.rays)
	{
		r.x = i;
		ft_draw_wall_column(v, &r, i);
		i++;
	}
}
