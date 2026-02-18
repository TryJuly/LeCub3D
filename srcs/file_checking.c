/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:38:21 by strieste          #+#    #+#             */
/*   Updated: 2026/02/18 14:54:03 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check_before_map(char **file);

int	is_valide_file(char **file)
{
	int	count;

	count = 0;
	while (file[count] != 0)
	{
		
	}
}

static int	check_before_map(char **file)
{
	int	count;

	count = (lenght_top_map(file) - 1);
	while (count <= 0)
	{
		if (is_valide_line(file[count]))
			return (1);
		count--;
	}
	return (0);
}

static int	is_valide_line(char *line)
{
	int	count;

	if (line[0] == '\0')
		return (0);
	count = 0;
	while (!ft_isalnum(line[count]))
		count++;
	if (ft_strlen(&line[count]) > 4 && !ft_strncmp(&line[count], "NO", 2))
		return (0);
	if (ft_strlen(&line[count]) > 4 && !ft_strncmp(&line[count], "SO", 2))
		return (0);
	if (ft_strlen(&line[count]) > 4 && !ft_strncmp(&line[count], "WE", 2))
		return (0);
	if (ft_strlen(&line[count]) > 4 && !ft_strncmp(&line[count], "EA", 2))
		return (0);
	if (ft_strlen(&line[count]) > 4 && !ft_strncmp(&line[count], "F ", 2))
		return (0);
	if (ft_strlen(&line[count]) > 4 && !ft_strncmp(&line[count], "C", 2))
		return (0);
	return (1);
}
