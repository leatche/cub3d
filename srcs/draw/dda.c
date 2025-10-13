/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 12:59:09 by marvin            #+#    #+#             */
/*   Updated: 2025/09/28 12:59:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_dda_step(t_value *value, t_dda *param)
{
	if (param->side_dist_x < param->side_dist_y)
	{
		param->side_dist_x += param->delta_dist_x;
		param->map_x += param->step_x;
		param->side = 0;
	}
	else
	{
		param->side_dist_y += param->delta_dist_y;
		param->map_y += param->step_y;
		param->side = 1;
	}
	if (param->map_y < 0 || param->map_y >= ft_size_tab(value->parsing->map)
		|| param->map_x < 0
		|| param->map_x >= (int)ft_strlen(value->parsing->map[0]))
		param->hit = 1;
	else if (value->parsing->map[param->map_y][param->map_x] == '1')
		param->hit = 1;
}

double	ft_dda_calc_dist(t_dda *param)
{
	if (param->side == 0)
		return ((param->map_x - param->player_x
				+ (1 - param->step_x) / 2) / param->ray_dir_x);
	else
		return ((param->map_y - param->player_y
				+ (1 - param->step_y) / 2) / param->ray_dir_y);
}

double	ft_dda_ray(t_value *va, double ray_angle, t_rayhit *res)
{
	t_dda	dda;

	ft_dda_init(va, ray_angle, &dda);
	while (!dda.hit)
		ft_dda_step(va, &dda);
	dda.dist = ft_dda_calc_dist(&dda);
	res->x = dda.player_x + dda.ray_dir_x * dda.dist;
	res->y = dda.player_y + dda.ray_dir_y * dda.dist;
	res->side = dda.side;
	res->dist = dda.dist;
	return (dda.dist);
}
