/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:58:17 by strieste          #+#    #+#             */
/*   Updated: 2026/02/18 13:49:25 by cbezenco         ###   ########.fr       */
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
	char	**map;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		*rgb_ceiling;
	int		*rgb_floor;
	void	*mlx;
	void	*win;
	t_img	player;
	t_img	mapi;
	t_vec	pos;
	float	angle;

// }	t_data;

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

#endif