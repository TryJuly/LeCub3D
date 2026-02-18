/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbezenco <cbezenco@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:58:17 by strieste          #+#    #+#             */
/*   Updated: 2026/02/18 12:20:19 by cbezenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <math.h>

# include <fcntl.h>

typedef struct s_data
{
	char	**map;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		*rgb_ceiling;
	int		*rgb_floor;

}	t_data;

/*		check				*/

int		valide_extension(char *filename);

char	**exctract_file(char *filename, char *tmp, int count);
void	print_tab(char **tab);

/*		About map			*/

char	**get_map(char **file);

/*		Get texture path	*/

char	*get_no_texture(char **out_file);
char	*get_so_texture(char **out_file);
char	*get_we_texture(char **out_file);
char	*get_ea_texture(char **out_file);

/*		Clean				*/

void	clean_array(char **array);

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
	void	*mlx;
	void	*win;
	int		grid_size;
	t_img	player;
	t_vec	pos;
	float	angle;
	char	**map;
}	t_data;

int		valide_extension(char *str);

#endif