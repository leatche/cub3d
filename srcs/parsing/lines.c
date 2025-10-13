/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 02:00:47 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/13 02:36:07 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_pars_the_line(t_parsing *pars, char *line)
{
	if (!line[0])
		return ("-2");
	if (((line[0] == 'F' ) || (line[0] == 'C')) && ft_is_a_space(line[1]))
		return (ft_pars_color(line, pars));
	if ((ft_strncmp(line, "NO", 2) == 0) && ft_is_a_space(line[2]))
		return ("-3");
	if ((ft_strncmp(line, "SO", 2) == 0) && ft_is_a_space(line[2]))
		return ("-3");
	if ((ft_strncmp(line, "WE", 2) == 0) && ft_is_a_space(line[2]))
		return ("-3");
	if ((ft_strncmp(line, "EA", 2) == 0) && ft_is_a_space(line[2]))
		return ("-3");
	return (line);
}

int	ft_transfer_map(int fd, t_parsing *pars)
{
	t_list	*list_tmp;

	list_tmp = ft_read_lines(fd, pars);
	if (!list_tmp)
		return (-1);
	if (!list_tmp || list_tmp == NULL)
		return (-1);
	pars->map = ft_list_to_tab(list_tmp, pars);
	ft_lstclear(&list_tmp, free);
	return (0);
}

t_list	*ft_read_lines(int fd, t_parsing *pars)
{
	t_list	*list_tmp;
	char	*line;
	char	*a;

	line = "";
	list_tmp = NULL;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		a = ft_pars_the_line(pars, line);
		if (ft_check_trap(pars, a, line, list_tmp) == BAD)
			return (ft_lstclear(&list_tmp, free), free(line), NULL);
		if (a == line)
			ft_add_to_map(line, &list_tmp, pars);
		free (line);
	}
	if (list_tmp == NULL)
		ft_print("Your map is missing ;o");
	return (list_tmp);
}

int	ft_check_trap(t_parsing *pars, char	*a, char *line, t_list	*list_tmp)
{
	if (ft_strncmp(a, "-1", 2) == 0)
		return (BAD);
	if (a == line && (pars->hasFloor == 0 || pars->hasCeiling == 0))
	{
		ft_print("Your map is missing or wrongly placed ;o");
		return (BAD);
	}
	if (ft_strncmp(a, "-2", 2) == 0 && list_tmp)
		pars->space = 1;
	if (a == line && pars->space == 1)
	{
		ft_print("There are a some empty lines in your map ;)");
		return (BAD);
	}
	return (GOOD);
}
