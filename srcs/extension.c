/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:35:18 by strieste          #+#    #+#             */
/*   Updated: 2026/02/22 11:54:07 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
			continue;
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
	return (0);
}

void	print_arg_example(void)
{
	printf("Error\n");
	printf("Please configure the beginning of the file as follows :\n");
	printf("\nNorth texture : NO ./path_to_the_north_texture\n");
	printf("South texture : SO ./path_to_the_south_texture\n");
	printf("West texture  : WE ./path_to_the_west_texture\n");
	printf("East texture  : EA ./path_to_the_east_texture\n");
	printf("Floor color   : F 220,100,0\n");
	printf("Ceiling color : C 225,30,0\n");
	printf("\n(Info) R,G,B colors in range [0,255]: 0, 255, 255\n");
}
