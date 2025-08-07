/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:20:37 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/07 11:46:16 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_parsing *pars;

	pars = malloc(sizeof(t_parsing));
	if (ac == 2 && (ft_extension(av[1]) == GOOD) && (ft_open(av[1], pars) != -1))
	{
		// if (ft_parsing(pars) == -1);
		// 	return (-1);
	}
	else
	{
			ft_print("There is a problem in your arguments !");
			printf("Check again your file and the number of arguments !");
	}
	return (0);
}
