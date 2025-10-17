/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbehar <sbehar@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:20:37 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/17 18:15:57 by sbehar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_loop(t_value *value);

int	main(int ac, char **av)
{
	t_value		*value;

	if (ac != 2)
	{
		ft_print("Check again the number of arguments !");
		return (-1);
	}
	value = ft_calloc(1, sizeof(t_value));
	value->parsing = pars_file(av[1]);
	if (!value->parsing)
	{
		free(value);
		return (1);
	}
	if (ft_parsing(value) == -1)
	{
		ft_free_error(value);
		return (0);
	}
	ft_make_cub(value);
	ft_free_parsing(value->parsing);
	ft_free_value(value);
	return (0);
}

void	ft_make_cub(t_value *value)
{
	if (ft_init(value) == BAD)
		return ;
	//ft_draw_map(value);
	mlx_loop_hook(value->mlx, ft_loop, value);
	mlx_loop(value->mlx);
}


int	load_textures(t_value *value, t_render3d *r)
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
	r->texture_north.data = (int *)mlx_get_data_addr(r->texture_north.img_ptr, &r->texture_north.bpp, &r->texture_north.size_line, &r->texture_north.endian);
	r->texture_south.data = (int *)mlx_get_data_addr(r->texture_south.img_ptr, &r->texture_south.bpp, &r->texture_south.size_line, &r->texture_south.endian);
	r->texture_east.data = (int *)mlx_get_data_addr(r->texture_east.img_ptr, &r->texture_east.bpp, &r->texture_east.size_line, &r->texture_east.endian);
	r->texture_west.data = (int *)mlx_get_data_addr(r->texture_west.img_ptr, &r->texture_west.bpp, &r->texture_west.size_line, &r->texture_west.endian);
	return (GOOD);
}

int	ft_init(t_value *value)
{
	int bits_per_pixel;
	int	size_line;
	int	endian;
	t_render3d	*r;

	r = &value->render3d;
	value->mlx = mlx_init();
	mlx_get_screen_size(value->mlx, &value->width, &value->height);
	value->window = mlx_new_window(value->mlx, value->width,
			value->height, "cub3d");
	ft_init_mouse(value);
	value->draw = (t_color *)mlx_get_data_addr(value->img, &bits_per_pixel, &size_line, &endian);
	if (load_textures(value, r) == BAD)
		return (BAD);
	mlx_do_key_autorepeatoff(value->mlx);
	value->first_mouse = 1;
	mlx_hook(value->window, 6, 1L << 6, ft_mouse_move, value);
	mlx_hook(value->window, 33, 1L << 17, mlx_loop_end, value->mlx);
	mlx_hook(value->window, KEY_PRESS_ID, (1L<<0), key_press, value);
	mlx_hook(value->window, KEY_RELEASE_ID, (1L<<1), key_release, value);
	mlx_loop_hook(value->mlx, ft_loop, value);
	mlx_mouse_hide(value->mlx, value->window);
	mlx_mouse_move(value->mlx, value->window, value->window_center_x, value->window_center_y);
	return (GOOD);
}
