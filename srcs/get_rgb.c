/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:18:40 by strieste          #+#    #+#             */
/*   Updated: 2026/02/18 12:23:32 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	get_lenght_f(char **file);

int	*get_rgb_f(char **file)
{
	int	*tab;
	int	count;

	count = get_lenght_f(file);
	tab = malloc(3 * sizeof(int));
	if (!tab)
		return (-1);
}

static int	get_lenght_f(char **file)
{
	int	i;
	int	count;

	count = 0;
	while (file[count] != 0)
	{
		i = 0;
		while (!ft_isalpha(file[count][i]))
			i++;
		if (!ft_strncmp(&file[count][i], "F ", 2))
			break ;
		count++;
	}
	return (count);
}
