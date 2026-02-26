/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 07:49:15 by strieste          #+#    #+#             */
/*   Updated: 2026/02/26 07:52:29 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	map_set(char c)
{
	if (c == '1')
		return (0);
	else if (c == '0')
		return (0);
	else if (c == 'N')
		return (0);
	else if (c == 'S')
		return (0);
	else if (c == 'E')
		return (0);
	else if (c == 'W')
		return (0);
	else if (c == ' ')
		return (0);
	else if (c == '\t')
		return (0);
	else if (c == '\r')
		return (0);
	return (1);
}

int	map_wall_left(char **map)
{
	int	count;
	int	i;

	count = 0;
	while (map[count])
	{
		i = 0;
		while (map[count][i])
		{
			if (map[count][i] != '1' && map[count][i] != ' ')
				return (1);
			if (map[count][i] == '1')
				break ;
			i++;
		}
		count++;
	}
	return (0);
}

int	map_wall_right(char **map)
{
	int	count;
	int	i;

	count = 0;
	while (map[count])
	{
		i = ft_strlen(map[count]);
		while (i >= 0 && map[count][i])
		{
			if (map[count][i] != '1' && map[count][i] != ' ')
				return (1);
			if (map[count][i] == '1')
				break ;
			i--;
		}
		count++;
	}
	return (0);
}

int	map_wall_up(char **map)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (map[count][i])
	{
		if (map[count][i] != '1' && map[count][i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	map_wall_down(char **map)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (map[count + 1])
		count++;
	while (map[count][i])
	{
		if (map[count][i] != '1' && map[count][i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
