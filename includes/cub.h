/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:23:47 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/10 12:44:12 by tcherepoff       ###   ########.fr       */
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

# define GOOD 1
# define BAD -1
# define YES 1
# define NO -1

# define WIDTH 1400
# define HEIGHT 800
# define GRID_SIZE 100

# define PI 3.14159265359

# define Z 122
# define W 119

# define Q 113
# define A 97

# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define ESC 65307

# define KEY_PRESS_ID 02
# define KEY_PRESS_MASK (1L<<0)

# define KEY_RELEASE_ID 03
# define KEY_RELEASE_MASK (1L<<1)

# define DIR "ENWS"

typedef struct s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}				t_color;

typedef struct s_point
{
	double	x;
	double	y;
}				t_point;

typedef struct s_player
{
	double	orientation;
	t_point	pos;
	t_color	color;
}				t_player;

typedef struct s_parsing
{
	int					start;
	int					space;
	char				**map;
	long unsigned int	size_line;
	t_color				floor;
	t_color				wall;
	t_player			*player;
}				t_parsing;

typedef struct s_key
{
	int	go_forward;
	int	go_backward;
	int	go_left;
	int	go_right;
	int	turn_left;
	int	turn_right;
}	t_key;

typedef struct s_value
{
	int			height;
	int			width;
	void		*mlx;
	void		*window;
	void		*img;
	t_color		*draw;
	t_player	*player;
	t_parsing	*parsing;
	t_key		keys;
}				t_value;

void	ft_print(char *a);
void	ft_init(t_value *value);
void	ft_free_tab(char **tab);
void	ft_draw_map(t_value *value);
void	ft_make_cub(t_value *value);
void	ft_print_map(t_value *value);
void	ft_free_value(t_value *value);
void	ft_print_player(t_value *value);
void	ft_initialize_pars(t_parsing *pars);
void	ft_put_pixel(t_value *value, t_point pos, t_color color);
void	ft_add_to_map(char *a, t_list **list_tmp, t_parsing *pars);
void	ft_put_square(t_value *value, t_point pos, int size, t_color color);
void	ft_put_circle(t_value *value, t_point pos, int size, t_color color);
void	ft_put_line(t_value *value, t_point start, t_point end, t_color color);

int		ft_is_a_space(char a);
int		ft_loop(t_value *value);
int		ft_size_tab(char **tab);
int		ft_extension(char *file);
int		ft_check_wall(char **tmp);
int		ft_conform_map(char **tmp);
int		ft_checker_wall(char **tmp);
int		ft_free_error(t_value *value);
int		ft_map_start(t_parsing *pars);
int		ft_check_wall_top(char *line);
int		ft_check_side_wall(char *line);
int		ft_good_characters(char *line);
int		ft_free_parsing(t_parsing *pars);
int		ft_check_sides(char **tmp, int size);
int		ft_open(char *file, t_parsing *pars);
int		key_release(int keycode, t_value *value);
int		key_press(int keycode, t_value *value);
int		ft_check_zero(char **tmp, int i, int j);
int		ft_transfer_map(int fd, t_parsing *pars);
int		ft_norm_color(char *line, t_color *color);
int		ft_parsing(t_value *value, t_parsing *pars);
int		ft_has_a_player(t_value *value, t_parsing *pars);
int		ft_value_color(char *line, unsigned char *color);
int		ft_check_trap(t_parsing *pars, char	*a, char *line, t_list *list_tmp);

char	*ft_strdup_space(char *s, int size_line);
char	*ft_pars_the_line(t_parsing *pars, char *line);
char	*ft_pars_color(char *line, t_parsing *pars);

char	**ft_list_to_tab(t_list *list_tmp, t_parsing *pars);

t_color	green(void);
t_color	yellow(void);
t_color	color(int r, int g, int b);

t_list	*ft_read_lines(int fd, t_parsing *pars);

t_point	point(int x, int y);

#endif
