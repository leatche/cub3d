/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:23:47 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/10 00:34:33 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>
# include "extern_files/mlx/mlx.h"
# include "extern_files/libft/libft.h"

#define GOOD 1
#define BAD -1
#define YES 1
#define NO -1

typedef struct s_parsing
{
	int	fd;
	char *sky_color;
	char *floor_color;
	char **map;
}					t_parsing;


void	ft_print(char *a);
int	ft_parsing(char *pars);
int	ft_extension(char *file);
int	ft_open(char *file, t_parsing *pars);
int	ft_read_lines(int fd, t_parsing *pars);
char	*ft_pars_the_line(t_parsing *pars, char *line);
int	ft_is_a_space(char a);
char	**ft_list_to_tab(t_list *list_tmp);
void	ft_add_to_map(char *a, t_list **list_tmp);
#endif
