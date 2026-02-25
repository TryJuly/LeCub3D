/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbezenco <cbezenco@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:09:13 by strieste          #+#    #+#             */
/*   Updated: 2026/02/25 14:59:20 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clean_array(char **array)
{
	int	count;

	if (!array || !*array)
		return ;
	count = 0;
	while (array[count] && array[count] !=  0)
		free(array[count++]);
	free(array);
	return ;
}

void	clean_array_null(char ***array)
{
	int	count;

	if (!*(array) || !*(*array))
		return ;
	count = 0;
	while ((*array)[count] && (*array)[count] !=  0)
		free((*array)[count++]);
	free(*array);
	(*array) = NULL;
	return ;
}

void	clean_texture_map(t_data *data)
{
	if (data->map)
		clean_array(data->map);
	if (data->image.no_texture)
		free(data->image.no_texture);
	if (data->image.so_texture)
		free(data->image.so_texture);
	if (data->image.we_texture)
		free(data->image.we_texture);
	if (data->image.ea_texture)
		free(data->image.ea_texture);
}

void	clean_texture_init(t_data *data)
{
	if (data->image.no_texture)
	{
		free(data->image.no_texture);
		data->image.no_texture = 0;
	}
	if (data->image.so_texture)
	{
		free(data->image.so_texture);
		data->image.so_texture = 0;
	}
	if (data->image.we_texture)
	{
		free(data->image.we_texture);
		data->image.we_texture = 0;
	}
	if (data->image.ea_texture)
	{
		free(data->image.ea_texture);
		data->image.ea_texture = 0;
	}
}

void	clean_data_end(t_data *data)
{
	clean_texture_init(data);
	mlx_destroy_image(data->mlx, data->image.no_img.img);
	mlx_destroy_image(data->mlx, data->image.so_img.img);
	mlx_destroy_image(data->mlx, data->image.ea_img.img);
	mlx_destroy_image(data->mlx, data->image.we_img.img);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}
