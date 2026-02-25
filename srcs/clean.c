/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:09:13 by strieste          #+#    #+#             */
/*   Updated: 2026/02/25 10:03:52 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clean_array(char **array)
{
	int	count;

	if (!array)
		return ;
	count = 0;
	while (array[count] !=  0)
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
	while ((*array)[count] !=  0)
		free((*array)[count++]);
	free(*array);
	(*array) = NULL;
	return ;
}

void	clean_texture_init(t_data *data)
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
