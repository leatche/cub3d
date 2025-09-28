/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:20:37 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/09/28 12:51:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	ft_draw_map(value);
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
	value->player->color = random_color();
	ft_draw_map(value);
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

void	ft_init(t_value *value)
{
	int t;

	value->mlx = mlx_init();
	value->width = 1199;
	value->height = 599;
	value->window = mlx_new_window(value->mlx, value->width,
			value->height, "cub3d");
	value->img = mlx_new_image(value->mlx, value->width, value->height);
	value->draw = (t_color *)mlx_get_data_addr(value->img, &t, &t, &t);
	mlx_do_key_autorepeatoff(value->mlx);
	mlx_hook(value->window, 33, 1L << 17, mlx_loop_end, value->mlx);
	mlx_hook(value->window, KEY_PRESS_ID, KEY_PRESS_MASK, key_press, value);
	mlx_hook(value->window, KEY_RELEASE_ID, KEY_RELEASE_MASK, key_release, value);
	mlx_loop_hook(value->mlx, ft_loop, value);
}

void	ft_free_value(t_value *value)
{
	mlx_do_key_autorepeaton(value->mlx);
	mlx_destroy_image(value->mlx, value->img);
	mlx_destroy_window(value->mlx, value->window);
	mlx_destroy_display(value->mlx);
	// ft_free_tab((void **)value->tab);
	free(value->mlx);
	free(value->player);
	free(value);
}
