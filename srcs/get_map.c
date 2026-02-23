/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:50:14 by strieste          #+#    #+#             */
/*   Updated: 2026/02/23 13:08:46 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	map_set(char c);
static int	is_valide_line_map(char *line);
static int	find_max_len(char **file, int start, int end);
static char	*replace_tab_line(char *line, int line_size);
static int	replace_tab(char ***map, int line_size);

char	**get_map(char **file, int	lenght_up, int lenght_down, int count)
{
	char	**map;
	int		line_size;

	lenght_up = index_top_map(file);
	lenght_down = index_down_map(file);
	line_size = find_max_len(file, lenght_up, lenght_down) + 2;
	map = ft_calloc(((lenght_down - lenght_up) + 2), sizeof(char *));
	if (!map)
		return (NULL);
	count = 0;
	while (file[lenght_up] && lenght_up <= lenght_down)
	{
		map[count] = ft_calloc((line_size + 1), sizeof(char));
		if (!map[count])
			return (clean_array(map), NULL);
		ft_strlcpy(map[count], file[lenght_up], ft_strlen(file[lenght_up]) + 1);
		count++;
		lenght_up++;
	}
	map[count] = 0;
	if (replace_tab(&map, line_size))
		return (clean_array(map), NULL);
	return (map);
}

static int	replace_tab(char ***map, int line_size)
{
	char *tmp;
	int	count;

	count = 0;
	while ((*map)[count] && (*map)[count] != 0)
	{
		tmp = replace_tab_line((*map)[count], line_size);
		if (!tmp)
			return (1);
		(*map)[count] = tmp;
		count++;
	}
	return (0);
}

static char	*replace_tab_line(char *line, int line_size)
{
	int		i;
	int		j;
	int		count;
	char	*tmp;

	tmp = ft_calloc(line_size, sizeof(char));
	if (!tmp)
		return (NULL);
	count = 0;
	i = 0;
	while (line[count])
	{
		if (line[count] == '\t')
		{
			j = 4;
			while (j--)
				tmp[i++] = ' ';
			count++;
			continue ;
		}
		tmp[i++] = line[count++];
	}
	tmp[i] = '\0';
	return (tmp);
}

static int	find_max_len(char **file, int start, int end)
{
	int	res;
	int	count;
	int	tab_count;

	if (!file || !file[0])
		return (-1);
	res = 0;
	while (file[start] && start <= end)
	{
		count = 0;
		tab_count = 0;
		while (file[start][count])
		{
			if (file[start][count] == '\t')
				tab_count += 4;
			if ((tab_count + count) > res)
				res = (count + tab_count);
			count++;
		}
		start++;
	}
	return (res);
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
	return (-1);
}

static int	is_valide_line_map(char *line)
{
	int	count;
	int	valide;

	count = 0;
	valide = 0;
	if (line[0] == '\n' || line[0] == '\0')
		return (1);
	while (line[count])
	{
		if (ft_isalnum(line[count]))
			valide = 1;
		count++;
	}
	if (!valide)
		return (1);
	count = 0;
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
