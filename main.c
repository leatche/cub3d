/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:20:37 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/20 17:21:14 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_value		*value;
	t_parsing	*pars;

	value = calloc(1, sizeof(t_value));
	value->parsing = calloc(1, sizeof(t_parsing));
	pars = value->parsing;
	if (ac == 2 && ft_extension(av[1]) == GOOD && (ft_open(av[1], value->parsing) != -1))
	{
		if (ft_parsing(value->parsing) == -1)
			return (ft_free_parsing(pars));
		printf("Player: [%.2f, %.2f] | %.2f deg\n", pars->player->pos_x, pars->player->pos_y, pars->player->orientation);
		ft_make_cub(value);
	}
	else
		ft_print("Check again your file or the number of arguments !");
	ft_free_parsing(value->parsing);
	free(value);
	return (0);
}

void	ft_make_cub(t_value *value)
{
	ft_init(value);
	draw_map(value);
	mlx_put_image_to_window(value->mlx, value->window, value->img, 0, 0);
	mlx_loop(value->mlx);
	ft_free_value(value);
}

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
	mlx_key_hook(value->window, key_press, value->mlx);
	mlx_hook(value->window, 33, 1L << 17, mlx_loop_end, value->mlx);
}

void	ft_free_value(t_value *value)
{
	mlx_destroy_image(value->mlx, value->img);
	mlx_destroy_window(value->mlx, value->window);
	mlx_destroy_display(value->mlx);
	// ft_free_tab((void **)value->tab);
	free(value->mlx);
	free(value);
}
