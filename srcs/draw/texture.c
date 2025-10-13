/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:05:14 by marvin            #+#    #+#             */
/*   Updated: 2025/10/11 17:05:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	ft_calc_ray_angle(t_render3d *r, int i);
double	ft_calc_corr_dist(double dist, double ray_angle_rad, double player_ang);
void	ft_calc_draw_lim(t_render3d *r, double c_dst, int *draw_s, int *draw_e);
double	ft_cast_ray(t_value *v, double ray_angle, t_rayhit *hit);
double	ft_normalize_angle(double angle_deg);

int	ft_calc_tex_x(t_render3d *r, t_rayhit *hit)
{
	double	wall_hit;
	int		tex_x;

	if (hit->side == 0)
		wall_hit = hit->y - floor(hit->y);
	else
		wall_hit = hit->x - floor(hit->x);
	tex_x = (int)(wall_hit * r->texture_north.width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= r->texture_north.width)
		tex_x = r->texture_north.width - 1;
	return (tex_x);
}

void	ft_select_texture(t_render3d *r, double ray_an, int side, t_texture *t)
{
	if (side == 0)
	{
		if (ray_an > 90.0 && ray_an < 270.0)
			*t = r->texture_west;
		else
			*t = r->texture_east;
	}
	else
	{
		if (ray_an > 0.0 && ray_an < 180.0)
			*t = r->texture_north;
		else
			*t = r->texture_south;
	}
}

void	ft_calc_ray_params(t_draw *d)
{
	d->ray_angle = ft_calc_ray_angle(d->r, d->i);
	d->corrected_dist = 0.0;
	d->corrected_dist = ft_calc_corr_dist(
			ft_cast_ray(&d->value, d->ray_angle, &d->hit),
			ft_deg_to_rad(d->ray_angle),
			d->r->player_angle_rad);
}

void	ft_calc_draw_params(t_draw *d)
{
	ft_calc_draw_lim(d->r, d->corrected_dist, &d->draw_start, &d->draw_end);
	d->tex_x = ft_calc_tex_x(d->r, &d->hit);
	d->ray_angle = ft_normalize_angle(d->ray_angle);
	ft_select_texture(d->r, d->ray_angle, d->hit.side, &d->texture);
}
