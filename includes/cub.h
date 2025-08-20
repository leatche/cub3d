/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:23:47 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/20 17:04:44 by tcherepoff       ###   ########.fr       */
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
# include <math.h>
# include "extern_files/mlx/mlx.h"
# include "extern_files/libft/libft.h"

#define GOOD 1
#define BAD -1
#define YES 1
#define NO -1

#define WIDTH 1400
#define HEIGHT 800

typedef struct s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}				t_color;

typedef struct s_player
{
	double	orientation;
	double	pos_x;
	double	pos_y;
}				t_player;

typedef struct s_parsing
{
	int					start;
	int					already_player;
	char				**map;
	t_color				floor;
	t_color				wall;
	long unsigned int	size_line;
	t_player			*player;
}				t_parsing;

typedef struct s_value
{
	int		height;
	int		width;
	void	*mlx;
	void	*window;
	void	*img;
	t_color	*draw;
	t_parsing *parsing;
	
}				t_value;

void	ft_print(char *a);
void	ft_init(t_value *value);
void	ft_free_tab(char **tab);
void	ft_make_cub(t_value *value);
void	ft_free_value(t_value *value);
void	ft_initialize_pars(t_parsing *pars);
void	ft_add_to_map(char *a, t_list **list_tmp, t_parsing *pars);

int		ft_is_a_space(char a);
int		ft_size_tab(char **tab);
int		ft_extension(char *file);
int		ft_check_wall(char **tmp);
int		ft_conform_map(char **tmp);
int		ft_checker_wall(char **tmp);
int		ft_parsing(t_parsing *pars);
int		ft_map_start(t_parsing *pars);
int		ft_check_wall_top(char *line);
int		ft_check_side_wall(char *line);
int		ft_good_characters(char *line);
int		ft_free_parsing(t_parsing *pars);
int		ft_check_sides(char **tmp, int size);
int		ft_open(char *file, t_parsing *pars);
int		ft_read_lines(int fd, t_parsing *pars);
int		key_press(int keycode, t_value *value);
int		ft_check_zero(char **tmp, int i, int j);
int		ft_norm_color(char *line, t_color *color);
int		ft_value_color(char *line, unsigned char *color);

char	*ft_strdup_space(char *s, int size_line);
char	*ft_pars_the_line(t_parsing *pars, char *line);
char	*ft_pars_color(char *line, t_parsing *pars);

char	**ft_list_to_tab(t_list *list_tmp, t_parsing *pars);
int		ft_has_a_player(t_parsing *pars);

void ft_put_pixel(t_value *value, int x, int y, t_color color);
void ft_put_square(t_value *value, int x, int y, int size, t_color color);
void ft_put_circle(t_value *value, int x, int y, int size, t_color color);
t_color color(int r, int g, int b);
void draw_map(t_value *value);

t_color yellow();
t_color green();
#endif
