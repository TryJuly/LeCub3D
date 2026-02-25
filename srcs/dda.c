/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbezenco <cbezenco@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:17:12 by cbezenco          #+#    #+#             */
/*   Updated: 2026/02/25 14:28:51 by cbezenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_ray(t_data *data, double ray_x, double ray_y)
{
	data->delta_d_x = fabs(1 / ray_x);
	data->delta_d_y = fabs(1 / ray_y);
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	//calcul de step et side_d
	if (ray_x < 0)
	{
		data->step_x = -1;
		data->side_d_x = (data->pos_x - data->map_x) * data->delta_d_x;
	}
	else
	{
		data->step_x = 1;
		data->side_d_x = (data->map_x + 1 - data->pos_x) * data->delta_d_x;
	}
	if (ray_y < 0)
	{
		data->step_y = -1;
		data->side_d_y = (data->pos_y - data->map_y) * data->delta_d_y;
	}
	else
	{
		data->step_y = 1;
		data->side_d_y = (data->map_y + 1 - data->pos_y) * data->delta_d_y;
	}
}

void	dda(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->side_d_x < data->side_d_y)
		{
			data->side_d_x += data->delta_d_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_d_y += data->delta_d_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		//check si collision
		if (data->map[data->map_y][data->map_x] != '0')
			data->hit = 1;
	}
	data->hit = 0;
}

void	calculate_ray(t_data *data, int x, double ray_x, double ray_y)
{
	init_ray(data, ray_x, ray_y);
	//DDA
	dda(data);
	if (data->side == 0)
	{
		data->wall_dist = data->side_d_x - data->delta_d_x;
		data->wall_x = data->pos_y + data->wall_dist * ray_y;
	}
	else
	{
		data->wall_dist = data->side_d_y - data->delta_d_y;
		data->wall_x = data->pos_x + data->wall_dist * ray_x;
	}
	data->wall_x -= floor(data->wall_x);
	data->text_x = (int)(data->wall_x * data->size);
	if (data->text_x < 0)
		data->text_x = 0;
	else if (data->text_x >= data->size)
		data->text_x = data->size - 1;
	//hauteur de la ligne a dessiner
	data->line_h = (int)(WIN_H / (data->wall_dist));
	//calcul du plus haut et du plus bas pixel de la vertical stripe
	draw_walls(data, x);
}
