/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:35:18 by strieste          #+#    #+#             */
/*   Updated: 2026/02/26 13:49:21 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	only_one(char *filename);

int	valide_extension(char *filename)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (filename[i])
	{
		if (filename[i] == '.' && !ft_strncmp(&filename[i], ".cub", 4))
		{
			count++;
			i += 4;
			continue ;
		}
		i++;
	}
	i -= 4;
	if (ft_strncmp(&filename[i], ".cub", 4) != 0)
		return (ft_putstr_fd("Not a valide extension\n", 2), 1);
	if (count > 1)
		return (ft_putstr_fd("More than 1 '.cub' extension\n", 2), 1);
	if (count < 1)
		return (ft_putstr_fd("Not a valide extention\n", 2), 1);
	if (only_one(filename))
		return (ft_putstr_fd("Not a valide extention\n", 2), 1);
	return (0);
}

static int	only_one(char *filename)
{
	int	count;

	count = 0;
	while (filename[count])
	{
		if (filename[count] == '.')
		{
			if (!ft_strncmp(&filename[count], ".cub", 5))
				return (0);
			else
				return (1);
		}
		count++;
	}
	return (1);
}