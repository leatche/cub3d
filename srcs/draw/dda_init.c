/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 13:54:23 by marvin            #+#    #+#             */
/*   Updated: 2025/09/28 13:54:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_dda_init_x(t_dda *param)
{
	if (param->ray_dir_x == 0)
		param->delta_dist_x = 1e30;
	else
		param->delta_dist_x = fabs(1 / param->ray_dir_x);
	if (param->ray_dir_x < 0)
	{
		param->step_x = -1;
		param->side_dist_x = (param->player_x - param->map_x)
			* param->delta_dist_x;
	}
	else
	{
		param->step_x = 1;
		param->side_dist_x = (param->map_x + 1.0 - param->player_x)
			* param->delta_dist_x;
	}
}

void	ft_dda_init_y(t_dda *param)
{
	if (param->ray_dir_y == 0)
		param->delta_dist_y = 1e30;
	else
		param->delta_dist_y = fabs(1 / param->ray_dir_y);
	if (param->ray_dir_y < 0)
	{
		param->step_y = -1;
		param->side_dist_y = (param->player_y - param->map_y)
			* param->delta_dist_y;
	}
	else
	{
		param->step_y = 1;
		param->side_dist_y = (param->map_y + 1.0 - param->player_y)
			* param->delta_dist_y;
	}
}

void	ft_dda_init(t_value *value, double ray_angle, t_dda *param)
{
	param->player_x = value->player->pos.x;
	param->player_y = value->player->pos.y;
	param->map_x = (int)(param->player_x);
	param->map_y = (int)(param->player_y);
	param->ray_dir_x = cos(ray_angle);
	param->ray_dir_y = -sin(ray_angle);
	ft_dda_init_x(param);
	ft_dda_init_y(param);
	param->hit = 0;
}
