/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:20:37 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/16 19:24:46 by tcherepoff       ###   ########.fr       */
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
	value = calloc(1, sizeof(t_value));
	value->parsing = calloc(1, sizeof(t_parsing));
	if (ft_extension(av[1]) == GOOD && (ft_open(av[1], value->parsing) != -1))
	{
		if (ft_parsing(value, value->parsing) == -1)
			return (ft_free_error(value));
		ft_make_cub(value);
	}
	else
		return (ft_free_error(value));
	ft_free_parsing(value->parsing);
	ft_free_value(value);
	return (0);
}

void	ft_make_cub(t_value *value)
{
	ft_init(value);
	//ft_draw_map(value);
	mlx_loop_hook(value->mlx, ft_loop, value);
	mlx_loop(value->mlx);
}


void	load_textures(t_value *value, t_render3d *r)
{
	r->texture_north.img_ptr = mlx_xpm_file_to_image(value->mlx, "textures/texture_nord.xpm", &r->texture_north.width, &r->texture_north.height);
	r->texture_north.data = (int *)mlx_get_data_addr(r->texture_north.img_ptr, &r->texture_north.bpp, &r->texture_north.size_line, &r->texture_north.endian);
	r->texture_south.img_ptr = mlx_xpm_file_to_image(value->mlx, "textures/texture_sud.xpm", &r->texture_south.width, &r->texture_south.height);
	r->texture_south.data = (int *)mlx_get_data_addr(r->texture_south.img_ptr, &r->texture_south.bpp, &r->texture_south.size_line, &r->texture_south.endian);
	r->texture_east.img_ptr = mlx_xpm_file_to_image(value->mlx, "textures/texture_east.xpm", &r->texture_east.width, &r->texture_east.height);
	r->texture_east.data = (int *)mlx_get_data_addr(r->texture_east.img_ptr, &r->texture_east.bpp, &r->texture_east.size_line, &r->texture_east.endian);
	r->texture_west.img_ptr = mlx_xpm_file_to_image(value->mlx, "textures/texture_west.xpm", &r->texture_west.width, &r->texture_west.height);
	r->texture_west.data = (int *)mlx_get_data_addr(r->texture_west.img_ptr, &r->texture_west.bpp, &r->texture_west.size_line, &r->texture_west.endian);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_value *value;

	value = (t_value *)param;
	(void)x;
	(void)y;
	if (button == 4)
		minimap_zoom_in(&value->minimap);
	else if (button == 5)
		minimap_zoom_out(&value->minimap);
	return (0);
}

void	update_player_orientation(t_value *value, int xoffset)
{
	double	sensitivity;
	double	rotation;

	sensitivity = 0.01f;
	rotation = xoffset * sensitivity;
	value->player->orientation += rotation;
}

int	mouse_move(int x, int y, t_value *value)
{
	int	offset;

	(void)y;
	if (!value->mouse_on)
		return (0);
	offset = x - value->window_center_x;
	if (offset != 0)
		update_player_orientation(value, offset);
	mlx_mouse_move(value->mlx, value->window, value->window_center_x, value->window_center_y);
	return (0);
}

void	ft_init(t_value *value)
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
	value->window_center_x = value->width / 2;
	value->window_center_y = value->height / 2;
	value->mouse_on = 1;
	value->img = mlx_new_image(value->mlx, value->width, value->height);
	value->draw = (t_color *)mlx_get_data_addr(value->img, &bits_per_pixel, &size_line, &endian);
	value->minimap.cx = 110;
	value->minimap.cy = 110;
	value->minimap.radius = 80;
	value->minimap.scale = 6;
	mlx_mouse_hook(value->window, mouse_hook, value);
	update_map_size(&value->minimap, value->parsing->map);
	load_textures(value, r);
	mlx_do_key_autorepeatoff(value->mlx);
	value->first_mouse = 1;
	mlx_hook(value->window, 6, 1L << 6, mouse_move, value);
	mlx_hook(value->window, 33, 1L << 17, mlx_loop_end, value->mlx);
	mlx_hook(value->window, KEY_PRESS_ID, KEY_PRESS_MASK, key_press, value);
	mlx_hook(value->window, KEY_RELEASE_ID,
		KEY_RELEASE_MASK, key_release, value);
	mlx_loop_hook(value->mlx, ft_loop, value);
	mlx_mouse_hide(value->mlx, value->window);
	mlx_mouse_move(value->mlx, value->window, value->window_center_x, value->window_center_y);
}
