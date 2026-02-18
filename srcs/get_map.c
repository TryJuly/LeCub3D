/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:50:14 by strieste          #+#    #+#             */
/*   Updated: 2026/02/18 11:47:46 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	lenght_up_map(char **file);
static int	lenght_down_map(char **file);

char	**get_map(char **file)
{
	int		count;
	char	**map;
	char	*tmp;
	int		lenght_up;
	int		lenght_down;

	lenght_up = lenght_up_map(file);
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

static int	lenght_down_map(char **file)
{
	int	i;
	int	count;

	count = 0;
	while (file[count + 1] != 0)
		count++;
	while (count > 5)
	{
		i = 0;
		while (file[count][i] && ft_strlen(&file[count][i]) > 4
				&& ft_strncmp(&file[count][i], "1111", 4))
			i++;
		if (!ft_strncmp(&file[count][i], "1111", 4))
			break ;
		count--;
	}
	return (count);
}

static int	lenght_up_map(char **file)
{
	int	i;
	int	count;

	count = 0;
	while (file[count] != 0)
	{
		i = 0;
		while (file[count][i] && ft_strncmp(&file[count][i], "1111", 4))
			i++;
		if (!ft_strncmp(&file[count][i], "1111", 4))
			break ;
		count++;
	}
	return (count);
}
