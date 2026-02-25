/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbezenco <cbezenco@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:21:50 by cbezenco          #+#    #+#             */
/*   Updated: 2026/02/25 15:12:40 by cbezenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

long	get_curr_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	loop(t_data *data)
{
	double	cam_x;
	int		x;

	clean_img(data->walls, data->image);
	x = 0;
	while (x < WIN_W)
	{
		cam_x = 2 * x / (double)WIN_W - 1;
		data->ray_dirx = data->dir_x + data->plane_x * cam_x;
		data->ray_diry = data->dir_y + data->plane_y * cam_x;
		calculate_ray(data, x, data->ray_dirx, data->ray_diry);
		x++;
	}
	//timing for input and fps counter
	data->oldtime = data->time;
	data->time = get_curr_time();
	data->frames = (data->time - data->oldtime) / 1000.0;
	//printf("%f\n", 1.0 / data->frames);
	//redraw the screen
	mlx_put_image_to_window(data->mlx, data->win, data->walls.img, 0, 0);
	//speed modifiers
	data->move_speed = data->frames * MOVE_SPEED;
	data->rot_speed = data->frames * ROT_SPEED;
	move_player(data);
	return (0);
}

int	win_close(t_data *data)
{
	clean_texture_init(data);
	mlx_destroy_image(data->mlx, data->walls.img);
	mlx_destroy_image(data->mlx, data->image.no_img.img);
	mlx_destroy_image(data->mlx, data->image.so_img.img);
	mlx_destroy_image(data->mlx, data->image.ea_img.img);
	mlx_destroy_image(data->mlx, data->image.we_img.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
