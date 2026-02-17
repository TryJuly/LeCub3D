/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:35:18 by strieste          #+#    #+#             */
/*   Updated: 2026/02/17 14:35:34 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	valide_extension(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '.' && !ft_strncmp(&str[i], ".cub", 4))
		{
			count++;
			i += 3;
			continue;
		}
		i++;
	}
	i -= 4;
	if (ft_strncmp(&str[i], ".cub", 4) != 0)
		return (ft_putstr_fd("Not a valide extension\n", 2), 1);
	if (count > 1)
		return (ft_putstr_fd("More than 1 '.cub' extension\n", 2), 1);
	if (count < 1)
		return (ft_putstr_fd("Not a valide extention\n", 2), 1);
	return (0);
}
