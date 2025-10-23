/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbehar <sbehar@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:20:37 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/23 14:32:59 by sbehar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	mlx_loop_hook(value->mlx, ft_loop, value);
	mlx_loop(value->mlx);
}

int	ft_init(t_value *value)
{
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_render3d	*r;

	r = &value->render3d;
	value->mlx = mlx_init();
	mlx_get_screen_size(value->mlx, &value->width, &value->height);
	value->window = mlx_new_window(value->mlx, value->width,
			value->height, "cub3d");
	ft_init_mouse(value);
	value->draw = (t_color *)mlx_get_data_addr(value->img,
			&bits_per_pixel, &size_line, &endian);
	if (ft_load_textures(value, r) == BAD)
		return (BAD);
	mlx_do_key_autorepeatoff(value->mlx);
	value->first_mouse = 1;
	mlx_hook(value->window, 6, 1L << 6, ft_mouse_move, value);
	mlx_hook(value->window, 33, 1L << 17, mlx_loop_end, value->mlx);
	mlx_hook(value->window, KEY_PRESS_ID, (1L << 0), key_press, value);
	mlx_hook(value->window, KEY_RELEASE_ID, (1L << 1), key_release, value);
	mlx_loop_hook(value->mlx, ft_loop, value);
	mlx_mouse_hide(value->mlx, value->window);
	mlx_mouse_move(value->mlx, value->window, value->win_cx, value->win_cy);
	return (GOOD);
}

int	ft_load_textures(t_value *v, t_render3d *r)
{
	if (ft_load_textures_img(v, r) == BAD)
		return (BAD);
	ft_load_textures_data(r);
	return (GOOD);
}
