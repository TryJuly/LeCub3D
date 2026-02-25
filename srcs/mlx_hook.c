/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbezenco <cbezenco@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:39:06 by cbezenco          #+#    #+#             */
/*   Updated: 2026/02/25 15:06:50 by cbezenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == W)
		data->keys.w = 1;
	if (keycode == S)
		data->keys.s = 1;
	if (keycode == A)
		data->keys.a = 1;
	if (keycode == D)
		data->keys.d = 1;
	if (keycode == LEFT)
		data->keys.left = 1;
	if (keycode == RIGHT)
		data->keys.right = 1;
	if (keycode == ESC)
		win_close(data);
	return (0);
}

int	key_released(int kcode, t_data *data)
{
	if (kcode == W)
		data->keys.w = 0;
	if (kcode == S)
		data->keys.s = 0;
	if (kcode == A)
		data->keys.a = 0;
	if (kcode == D)
		data->keys.d = 0;
	if (kcode == LEFT)
		data->keys.left = 0;
	if (kcode == RIGHT)
		data->keys.right = 0;
	return (0);
}

void	move_player_3(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;
	int		left;

	if (data->keys.left == 1)
		left = -1;
	if (data->keys.right == 1)
		left = 1;
	if (data->keys.left == 1 || data->keys.right == 1)
	{
		old_dir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(data->rot_speed * left)
			- data->dir_y * sin(data->rot_speed * left);
		data->dir_y = old_dir_x * sin(data->rot_speed * left)
			+ data->dir_y * cos(data->rot_speed * left);
		old_plane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(data->rot_speed * left)
			- data->plane_y * sin(data->rot_speed * left);
		data->plane_y = old_plane_x * sin(data->rot_speed * left)
			+ data->plane_y * cos(data->rot_speed * left);
	}
}

void	move_player_2(t_data *data)
{
	double	side_dirx;
	double	side_diry;

	if (data->keys.a == 1)
	{
		side_dirx = data->dir_x * cos(-PI / 2) - data->dir_y * sin(-PI / 2);
		side_diry = data->dir_x * sin(-PI / 2) + data->dir_y * cos(-PI / 2);
		if (data->map[(int)(data->pos_y + side_diry * data->move_speed)]
			[(int)(data->pos_x + side_dirx * data->move_speed)] == '0')
		{
			data->pos_y += side_diry * data->move_speed;
			data->pos_x += side_dirx * data->move_speed;
		}
	}
	if (data->keys.d == 1)
	{
		side_dirx = data->dir_x * cos(PI / 2) - data->dir_y * sin(PI / 2);
		side_diry = data->dir_x * sin(PI / 2) + data->dir_y * cos(PI / 2);
		if (data->map[(int)(data->pos_y + side_diry * data->move_speed)]
			[(int)data->pos_x] == '0')
			data->pos_y += side_diry * data->move_speed;
		if (data->map[(int)data->pos_y]
			[(int)(data->pos_x + side_dirx * data->move_speed)] == '0')
			data->pos_x += side_dirx * data->move_speed;
	}
}

void	move_player(t_data *data)
{
	if (data->keys.w == 1)
	{
		if (data->map[(int)(data->pos_y + data->dir_y * data->move_speed)]
			[(int)data->pos_x] == '0')
			data->pos_y += data->dir_y * data->move_speed;
		if (data->map[(int)data->pos_y]
			[(int)(data->pos_x + data->dir_x * data->move_speed)] == '0')
			data->pos_x += data->dir_x * data->move_speed;
	}
	if (data->keys.s == 1)
	{
		if (data->map[(int)(data->pos_y - data->dir_y * data->move_speed)]
			[(int)data->pos_x] == '0')
			data->pos_y -= data->dir_y * data->move_speed;
		if (data->map[(int)data->pos_y]
			[(int)(data->pos_x - data->dir_x * data->move_speed)] == '0')
			data->pos_x -= data->dir_x * data->move_speed;
	}
	move_player_2(data);
	move_player_3(data);
}
