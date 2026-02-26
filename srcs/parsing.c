/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 16:45:09 by strieste          #+#    #+#             */
/*   Updated: 2026/02/26 09:29:20 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// int	valide_map(char **file);
int			valide_map(char **file);
static int	check_map(char **file, t_data *data);
static int	flood_fill(char **map, int x, int y, t_data *data);

int	parsing(char *filename, t_data *data)
{
	char	**file;

	ft_bzero(data, sizeof(data));
	if (valide_extension(filename))
		return (1);
	file = exctract_file(filename, 0, 0);
	if (!file)
		return (1);
	if (check_before_map(file, data))
		return (clean_array_null(&file), 1);
	if (valide_map(file))
		return (clean_texture_init(data), clean_array_null(&file), 1);
	if (check_after_map(file))
		return (clean_texture_init(data), clean_array_null(&file), 1);
	if (check_map(file, data))
		return (clean_texture_map(data), clean_array_null(&file), 1);
	clean_array_null(&file);
	return (0);
}

int	valide_map(char **file)
{
	int	up;
	int	down;

	up = index_top_map(file);
	down = index_down_map(file);
	while (file[up] != 0 && up < down)
	{
		if (is_valide_line_map(file[up]))
		{
			ft_putstr_fd("Error\nInvalide case in a map\n", 2);
			printf("The map must be composed of only 6 possible characters:");
			printf("\n0 for an empty space\n");
			printf("1 for a wall\n");
			printf("one of N,S,E or W for the player\n");
			printf("start position and spawning orientation.\n");
			return (1);
		}
		up++;
	}
	return (0);
}

static int	check_map(char **file, t_data *data)
{
	char	**cpy;

	data->map = get_map(file, 0, 0, 0);
	if (!data->map)
		return (1);
	if (find_player(data->map, data))
		return (clean_array_null(&data->map), 1);
	find_player_pos(data->map, data);
	get_size_map(data->map, data);
	cpy = get_map(file, 0, 0, 0);
	if (!cpy)
		return (clean_array_null(&data->map), 1);
	data->error = 0;
	if (flood_fill(cpy, data->x, data->y, data))
		return (clean_array_null(&cpy), print_unclosed(), 1);
	if (map_wall_up(data->map) || map_wall_down(data->map)
		|| map_wall_left(data->map) || map_wall_right(data->map))
		return (clean_array_null(&cpy), print_unclosed(), 1);
	clean_array_null(&cpy);
	return (0);
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

// int	check_map_characters(char **file, int start)
// {
// 	int	i;
// 	int	j;

// 	i = start;
// 	while (file[i])
// 	{
// 		j = 0;
// 		while (file[i][j])
// 		{
// 			if (map_set(file[i][j]))
// 			{
// 				ft_putstr_fd("Error\nInvalid character in map\n", 2);
// 				return (1);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int	is_walkable(char c)
// {
// 	return (c == '0' || c == 'N' || c == 'S'
// 		|| c == 'E' || c == 'W');
// }

// int	is_space_or_void(char **map, int i, int j)
// {
// 	if (i < 0 || j < 0 || !map[i])
// 		return (1);
// 	if (j >= (int)ft_strlen(map[i]))
// 		return (1);
// 	if (map[i][j] == ' ')
// 		return (1);
// 	return (0);
// }

// int	check_map_closed(char **map, int start)
// {
// 	int	i;
// 	int	j;

// 	i = start;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (is_walkable(map[i][j]))
// 			{
// 				if (is_space_or_void(map, i - 1, j)
// 					|| is_space_or_void(map, i + 1, j)
// 					|| is_space_or_void(map, i, j - 1)
// 					|| is_space_or_void(map, i, j + 1))
// 				{
// 					ft_putstr_fd("Error\nMap is not closed\n", 2);
// 					return (1);
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int	valide_map(char **file)
// {
// 	int	start;

// 	start = index_top_map(file);
// 	if (check_map_characters(file, start))
// 		return (1);
// 	if (check_map_closed(file, start))
// 		return (1);
// 	return (0);
// }
