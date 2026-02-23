/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbezenco <cbezenco@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:58:17 by strieste          #+#    #+#             */
/*   Updated: 2026/02/23 13:03:48 by cbezenco         ###   ########.fr       */
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
# define WIN_H 640
# define WIN_W 800
# define PI 3.141592

# define RED 0x00FF0000
# define BLUE 0x000000FF
# define GREEN 0x0000FF00
# define VOID 0x00000000
# define BROWN 0x00A52A2A
# define SKY	0x0071BCE1

# define W 119
# define S 115
# define A 97
# define D 100
# define LEFT 65361
# define RIGHT 65363

typedef struct s_vec
{
	float	x;
	float	y;
}	t_vec;

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

typedef struct s_data
{
	char	**map;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		*rgb_ceiling;
	int		*rgb_floor;
	void	*mlx;
	void	*win;
	int		w;
	int		a;
	int		s;
	int		d;
	int		moving;
	t_img	player;
	t_img	mapi;
	t_img	walls;
	t_key	keys;
	double	pos_x;
	double	pos_y ;
	double	dir_x ;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	ray_dirx;
	double	ray_diry;
	int		map_x;
	int		map_y;
	double	side_d_x;
	double	side_d_y;
	double	delta_d_x;
	double	delta_d_y;
	double	wall_dist;
	int		line_h;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	long	time;
	long	oldtime;
	double	frames;
	double	move_speed;
	double	rot_speed;
}	t_data;

/*		check				*/

int		valide_extension(char *filename);

char	**clean_extract(char *filename);
// char	**exctract_file(char *filename, char *tmp, int count);
void	print_tab(char **tab);

/*		About map			*/

char	**get_map(char **file);
int		lenght_top_map(char **file);
int		lenght_down_map(char **file);

/*		Get texture path	*/

char	*get_no_texture(char **file);
char	*get_so_texture(char **file);
char	*get_we_texture(char **file);
char	*get_ea_texture(char **file);
int		*get_rgb_f(char **file);
int		*get_rgb_c(char **file);

/*		Clean				*/

void	clean_array(char **array);

int		valide_extension(char *str);

/*		DDA					*/

int		loop(t_data *data);
int		key_pressed(int keycode, t_data *data);
int		key_released(int kcode, t_data *data);

long	get_curr_time(void);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	init_data(t_data *data);
int		win_close(t_data *data);

#endif