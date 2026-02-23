/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:58:17 by strieste          #+#    #+#             */
/*   Updated: 2026/02/23 09:38:56 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>

# define GRIDSIZE 16
# define RED 0x00FF0000
# define BLUE 0x0000FF00
# define GREEN 0x000000FF

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

typedef struct s_data
{
	int		w_map;
	int		h_map;
	char	**map;
	t_img	no_img;
	char	*no_texture;
	t_img	so_img;
	char	*so_texture;
	t_img	we_img;
	char	*we_texture;
	t_img	ea_img;
	char	*ea_texture;
	int		*rgb_ceiling;
	int		*rgb_floor;
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	t_img	player;
	t_img	mapi;
	t_vec	pos;
	float	angle;
	int		error;

}	t_data;

/*		check				*/

int		valide_extension(char *filename);
int		is_valide_file(char *filename, t_data *data);
int		is_valide_line(char *line);
int		is_blank(char *line);
int		check_before_map(char **file, t_data *data);
int		get_infos(char **file, t_data *data);

char	**clean_extract(char *filename);
// char	**exctract_file(char *filename, char *tmp, int count);
void	print_tab(char **tab);

/*		About map			*/

char	**get_map(char **file, int	lenght_up, int lenght_down, int count);
int		index_top_map(char **file);
int		index_down_map(char **file);

/*		Get texture path	*/

char	*get_no_texture(char **file);
char	*get_so_texture(char **file);
char	*get_we_texture(char **file);
char	*get_ea_texture(char **file);
int		*get_rgb_f(char **file);
int		*get_rgb_c(char **file);

/*		Clean				*/

void	clean_array(char **array);
void	clean_array_null(char ***array);
void	clean_struct_init(t_data *data);

int		valide_extension(char *str);
// int		lenght_tab(char **tab);
char	**copy_file_arg(char **file);
// char	**copy_file_arg(char **file);
char	**map_validator(char **file, t_data *data);
int		get_width_map(char **map);
char	**final_map(char **map);
int		lenght_tab(char **tab);
void	clean_struct_init(t_data *data);
int		check_after_map(char **file);
int	find_player(char **map, t_data *data);
int	find_player_pos(char **map, t_data *data);
int	parsing(char *filename, t_data *data);
void	print_arg_example(void);
int	get_size_map(char **map, t_data *data);

#endif