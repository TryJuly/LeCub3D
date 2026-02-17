/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:58:17 by strieste          #+#    #+#             */
/*   Updated: 2026/02/17 15:28:30 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
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

/*		check			*/

int		valide_extension(char *filename);

char	**exctract_file(char *filename);
void	print_tab(char **tab);


#endif