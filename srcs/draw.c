/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbezenco <cbezenco@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:41:03 by cbezenco          #+#    #+#             */
/*   Updated: 2026/02/25 14:21:08 by cbezenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(t_data *data)
{
	int		color;
	t_img	*img;

	if (data->side == 1 && data->ray_diry < 0)
		img = &data->image.no_img;
	if (data->side == 0 && data->ray_dirx >= 0)
		img = &data->image.ea_img;
	if (data->side == 1 && data->ray_diry >= 0)
		img = &data->image.so_img;
	if (data->side == 0 && data->ray_dirx < 0)
		img = &data->image.we_img;
	color = 0;
	color += img->addr[(int)(data->text_y * img->line_length + data->text_x
			* (img->bits_per_pixel / 8) + 2)] * 65536;
	color += img->addr[(int)(data->text_y * img->line_length + data->text_x
			* (img->bits_per_pixel / 8) + 1)] * 256;
	color += img->addr[(int)(data->text_y * img->line_length + data->text_x
			* (img->bits_per_pixel / 8))];
	return (color);
}

void	set_text_y(t_data *data, int y)
{
	double	scale;

	scale = y * data->image.no_img.line_length - (WIN_H) / 2
		* data->image.no_img.line_length + data->line_h
		* data->image.no_img.line_length / 2;
	data->text_y = (int)(((scale * data->size) / data->line_h)
			/ data->image.no_img.line_length);
	if (data->text_y < 0)
		data->text_y = 0;
	else if (data->text_y >= data->size)
		data->text_y = data->size - 1;
}

void	draw_walls(t_data *data, int x)
{
	int		draw_start;
	int		draw_end;
	int		y;
	int		color;

	draw_start = -data->line_h / 2 + WIN_H / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = data->line_h / 2 + WIN_H / 2;
	if (draw_end >= WIN_H)
		draw_end = WIN_H - 1;
	//dessiner la vertical stripe
	y = draw_start;
	while (y <= draw_end)
	{
		set_text_y(data, y);
		color = get_color(data);
		my_pixel_put(&data->walls, x, y, color);
		y++;
	}
}

void	clean_img(t_img img, t_texture color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			if (y < WIN_H / 2)
				my_pixel_put(&img, x, y, color.rgb_c);
			else
				my_pixel_put(&img, x, y, color.rgb_f);
			x++;
		}
		y++;
	}
}
