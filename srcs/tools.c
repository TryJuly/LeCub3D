/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 07:49:52 by strieste          #+#    #+#             */
/*   Updated: 2026/02/26 11:37:13 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '\n' && src[i] != '\r')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return ;
}

int	index_down_map(char **file)
{
	int	count;

	count = index_top_map(file);
	while (file[count])
	{
		if (is_valide_line_map(file[count]))
			return (count);
		count++;
	}
	if (!is_valide_line_map(file[count - 1]) && !file[count])
		return (count - 1);
	return (-1);
}

int	index_top_map(char **file)
{
	int	count;

	count = 0;
	while (file[count] != 0)
	{
		if (!is_valide_line_map(file[count]))
			return (count);
		count++;
	}
	ft_putstr_fd("Error\nMap not found\n", 2);
	return (-1);
}

static int	set_valide(char c);
static int	side_check(char **map, int x, int y);

int	map_is_walkable(char **map)
{
	int	i;
	int	j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (side_check(map, j, i))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	side_check(char **map, int x, int y)
{
	if (map[y - 1][x] && set_valide(map[y - 1][x]))
		return (1);
	if (map[y][x + 1] && set_valide(map[y][x + 1]))
		return (1);
	if (map[y + 1][x] && set_valide(map[y + 1][x]))
		return (1);
	if (map[y][x - 1] && set_valide(map[y][x - 1]))
		return (1);
	return (0);
}

static int	set_valide(char c)
{
	if (c == '1')
		return (0);
	if (c == '0')
		return (0);
	if (c == 'N')
		return (0);
	if (c == 'S')
		return (0);
	if (c == 'E')
		return (0);
	if (c == 'W')
		return (0);
	return (1);
}