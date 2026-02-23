/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:46:57 by strieste          #+#    #+#             */
/*   Updated: 2026/02/23 09:33:49 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_size_map(char **map, t_data *data)
{
	int	count;
	int	res;
	int	i;

	count = 0;
	res = 0;
	while (map[count] != 0)
	{
		i = 0;
		while (map[count][i])
			i++;
		if (i > res)
			res = i;
		count++;
	}
	data->h_map = count;
	data->w_map = res;
	return (0);
}

int	find_player_pos(char **map, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((map[y][x] == 'N' || map[y][x] == 'S')
					|| (map[y][x] == 'E' || map[y][x] == 'W'))
			{
				data->x = x;
				data->y = y;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	find_player(char **map, t_data *data)
{
	int	x;
	int	y;
	int	find_player;

	y = 0;
	find_player = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((map[y][x] == 'N' || map[y][x] == 'S')
					|| (map[y][x] == 'E' || map[y][x] == 'W'))
				find_player++;
			x++;
		}
		y++;
	}
	if (find_player < 1)
		return (ft_putstr_fd("Error\nNo player found\n", 2), 1);
	if (find_player > 1)
		return (ft_putstr_fd("Error\nMore than one player found\n", 2), 1);
	if (find_player_pos(map, data))
		return (ft_putstr_fd("Error\nPlayer not found\n", 2), 1);
	return (0);
}
