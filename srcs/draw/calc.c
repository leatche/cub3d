/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 23:46:45 by marvin            #+#    #+#             */
/*   Updated: 2025/09/30 23:46:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_calc_tex_x(t_texture *texture, t_rayhit *hit)
{
	double	wall_hit;
	int		tex_x;

	if (hit->side == 0)
		wall_hit = hit->y - floor(hit->y);
	else
		wall_hit = hit->x - floor(hit->x);
	tex_x = (int)(wall_hit * texture->width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= texture->width)
		tex_x = texture->width - 1;
	return (tex_x);
}

double	ft_calc_ray_angle(t_render3d *r, int i)
{
	return (r->start_angle + ((double)i / (r->rays - 1)) * r->fov);
}

double	ft_cast_ray(t_value *v, double ray_angle, t_rayhit *hit)
{
	return (ft_dda_ray(v, ft_deg_to_rad(ray_angle), hit));
}

double	ft_calc_corr_dist(double dist, double ray_angle_rad, double player_ang)
{
	double	corrected_dist;

	corrected_dist = dist * cos(ray_angle_rad - player_ang);
	if (corrected_dist < 0.001)
		corrected_dist = 0.001;
	return (corrected_dist);
}

void	ft_calc_draw_lim(t_render3d *r, double c_dst, int *draw_s, int *draw_e)
{
	int	wall_height;

	wall_height = (int)(r->win_height / c_dst);
	*draw_s = (r->win_height / 2) - (wall_height / 2);
	*draw_e = *draw_s + wall_height;
}
