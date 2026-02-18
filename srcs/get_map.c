/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:50:14 by strieste          #+#    #+#             */
/*   Updated: 2026/02/18 14:40:29 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	map_set(char c);
static int	is_valide_line(char *line);

char	**get_map(char **file)
{
	int		count;
	char	**map;
	char	*tmp;
	int		lenght_up;
	int		lenght_down;

	lenght_up = lenght_top_map(file);
	lenght_down = lenght_down_map(file);
	map = ft_calloc(((lenght_down - lenght_up) + 1), sizeof(char *));
	if (!map)
		return (NULL);
	count = 0;
	while (lenght_up <= lenght_down)
	{
		tmp = ft_strdup(file[lenght_up]);
		if (!tmp)
			return (clean_array(map), NULL);
		map[count++] = tmp;
		lenght_up++;
	}
	map[count] = 0;
	return (map);
}

int	lenght_down_map(char **file)
{
	int	count;

	count = 0;
	while (file[count + 1] != 0)
		count++;
	while (count > 5)
	{
		if (!is_valide_line(file[count]))
			break ;
		count--;
	}
	return (count);
}

int	lenght_top_map(char **file)
{
	int	count;

	count = 0;
	while (file[count] != 0)
	{
		if (!is_valide_line(file[count]))
			break ;
		count++;
	}
	return (count);
}

static int	is_valide_line(char *line)
{
	int	count;

	count = 0;
	if (line[0] == '\n' || line[0] == '\0')
		return (1);
	while (line[count])
	{
		if (map_set(line[count]) == 1)
			return (1);
		count++;
	}
	return (0);
}

static int	map_set(char c)
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
	return (1);
}
