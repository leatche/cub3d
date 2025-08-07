/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:04:17 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/07 15:04:04 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_extension(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i < 5)
		return (BAD);
	if (strcmp(file + i - 4, ".cub") == 0)
		return (GOOD);
	return (BAD);
}

int	ft_open(char *file, t_parsing *pars)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (BAD);
	return (ft_read_lines(fd, pars));
}

int	ft_read_lines(int fd, t_parsing *pars)
{
	char	*line;
	int		a;

	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (line && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		a = ft_pars_the_line(pars, line);
		printf("%d\n",a);
		free (line);
	}
	return GOOD;
}

int	ft_pars_the_line(t_parsing *pars, char *line)
{
	int	i;

	i = 0;
	pars->fd = 0;
	while (line[i] && ft_is_a_space(line[i]))
		i++;
	if (!line[i])
		return (55);
	if (((line[i] == 'F' ) | (line[i] == 'C')) && ft_is_a_space(line[i + 1]))
		return (1);
	if ((ft_strncmp(line + i, "NO", 2) == 0) && ft_is_a_space(line[i + 2]))
		return (2);
	if ((ft_strncmp(line + i, "SO", 2) == 0) && ft_is_a_space(line[i + 2]))
		return (3);
	if ((ft_strncmp(line + i, "WE", 2) == 0) && ft_is_a_space(line[i + 2]))
		return (4);
	if ((ft_strncmp(line + i, "EA", 2) == 0) && ft_is_a_space(line[i + 2]))
		return (5);
	return (8);
	
}

int	ft_is_a_space(char a)
{
	if (a == ' ' || a == '\t')
		return (1);
	return (0);
}
