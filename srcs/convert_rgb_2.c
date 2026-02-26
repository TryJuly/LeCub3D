/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:20:10 by strieste          #+#    #+#             */
/*   Updated: 2026/02/26 07:55:14 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	create_rgb(int r, int g, int b);

int	get_rgb_color(char **file, char type)
{
	int	*color;
	int	result;

	if (type == 'c')
		color = get_rgb_c(file);
	else if (type == 'f')
		color = get_rgb_f(file);
	if (!color)
	{
		ft_putstr_fd("Error\nRGB color invalide\n", 2);
		printf("\n(Info) R,G,B colors in range [0,255]: 0, 255, 255\n");
		return (-1);
	}
	result = create_rgb(color[0], color[1], color[2]);
	free(color);
	return (result);
}

static int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_index_f(char **file)
{
	int	i;
	int	count;

	count = 0;
	while (file[count] != 0)
	{
		i = 0;
		while (file[count][i] && !ft_isalpha(file[count][i]))
			i++;
		if (ft_isalpha(file[count][i])
				&& !ft_strncmp(&file[count][i], "F ", 2))
			return (count);
		count++;
	}
	return (-1);
}

int	get_index_c(char **file)
{
	int	i;
	int	count;

	count = 0;
	while (file[count] != 0)
	{
		i = 0;
		while (file[count][i] && !ft_isalpha(file[count][i]))
			i++;
		if (ft_isalpha(file[count][i])
				&& !ft_strncmp(&file[count][i], "C ", 2))
			return (count);
		count++;
	}
	return (-1);
}
