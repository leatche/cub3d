/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:20:37 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/12 23:06:12 by tcherepoff       ###   ########.fr       */
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
	ft_draw_map(value);
	mlx_loop(value->mlx);
}

void	ft_init(t_value *value)
{
	int	t;

	value->mlx = mlx_init();
	mlx_get_screen_size(value->mlx, &value->width, &value->height);
	value->window = mlx_new_window(value->mlx, value->width,
			value->height, "cub3d");
	value->img = mlx_new_image(value->mlx, value->width, value->height);
	value->draw = (t_color *)mlx_get_data_addr(value->img, &t, &t, &t);
	mlx_do_key_autorepeatoff(value->mlx);
	mlx_hook(value->window, 33, 1L << 17, mlx_loop_end, value->mlx);
	mlx_hook(value->window, KEY_PRESS_ID, KEY_PRESS_MASK, key_press, value);
	mlx_hook(value->window, KEY_RELEASE_ID,
		KEY_RELEASE_MASK, key_release, value);
	mlx_loop_hook(value->mlx, ft_loop, value);
}
