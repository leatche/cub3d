/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:20:37 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/11 17:39:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_loop(t_value *value);

int	main(int ac, char **av)
{
	t_value		*value;

	value = calloc(1, sizeof(t_value));
	value->parsing = calloc(1, sizeof(t_parsing));
	if (ac == 2 && ft_extension(av[1]) == GOOD && (ft_open(av[1], value->parsing) != -1))
	{
		if (ft_parsing(value, value->parsing) == -1)
			return (ft_free_parsing(value->parsing));
		printf("Player: [%.2f, %.2f] | %.2f deg\n", value->player->pos.x, value->player->pos.y, value->player->orientation);
		ft_make_cub(value);
	}
	else
		ft_print("Check again your file or the number of arguments !");
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

t_color random_color()
{
	t_color dest;

	dest.r = rand() % 255;
	dest.g = rand() % 255;
	dest.b = rand() % 255;
	return dest;
}

int	ft_loop(t_value *value)
{
	ft_handle_rotation(value);
	ft_handle_up_and_down(value);
	ft_handle_right_and_left(value);
	//value->player->color = random_color();
	ft_draw_walls(value);
	mlx_put_image_to_window(value->mlx, value->window, value->img, 0, 0);
	return (1);
}

// int ft_loop(t_value *value)
// {
// 	if (value->keys.turn_left)
// 		value->player->orientation += 5;
// 	if (value->keys.turn_right)
// 		value->player->orientation -= 5;
// 	if (value->keys.go_forward) {
// 		value->player->pos.x += cos(value->player->orientation / 360 * (2 * PI)) / 30;
// 		value->player->pos.y += -sin(value->player->orientation / 360 * (2 * PI)) / 30;
// 	}
// 	if (value->keys.go_backward) {
// 		value->player->pos.x -= cos(value->player->orientation / 360 * (2 * PI)) / 30;
// 		value->player->pos.y -= -sin(value->player->orientation / 360 * (2 * PI)) / 30;
// 	}
// 	if (value->keys.go_left) {
// 		value->player->pos.x += cos((value->player->orientation + 90) / 360 * (2 * PI)) / 30;
// 		value->player->pos.y += -sin((value->player->orientation + 90) / 360 * (2 * PI)) / 30;
// 	}
// 	if (value->keys.go_right) {
// 		value->player->pos.x += cos((value->player->orientation - 90) / 360 * (2 * PI)) / 30;
// 		value->player->pos.y += -sin((value->player->orientation - 90) / 360 * (2 * PI)) / 30;
// 	}
// 	value->player->color = random_color();
// 	ft_draw_map(value);
// 	return (1);
// }

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
void	ft_init(t_value *value)
{
	int bits_per_pixel;
	int	size_line;
	int	endian;
	t_render3d	*r;

	r = &value->render3d;
	value->mlx = mlx_init();
	value->width = 1920;
	value->height = 1080;
	value->window = mlx_new_window(value->mlx, value->width,
			value->height, "cub3d");
	value->img = mlx_new_image(value->mlx, value->width, value->height);
	value->draw = (t_color *)mlx_get_data_addr(value->img, &bits_per_pixel, &size_line, &endian);
	load_textures(value, r);
	mlx_do_key_autorepeatoff(value->mlx);
	//mlx_hook(value->window, 22, 0, mlx_resize_handler, value);
	mlx_hook(value->window, 33, 1L << 17, mlx_loop_end, value->mlx);
	mlx_hook(value->window, KEY_PRESS_ID, KEY_PRESS_MASK, key_press, value);
	mlx_hook(value->window, KEY_RELEASE_ID, KEY_RELEASE_MASK, key_release, value);
	mlx_loop_hook(value->mlx, ft_loop, value);
}

void	ft_free_value(t_value *value)
{
	mlx_do_key_autorepeaton(value->mlx);
	mlx_destroy_image(value->mlx, value->img);
	 mlx_destroy_image(value->mlx, value->render3d.texture_north.img_ptr);
    mlx_destroy_image(value->mlx, value->render3d.texture_south.img_ptr);
    mlx_destroy_image(value->mlx, value->render3d.texture_east.img_ptr);
    mlx_destroy_image(value->mlx, value->render3d.texture_west.img_ptr);
	mlx_destroy_window(value->mlx, value->window);
	mlx_destroy_display(value->mlx);
	// ft_free_tab((void **)value->tab);
	free(value->mlx);
	free(value->player);
	free(value);
}
