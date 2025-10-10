/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 02:00:47 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/10 12:17:23 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_pars_the_line(t_parsing *pars, char *line)
{
	if (!line[0])
		return (NULL);
	if (((line[0] == 'F' ) || (line[0] == 'C')) && ft_is_a_space(line[1]))
		return (ft_pars_color(line, pars));
	if ((ft_strncmp(line, "NO", 2) == 0) && ft_is_a_space(line[2]))
		return ("1");
	if ((ft_strncmp(line, "SO", 2) == 0) && ft_is_a_space(line[2]))
		return ("1");
	if ((ft_strncmp(line, "WE", 2) == 0) && ft_is_a_space(line[2]))
		return ("1");
	if ((ft_strncmp(line, "EA", 2) == 0) && ft_is_a_space(line[2]))
		return ("1");
	return (line);
}

int	ft_transfer_map(int fd, t_parsing *pars)
{
	t_list	*list_tmp;

	list_tmp = ft_read_lines(fd, pars);
	if (!list_tmp)
		return (-1);
	pars->map = ft_list_to_tab(list_tmp, pars);
	ft_lstclear(&list_tmp, free);
	return (ft_map_start(pars));
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
		{
			free(line);
			ft_lstclear(&list_tmp, free);
			return (NULL);
		}
		if (a == line)
			ft_add_to_map(line, &list_tmp, pars);
		free (line);
	}
	return (list_tmp);
}

int	ft_check_trap(t_parsing *pars, char	*a, char *line, t_list	*list_tmp)
{
	if (pars->start == 0 && a == line)
		pars->start = -1;
	if (pars->start != -1)
		pars->start++;
	if (a == NULL && list_tmp)
		pars->space = 1;
	if (a == line && pars->space == 1)
		return (BAD);
	return (GOOD);
}
