/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbehar <sbehar@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 02:00:47 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/13 13:15:56 by sbehar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_pars_the_line(t_parsing *pars, char *line)
{
	if (!line[0])
		return ("1");
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

void ft_rectangularize_map(char **map)
{
	int height = ft_size_tab(map);
	size_t max_width = 0;  // changer int en size_t
	for (int i = 0; i < height; i++)
		if (ft_strlen(map[i]) > max_width)
			max_width = ft_strlen(map[i]);
	for (int i = 0; i < height; i++)
	{
		size_t curr_len = ft_strlen(map[i]);
		if (curr_len < max_width)
		{
			char *new_line = malloc(max_width + 1);
			strcpy(new_line, map[i]);
			memset(new_line + curr_len, '1', max_width - curr_len);
			new_line[max_width] = '\0';
			free(map[i]);
			map[i] = new_line;
		}
	}
}

int	ft_read_lines(int fd, t_parsing *pars)
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
		if (pars->start == 0 && a == line)
			pars->start = -1;
		if (pars->start != -1)
			pars->start++;
		if (a == line)
			ft_add_to_map(line, &list_tmp, pars);
		free (line);
	}
	pars->map = ft_list_to_tab(list_tmp, pars);
	ft_rectangularize_map(pars->map);
	ft_lstclear(&list_tmp, free);
	return (ft_map_start(pars));
}
