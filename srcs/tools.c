/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 07:49:52 by strieste          #+#    #+#             */
/*   Updated: 2026/02/26 09:27:14 by strieste         ###   ########.fr       */
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
