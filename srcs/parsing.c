/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:45:09 by strieste          #+#    #+#             */
/*   Updated: 2026/02/23 11:35:00 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check_map(char **file, t_data *data);
static int	flood_fill(char **map, int x, int y, t_data *data);
static void	print_unclosed(void);

int	parsing(char *filename, t_data *data)
{
	char	**file;

	if (valide_extension(filename))
		return (1);
	file = clean_extract(filename);
	if (!file)
		return (1);
	if (check_before_map(file, data))
		return (clean_array(file), 1);
	if (check_after_map(file))
		return (clean_struct_init(data), clean_array(file), 1);
	if (check_map(file, data))
		return (clean_struct_init(data), clean_array(file), 1);
	return (0);
}

static int	check_map(char **file, t_data *data)
{
	char	**cpy;

	data->map = get_map(file, 0, 0, 0);
	if (!data->map)
		return (1);
	if (find_player(data->map, data))
		return (clean_array(data->map), 1);
	find_player_pos(data->map, data);
	get_size_map(data->map, data);
	cpy = get_map(file, 0, 0, 0);
	if (!cpy)
		return (clean_array(data->map), 1);
	data->error = 0;
	if (flood_fill(cpy, data->x, data->y, data))
		return (clean_array(cpy), print_unclosed(), 1);
	clean_array_null(&cpy);
	return (0);
}

static void	print_unclosed(void)
{
	printf("Error\n");
	printf("The map provided in the file is not enclosed by walls, ");
	printf("or the ground is missing.\n");
	printf("Please redraw the map before starting the game.\n");
	return ;
}

static int	flood_fill(char **map, int x, int y, t_data *data)
{
	if (data->error == 1)
		return (1);
	if (!map || (x < 0 || y < 0 || x >= data->w_map || y >= data->h_map))
		return (data->error = 1, 1);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (0);
	if (map[y][x] == ' ' || map[y][x] == '\t')
		return (data->error = 1, 1);
	if ((map[y][x] == 'N') || (map[y][x] == 'S')
		|| (map[y][x] == 'E') || (map[y][x] == 'W') || (map[y][x] == '0'))
		map[y][x] = 'V';
	if (flood_fill(map, x + 1, y, data))
		return (1);
	if (flood_fill(map, x, y + 1, data))
		return (1);
	if (flood_fill(map, x - 1, y, data))
		return (1);
	if (flood_fill(map, x, y - 1, data))
		return (1);
	return (0);
}
