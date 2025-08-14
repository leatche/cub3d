/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:20:37 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/14 16:17:39 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_parsing *pars;

	pars = calloc(1, sizeof *pars);
	if (ac == 2 && (ft_extension(av[1]) == GOOD) && (ft_open(av[1], pars) != -1))
	{
		if (ft_parsing(pars) == -1)
			return (ft_free_parsing(pars));
	}
	else
	{
		ft_print("Check again your file or the number of arguments !");
		ft_free_parsing(pars);
		return (-1);
	}
	ft_free_parsing(pars);
	return (0);
}

int	ft_free_parsing(t_parsing *pars)
{
	if (!pars)
		return (-1);
	if (pars->map)
		ft_free_tab(pars->map);
	free(pars);
	return (-1);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
