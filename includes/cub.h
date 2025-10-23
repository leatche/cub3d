/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbehar <sbehar@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:23:47 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/23 14:16:09 by sbehar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdbool.h>
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

# define LINE_INFO 0
# define LINE_MAP 1
# define LINE_EMPTY 2
# define LINE_ERROR 3

# define NORTH 0
# define EAST 1
# define SOUTH 2
# define WEST 3

# define GRID_SIZE 150

# define PI 3.14159265359

# define Z 122
# define W 119

# define Q 113
# define A 97

# define S 115
# define D 100
# define M 109
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define ESC 65307

# define KEY_PRESS_ID 02

# define KEY_RELEASE_ID 03

# define DIR "ENWS"

# define FOV 60.0

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define COLOR_WALL 0xFFAA00
# define COLOR_SKY  0x87CEEB
# define COLOR_FLOOR 0x228B22

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
	t_point	dir;
	t_point	plane;
}				t_player;

typedef struct s_parsing
{
	int					space;
	char				**map;
	long unsigned int	size_line;
	t_color				floor;
	t_color				ceiling;
	int					last_line_type;
	int					has_map;
	int					has_floor;
	int					has_ceiling;
	t_player			*player;
	char				*textures[4];
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

typedef struct s_texture
{
	void	*img_ptr;
	int		*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_texture;

typedef struct s_render3d
{
	int			rays;
	int			win_height;
	int			x;
	double		fov;
	double		start_angle;
	double		player_angle_rad;
	t_color		wall_color;
	t_color		floor_color;
	t_color		ceiling_color;
	t_texture	texture_north;
	t_texture	texture_south;
	t_texture	texture_east;
	t_texture	texture_west;
}	t_render3d;

typedef struct s_setup
{
	int			draw_start;
	int			draw_end;
	int			tex_x;
	t_render3d	*r;
	t_texture	texture;
}	t_setup;

typedef struct s_minimap
{
	int	cx;
	int	cy;
	int	radius;
	int	scale;
	int	map_width;
	int	map_height;
	int	px;
	int	py;
}	t_minimap;

typedef struct s_value
{
	int			height;
	int			width;
	int			win_cx;
	int			win_cy;
	void		*mlx;
	void		*window;
	void		*img;
	int			first_mouse;
	int			last_mouse_x;
	bool		mouse_on;
	t_color		*draw;
	t_player	*player;
	t_parsing	*parsing;
	t_key		keys;
	t_render3d	render3d;
	t_minimap	minimap;
}				t_value;

typedef struct s_rayhit
{
	double	x;
	double	y;
	double	dist;
	int		side;
}	t_rayhit;

typedef struct s_draw
{
	t_value		value;
	t_render3d	*r;
	int			i;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	t_texture	texture;
	t_rayhit	hit;
	double		ray_angle;
	double		corrected_dist;
}	t_draw;

typedef struct s_dda
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	player_x;
	double	player_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	dist;
}	t_dda;

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

void		ft_print(char *a);
void		ft_free_tab(char **tab);
void		ft_draw_map(t_value *v);
void		ft_make_cub(t_value *v);
void		ft_draw_rays(t_value *v);
void		ft_print_map(t_value *v);
void		ft_free_value(t_value *v);
void		ft_draw_walls(t_value *v);
void		ft_finish_reading(int fd);
void		ft_print_player(t_value *v);
void		ft_dda_init_x(t_dda *param);
void		ft_dda_init_y(t_dda *param);
void		ft_init_mouse(t_value *value);
void		ft_calc_ray_params(t_draw *d);
void		ft_handle_rotation(t_value *v);
void		ft_calc_draw_params(t_draw *d);
void		ft_handle_up_and_down(t_value *v);
void		ft_initialize_pars(t_parsing *pars);
void		ft_handle_right_and_left(t_value *v);
void		ft_load_textures_data(t_render3d *r);
void		ft_minimap_zoom_in(t_minimap *minimap);
void		ft_minimap_zoom_out(t_minimap *minimap);
void		ft_draw_v_line(t_value *v, t_setup *set);
void		ft_setup_render3d(t_value *v, t_render3d *r);
void		ft_update_map_size(t_minimap *minimap, char **map);
void		ft_draw_minimap_map(t_value *v, t_minimap *minimap);
void		ft_put_pixel(t_value *v, t_point pos, t_color color);
void		ft_dda_init(t_value *v, double ray_angle, t_dda *param);
void		ft_draw_minimap_compass(t_value *v, t_minimap *minimap);
void		ft_update_player_orientation(t_value *value, int xoffset);
void		ft_add_to_map(char *a, t_list **list_tmp, t_parsing *pars);
void		ft_move_player(t_value *v, double delta_x, double delta_y);
void		ft_update_map_pos(t_player *p, t_minimap *map, int x, int y);
void		ft_put_square(t_value *v, t_point pos, int size, t_color color);
void		ft_put_circle(t_value *v, t_point pos, int size, t_color color);
void		ft_draw_minimap_circle(t_value *v, t_minimap *minimap, int color);
void		ft_put_line(t_value *v, t_point start, t_point end, t_color color);
void		ft_draw_one_minimap_cell(t_value *v, t_minimap *map, int x, int y);
void		ft_calc_draw_lim(t_render3d *r, double c_dst,
				int *draw_s, int *draw_e);

int			ft_loop(t_value *v);
int			ft_init(t_value *v);
int			ft_is_a_space(char a);
int			ft_parsing(t_value *v);
int			ft_size_tab(char **tab);
int			ft_extension(char *file);
int			ft_free_error(t_value *v);
int			ft_check_wall(char **tmp);
int			ft_conform_map(char **tmp);
int			ft_checker_wall(char **tmp);
int			ft_has_a_player(t_value *v);
int			ft_check_wall_top(char *line);
int			ft_check_side_wall(char *line);
int			ft_good_characters(char *line);
int			ft_free_parsing(t_parsing *pars);
int			key_press(int keycode, t_value *v);
int			ft_map_has_empty_line(t_list *map);
int			ft_check_sides(char **tmp, int size);
int			key_release(int keycode, t_value *v);
int			ft_check_zero(char **tmp, int i, int j);
int			ft_transfer_map(int fd, t_parsing *pars);
int			ft_norm_color(char *line, t_color *color);
int			ft_final_pars_map(t_parsing *pars, int a);
int			ft_pars_color(char *line, t_parsing *pars);
int			ft_mouse_move(int x, int y, t_value *value);
int			ft_pars_the_line(t_parsing *pars, char *line);
int			ft_load_textures(t_value *value, t_render3d *r);
int			ft_calc_tex_x(t_texture *texture, t_rayhit *hit);
int			ft_value_color(char *line, unsigned char *color);
int			ft_load_textures_img(t_value *value, t_render3d *r);
int			ft_mouse_hook(int button, int x, int y, void *param);
int			ft_check_trap(t_parsing *pars, char *line, t_list **list_tmp);

char		*ft_strdup_space(char *s, int size_line);

char		**ft_list_to_tab(t_list *list_tmp, t_parsing *pars);

double		ft_deg_to_rad(double angle_deg);
double		ft_normalize_angle(double angle_deg);
double		ft_calc_ray_angle(t_render3d *r, int i);
double		ft_dda_ray(t_value *va, double ray_angle, t_rayhit *res);
double		ft_cast_ray(t_value *v, double ray_angle, t_rayhit *hit);
double		ft_ray_angle(double orientation, double fov, int rays, int i);
double		ft_calc_corr_dist(double dist, double ray_angle_rad,
				double player_ang);

t_color		green(void);
t_color		yellow(void);
t_color		color(int r, int g, int b);
t_color		ft_get_minimap_cell_color(t_value *v, char c);
t_color		int_to_t_color(int rgb);

t_list		*ft_read_lines(int fd, t_parsing *pars);

t_point		point(int x, int y);
t_point		ft_ray_target_point(t_point origin, double angle, double length);

t_parsing	*pars_file(char *file);

#endif
