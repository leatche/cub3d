/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbehar <sbehar@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 03:58:54 by sbehar            #+#    #+#             */
/*   Updated: 2025/09/17 03:58:54 by sbehar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	ft_ray_angle(double player_orientation, double fov, int rays, int i)
{
	double	start_angle;
	double	step;

	start_angle = player_orientation - fov / 2.0;
	step = fov / (rays - 1);
	return (start_angle + i * step);
}

double	ft_deg_to_rad(double angle_deg)
{
	return ((angle_deg / 360.0) * (2 * PI));
}

t_point	ft_ray_target_point(t_point origin, double angle_rad, double length)
{
	double	dx;
	double	dy;

	dx = cos(angle_rad) * length;
	dy = -sin(angle_rad) * length;
	return (point(origin.x + dx, origin.y + dy));
}

void	ft_draw_one_ray(t_value *v, t_point origin, double angle_deg, double l)
{
	double	angle_rad;
	t_point	end;

	angle_rad = ft_deg_to_rad(angle_deg);
	end = ft_ray_target_point(origin, angle_rad, l);
	ft_put_line(v, origin, end, color(255, 200, 0));
}

void	ft_draw_rays(t_value *value)
{
	double	fov;
	double	angle_deg;
	int		rays;
	int		i;
	t_point	player_center;

	fov = 60.0;
	rays = 50;
	player_center = point(value->player->pos.x * GRID_SIZE,
			value->player->pos.y * GRID_SIZE);
	i = 0;
	while (i < rays)
	{
		angle_deg = ft_ray_angle(value->player->orientation, fov, rays, i);
		ft_draw_one_ray(value, player_center, angle_deg, GRID_SIZE);
		i++;
	}
}
