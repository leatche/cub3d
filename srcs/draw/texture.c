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

int	ft_load_textures_img(t_value *value, t_render3d *r)
{
	r->texture_north.img_ptr = mlx_xpm_file_to_image(value->mlx,
			value->parsing->textures[NORTH],
			&r->texture_north.width, &r->texture_north.height);
	r->texture_south.img_ptr = mlx_xpm_file_to_image(value->mlx,
			value->parsing->textures[SOUTH],
			&r->texture_south.width, &r->texture_south.height);
	r->texture_east.img_ptr = mlx_xpm_file_to_image(value->mlx,
			value->parsing->textures[EAST],
			&r->texture_east.width, &r->texture_east.height);
	r->texture_west.img_ptr = mlx_xpm_file_to_image(value->mlx,
			value->parsing->textures[WEST],
			&r->texture_west.width, &r->texture_west.height);
	if (!r->texture_north.img_ptr || !r->texture_south.img_ptr
		|| !r->texture_east.img_ptr || !r->texture_west.img_ptr)
	{
		ft_print("At least one texture is wrongly formated");
		return (BAD);
	}
	return (GOOD);
}

void	ft_load_textures_data(t_render3d *r)
{
	r->texture_north.data = (int *)mlx_get_data_addr(r->texture_north.img_ptr,
			&r->texture_north.bpp, &r->texture_north.size_line,
			&r->texture_north.endian);
	r->texture_south.data = (int *)mlx_get_data_addr(r->texture_south.img_ptr,
			&r->texture_south.bpp, &r->texture_south.size_line,
			&r->texture_south.endian);
	r->texture_east.data = (int *)mlx_get_data_addr(r->texture_east.img_ptr,
			&r->texture_east.bpp, &r->texture_east.size_line,
			&r->texture_east.endian);
	r->texture_west.data = (int *)mlx_get_data_addr(r->texture_west.img_ptr,
			&r->texture_west.bpp, &r->texture_west.size_line,
			&r->texture_west.endian);
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
	d->ray_angle = ft_normalize_angle(d->ray_angle);
	ft_select_texture(d->r, d->ray_angle, d->hit.side, &d->texture);
	d->tex_x = ft_calc_tex_x(&d->texture, &d->hit);
}
