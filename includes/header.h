/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:58:17 by strieste          #+#    #+#             */
/*   Updated: 2026/02/26 10:39:47 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/time.h>

# define GRIDSIZE 32
# define TEXSIZE 64
# define WIN_H 1280
# define WIN_W 1600
# define PI 3.141592

# define W 119
# define S 115
# define A 97
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

# define MOVE_SPEED 4.0
# define ROT_SPEED 2.0

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_key
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	left;
	int	right;
}	t_key;

typedef struct s_texture
{
	t_img	no_img;
	char	*no_texture;
	t_img	so_img;
	char	*so_texture;
	t_img	we_img;
	char	*we_texture;
	t_img	ea_img;
	char	*ea_texture;
	int		rgb_c;
	int		rgb_f;
}	t_texture;

typedef struct s_data
{
	int			w_map;
	int			h_map;
	char		**map;
	int			size;
	double		text_x;
	double		text_y;
	int			*rgb_ceiling;
	int			*rgb_floor;
	int			x;
	int			y;
	void		*mlx;
	void		*win;
	int			w;
	int			a;
	int			s;
	int			d;
	int			moving;
	t_img		player;
	t_img		mapi;
	int			error;
	t_img		walls;
	t_key		keys;
	double		pos_x;
	double		pos_y ;
	double		dir_x ;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		ray_dirx;
	double		ray_diry;
	int			map_x;
	int			map_y;
	double		side_d_x;
	double		side_d_y;
	double		delta_d_x;
	double		delta_d_y;
	double		wall_dist;
	double		wall_x;
	int			line_h;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	long		time;
	long		oldtime;
	double		frames;
	double		move_speed;
	double		rot_speed;
	t_texture	image;
}	t_data;

/*		Get file			*/

void	print_tab(char **tab);
char	**exctract_file(char *filename, char *tmp, int count);

/*		Begin file check	*/

int		is_valide_line(char *line);
char	get_identifier(char *line);
int		check_after_map(char **file);
int		valide_extension(char *filename);
int		check_before_map(char **file, t_data *data);

/*		RGB color			*/

int		*get_rgb_f(char **file);
int		*get_rgb_c(char **file);
int		get_index_c(char **file);
int		get_index_f(char **file);
int		get_rgb_color(char **file, char type);
char	*get_hex_color(int red, int green, int blue);

/*		check				*/

int		is_blank(char *line);
int		init_texture(t_data *data);
int		parsing(char *filename, t_data *data);
char	**copy_file_arg(char **file, int len, int count);;

/*		Map					*/

int		map_set(char c);
int		map_wall_up(char **map);
int		map_wall_down(char **map);
int		map_wall_left(char **map);
int		map_wall_right(char **map);
int		index_top_map(char **file);
int		index_down_map(char **file);
int		is_valide_line_map(char *line);
char	**get_map(char **file, int lenght_up, int lenght_down, int count);

/*		Get texture path	*/

char	*get_no_texture(char **file);
char	*get_so_texture(char **file);
char	*get_we_texture(char **file);
char	*get_ea_texture(char **file);

/*		DDA					*/

int		loop(t_data *data);
int		key_pressed(int keycode, t_data *data);
int		key_released(int kcode, t_data *data);

long	get_curr_time(void);
void	init_data(t_data *data);
int		win_close(t_data *data);
void	move_player(t_data *data);
void	draw_walls(t_data *data, int x);
void	clean_img(t_img img, t_texture color);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	calculate_ray(t_data *data, int x, double ray_x, double ray_y);

/*		Tools				*/

int		lenght_tab(char **tab);
int		is_wspace_line(char *line);
void	ft_strcpy(char *dest, char *src);
int		find_player(char **map, t_data *data);
int		get_size_map(char **map, t_data *data);
int		find_player_pos(char **map, t_data *data);

/*		Announce			*/

void	print_example(void);
void	print_unclosed(void);

/*		Clean				*/

void	clean_array(char **array);
void	clean_data_end(t_data *data);
void	clean_texture_map(t_data *data);
void	clean_array_null(char ***array);
void	clean_texture_init(t_data *data);
void	free_error_texture(t_data *data);

#endif