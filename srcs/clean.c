/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:09:13 by strieste          #+#    #+#             */
/*   Updated: 2026/02/23 11:34:22 by strieste         ###   ########.fr       */
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

void	clean_struct_init(t_data *data)
{
	if (data->map)
		clean_array(data->map);
	if (data->no_texture)
		free(data->no_texture);
	if (data->so_texture)
		free(data->so_texture);
	if (data->we_texture)
		free(data->we_texture);
	if (data->ea_texture)
		free(data->ea_texture);
	if (data->rgb_ceiling)
		free(data->rgb_ceiling);
	if (data->rgb_floor)
		free(data->rgb_floor);	
}
