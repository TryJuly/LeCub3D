/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:38:21 by strieste          #+#    #+#             */
/*   Updated: 2026/02/23 09:34:06 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_after_map(char **file)
{
	int	count;
	int	i;

	count = (index_down_map(file) + 1);
	while (file[count] && file[count] != 0)
	{
		i = 0;
		while (file[count][i])
		{
			if (file[count][i] != ' ' && file[count][i] != '\t'
					&& (file[count][i] != '\0'))
			{
				ft_putstr_fd("Error\nArgument find after map\n", 2);
				return (1);
			}
			i++;
		}
		count++;
	}
	return (0);
}

int	is_valide_line(char *line)
{
	int	count;

	count = 0;
	while (line[count] && !ft_isalnum(line[count]))
		count++;
	if (!line || line[count] == '\0')
		return (0);
	if (ft_strlen(&line[count]) > 2 && !ft_strncmp(&line[count], "NO", 2))
		return (0);
	else if (ft_strlen(&line[count]) > 2 && !ft_strncmp(&line[count], "SO", 2))
		return (0);
	else if (ft_strlen(&line[count]) > 2 && !ft_strncmp(&line[count], "WE", 2))
		return (0);
	else if (ft_strlen(&line[count]) > 2 && !ft_strncmp(&line[count], "EA", 2))
		return (0);
	else if (ft_strlen(&line[count]) > 2 && !ft_strncmp(&line[count], "F ", 2))
		return (0);
	else if (ft_strlen(&line[count]) > 2 && !ft_strncmp(&line[count], "C ", 2))
		return (0);
	return (1);
}
