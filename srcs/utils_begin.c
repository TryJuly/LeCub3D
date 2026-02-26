/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_begin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 07:46:15 by strieste          #+#    #+#             */
/*   Updated: 2026/02/26 13:18:27 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	get_identifier(char *line)
{
	int	count;

	count = 0;
	while (line[count] && !ft_isalnum(line[count]))
		count++;
	if (!line || line[count] == '\0')
		return (0);
	else if (ft_strlen(&line[count]) > 2 && !ft_strncmp(&line[count], "NO", 2))
		return ('N');
	else if (ft_strlen(&line[count]) > 2 && !ft_strncmp(&line[count], "SO", 2))
		return ('S');
	else if (ft_strlen(&line[count]) > 2 && !ft_strncmp(&line[count], "WE", 2))
		return ('W');
	else if (ft_strlen(&line[count]) > 2 && !ft_strncmp(&line[count], "EA", 2))
		return ('E');
	else if (ft_strlen(&line[count]) > 2 && !ft_strncmp(&line[count], "F ", 2))
		return ('F');
	else if (ft_strlen(&line[count]) > 2 && !ft_strncmp(&line[count], "C ", 2))
		return ('C');
	return (0);
}

int	is_blank(char *line)
{
	size_t	count;

	count = 0;
	while (line[count])
	{
		if (line[count] != ' ' && line[count] != '\t')
			return (1);
		count++;
	}
	return (0);
}

int	lenght_tab(char **tab)
{
	int	count;

	count = 0;
	while (tab[count] != 0)
		count++;
	return (count);
}

int	is_wspace_line(char *line)
{
	int	count;

	count = 0;
	while (line[count])
	{
		if (ft_isprint(line[count]) && line[count] != ' ')
			return (1);
		count++;
	}
	return (0);
}
