/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 10:36:51 by strieste          #+#    #+#             */
/*   Updated: 2026/02/26 10:37:03 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_error_texture(t_data *data)
{
	if (data->image.no_img.img)
		mlx_destroy_image(data->mlx, data->image.no_img.img);
	if (data->image.so_img.img)
		mlx_destroy_image(data->mlx, data->image.so_img.img);
	if (data->image.ea_img.img)
		mlx_destroy_image(data->mlx, data->image.ea_img.img);
	if (data->image.we_img.img)
		mlx_destroy_image(data->mlx, data->image.we_img.img);
}
