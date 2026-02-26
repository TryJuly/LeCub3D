/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:50:14 by strieste          #+#    #+#             */
/*   Updated: 2026/02/26 07:58:03 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	find_max_len(char **file, int start, int end);
static char	*replace_tab_line(char *line, int line_size);
static int	replace_tab(char ***map, int line_size);

char	**get_map(char **file, int lenght_up, int lenght_down, int count)
{
	char	**map;
	int		line_size;
	int		len;

	lenght_up = index_top_map(file);
	lenght_down = index_down_map(file);
	len = lenght_down - lenght_up;
	line_size = find_max_len(file, lenght_up, lenght_down) + 2;
	map = malloc((len + 2) * sizeof(char *));
	if (!map)
		return (NULL);
	count = 0;
	while (file[lenght_up] && lenght_up <= lenght_down)
	{
		map[count] = ft_calloc((line_size + 1), sizeof(char));
		if (!map[count])
			return (clean_array(map), NULL);
		ft_strcpy(map[count], file[lenght_up]);
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
	char	*tmp;
	int		count;

	count = 0;
	while ((*map)[count] && (*map)[count] != 0)
	{
		tmp = replace_tab_line((*map)[count], line_size);
		if (!tmp)
			return (1);
		free((*map)[count]);
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

int	is_valide_line_map(char *line)
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
