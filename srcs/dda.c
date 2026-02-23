/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbezenco <cbezenco@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:17:12 by cbezenco          #+#    #+#             */
/*   Updated: 2026/02/23 13:02:51 by cbezenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	get_color(int num)
{
	int	color;

	color = 0;
	if (num == '1')
		color = RED;
	else if (num == 2)
		color = GREEN;
	else if (num == 3)
		color = BLUE;
	else if (num == 4)
		color = RED;
	else if (num == 5)
		color = BLUE;
	else
		color = 0x00FFFFFF;
	return (color);
}

void	draw_walls(t_data *data, int x)
{
	int	draw_start;
	int	draw_end;
	int	color;
	int	y;

	draw_start = -data->line_h / 2 + WIN_H / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = data->line_h / 2 + WIN_H / 2;
	if (draw_end >= WIN_H)
		draw_end = WIN_H - 1;
	color = get_color(data->map[data->map_y][data->map_x]);
	//selon le coté, brightness différentes
	if (data->side == 1)
		color = color / 2;
	//dessiner la vertical stripe
	y = draw_start;
	while (y <= draw_end)
	{
		my_pixel_put(&data->walls, x, y, color);
		y++;
	}
}

void	calculate_ray(t_data *data, int x, double ray_x, double ray_y)
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
	//DDA
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
	if (data->side == 0)
		data->wall_dist = data->side_d_x - data->delta_d_x;
	else
		data->wall_dist = data->side_d_y - data->delta_d_y;
	//hauteur de la ligne a dessiner
	data->line_h = (int)(WIN_H / (data->wall_dist));
	//calcul du plus haut et du plus bas pixel de la vertical stripe
	draw_walls(data, x);
}

long	get_curr_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	clean_img(t_img img)
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
				my_pixel_put(&img, x, y, SKY);
			else
				my_pixel_put(&img, x, y, BROWN);
			x++;
		}
		y++;
	}
}

int	loop(t_data *data)
{
	double	cam_x;
	int		x;

	clean_img(data->walls);
	//move_player(data);
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
	if ((1.0 / data->frames) > 60)
	{
		while ((1.0 / data->frames) > 60)
		{
			data->time = get_curr_time();
			data->frames = (data->time - data->oldtime) / 1000.0;
		}
	}
	//printf("%f\n", (1.0 / data->frames)); // fps counter
	//redraw the screen
	mlx_put_image_to_window(data->mlx, data->win, data->walls.img, 0, 0);
	//speed modifiers
	data->move_speed = data->frames * 5.0;
	data->rot_speed = data->frames * 3.0;
	return (0);
}

int	key_pressed(int	keycode, t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;
	double	side_dirx;
	double	side_diry;

	if (keycode == W)
	{
		data->keys.w = 1;
		if (data->map[(int)(data->pos_y + data->dir_y * data->move_speed)][(int)data->pos_x] == '0')
			data->pos_y += data->dir_y * data->move_speed;
		if (data->map[(int)data->pos_y][(int)(data->pos_x + data->dir_x * data->move_speed)] == '0')
			data->pos_x += data->dir_x * data->move_speed;
	}
	if (keycode == S)
	{
		data->keys.s = 1;
		if (data->map[(int)(data->pos_y - data->dir_y * data->move_speed)][(int)data->pos_x] == '0')
			data->pos_y -= data->dir_y * data->move_speed;
		if (data->map[(int)data->pos_y][(int)(data->pos_x - data->dir_x * data->move_speed)] == '0')
			data->pos_x -= data->dir_x * data->move_speed;
	}
	if (keycode == A)
	{
		data->keys.a = 1;
		side_dirx = data->dir_x * cos(-PI / 2) - data->dir_y * sin(-PI / 2);
		side_diry = data->dir_x * sin(-PI / 2) + data->dir_y * cos(-PI / 2);
		if (data->map[(int)(data->pos_y + side_diry * data->move_speed)][(int)(data->pos_x + side_dirx * data->move_speed)] == '0')
		{
			data->pos_y += side_diry * data->move_speed;
			data->pos_x += side_dirx * data->move_speed;
		}
	}
	if (keycode == D)
	{
		data->keys.d = 1;
		side_dirx = data->dir_x * cos(PI / 2) - data->dir_y * sin(PI / 2);
		side_diry = data->dir_x * sin(PI / 2) + data->dir_y * cos(PI / 2);
		if (data->map[(int)(data->pos_y + side_diry * data->move_speed)][(int)data->pos_x] == '0')
			data->pos_y += side_diry * data->move_speed;
		if (data->map[(int)data->pos_y][(int)(data->pos_x + side_dirx * data->move_speed)] == '0')
			data->pos_x += side_dirx * data->move_speed;
	}
	if (keycode == LEFT)
	{
		data->keys.left = 1;
		old_dir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(-data->rot_speed) - data->dir_y * sin(-data->rot_speed);
		data->dir_y = old_dir_x * sin(-data->rot_speed) + data->dir_y * cos(-data->rot_speed);
		old_plane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(-data->rot_speed) - data->plane_y * sin(-data->rot_speed);
		data->plane_y = old_plane_x * sin(-data->rot_speed) + data->plane_y * cos(-data->rot_speed);
	}
	if (keycode == RIGHT)
	{
		data->keys.right = 1;
		old_dir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(data->rot_speed) - data->dir_y * sin(data->rot_speed);
		data->dir_y = old_dir_x * sin(data->rot_speed) + data->dir_y * cos(data->rot_speed);
		old_plane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(data->rot_speed) - data->plane_y * sin(data->rot_speed);
		data->plane_y = old_plane_x * sin(data->rot_speed) + data->plane_y * cos(data->rot_speed);
	}
	printf("%f : plane_x | %f : plane_y | %f : dir_x | %f : dir_y \n", data->plane_x, data->plane_y, data->dir_x, data->dir_y);
	printf("%f : move_speed | %f : rot_speed\n", data->move_speed, data->rot_speed);
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

void	print_map(t_data *data);

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// void	print_player(t_data *data, t_img *img, int color)
// {
// 	int		x;
// 	int		y;
// 	int		r;
// 	int		angle;

// 	x = 0;
// 	y = 0;
// 	r = 10;
// 	while (r > 0)
// 	{
// 		angle = 0;
// 		while (angle < 360)
// 		{
// 			x = data->pos_x + GRIDSIZE / 2 + r * cos(angle);
// 			y = data->pos_y + GRIDSIZE / 2 + r * sin(angle);
// 			my_pixel_put(img, x, y, color);
// 			angle++;
// 		}
// 		r--;
// 	}
// }

// int	set_p_coord(int keycode, t_data *data)
// {
// 	if ((keycode == 119))
// 		data->w = 1;
// 	else if ((keycode == 115))
// 		data->s = 1;
// 	else if ((keycode == 97))
// 		data->a = 1;
// 	else if ((keycode == 100))
// 		data->d = 1;
// 	else if (keycode == 65361)
// 		data->angle += 5;
// 	else if (keycode == 65363)
// 		data->angle -= 5;
// 	else
// 		printf("%i \n", keycode);
// 	return (1);
// }

// int	player_move(t_data *data)
// {
// 	if (data->w == 1)
// 	{
// 		if (data->map[(int)(data->pos.y - 1) / GRIDSIZE][(int)(data->pos.x) / GRIDSIZE] == '0')
// 			data->pos.y -= 1;
// 	}
// 	if (data->s == 1)
// 	{
// 		if (data->map[(int)(data->pos.y + 1 + GRIDSIZE) / GRIDSIZE][(int)(data->pos.x) / GRIDSIZE] == '0')
// 			data->pos.y += 1;
// 	}
// 	if (data->a == 1)
// 	{
// 		if (data->map[(int)(data->pos.y) / GRIDSIZE][(int)(data->pos.x - 1) / GRIDSIZE] == '0')
// 			data->pos.x -= 1;
// 	}
// 	if (data->d == 1)
// 	{
// 		if (data->map[(int)(data->pos.y) / GRIDSIZE][(int)(data->pos.x + 1 + GRIDSIZE) / GRIDSIZE] == '0')
// 			data->pos.x += 1;
// 	}
// 	if (data->w == 1 || data->s == 1 || data->a == 1 || data->d == 1)
// 	{
// 		print_map(data);
// 	}
// 	return (0);
// }

int	win_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

// int	press_key(int keycode, t_data *data)
// {
// 	if (keycode == 65307)
// 		win_close(data);
// 	if (!set_p_coord(keycode, data))
// 		return (0);
// 	return (0);
// }

// int	release_key(int keycode, t_data *data)
// {
// 	if ((keycode == 119))
// 		data->w = 0;
// 	else if ((keycode == 115))
// 		data->s = 0;
// 	else if ((keycode == 97))
// 		data->a = 0;
// 	else if ((keycode == 100))
// 		data->d = 0;
// 	else if (keycode == 65361)
// 		data->angle += 5;
// 	else if (keycode == 65363)
// 		data->angle -= 5;
// 	else
// 		printf("%i \n", keycode);
// 	return (1);
// }

// int	get_width(char **map)
// {
// 	int	i_max;
// 	int	i;
// 	int	j;

// 	i_max = 0;
// 	j = 0;
// 	while (map[j])
// 	{
// 		i = 0;
// 		while (map[j][i])
// 			i++;
// 		if (i > i_max)
// 			i_max = i;
// 		j++;
// 	}
// 	return (i_max);
// }

// int	get_height(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map[i])
// 		i++;
// 	return (i);
// }

// void	print_grid(t_img map, int x, int y, int color)
// {
// 	int	i;
// 	int	j;

// 	j = y + 1;
// 	while (j < y + GRIDSIZE - 1)
// 	{
// 		i = x + 1;
// 		while (i < x + GRIDSIZE - 1)
// 		{
// 			my_pixel_put(&map, i, j, color);
// 			i++;
// 		}
// 		j++;
// 	}
// }

// void	print_map(t_data *data)
// {
// 	int		x;
// 	int		y;
// 	t_img	temp;

// 	temp.img = mlx_new_image(data->mlx, WIN_W, WIN_H);
// 	temp.addr = mlx_get_data_addr(temp.img, &temp.bits_per_pixel, &temp.line_length, &temp.endian);
// 	y = 0;
// 	while (data->map[y])
// 	{
// 		x = 0;
// 		while (data->map[y][x])
// 		{
// 			if (data->map[y][x] == '1')
// 				print_grid(temp, x * GRIDSIZE, y * GRIDSIZE, RED);
// 			else if (data->map[y][x] == '0')
// 				print_grid(temp, x * GRIDSIZE, y * GRIDSIZE, BLUE);
// 			else if (data->map[y][x] == 'N')
// 			{
// 				if (data->pos.x == 0 && data->pos.y == 0)
// 				{
// 					data->pos.x = x * GRIDSIZE;
// 					data->pos.y = y * GRIDSIZE;
// 				}
// 				print_grid(temp, x * GRIDSIZE, y * GRIDSIZE, BLUE);
// 				data->map[y][x] = '0';
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	print_player(data, &temp, GREEN);
// 	mlx_destroy_image(data->mlx, data->mapi.img);
// 	data->mapi = temp;
// 	mlx_put_image_to_window(data->mlx, data->win, data->mapi.img, 0, 0);
// }

void	get_player_dir(t_data *data, char dir)
{
	if (dir == 'N')
	{
		data->dir_x = 0;
		data->dir_y = -1;
		data->plane_x = 0.66;
		data->plane_y = 0;
	}
	else if (dir == 'S')
	{
		data->dir_x = 0;
		data->dir_y = 1;
		data->plane_x = -0.66;
		data->plane_y = 0;
	}
	else if (dir == 'W')
	{
		data->dir_x = -1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = -0.66;
	}
	else if (dir == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = 0.66;
	}
}

void	get_player_coord(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] != '1' && data->map[y][x] != '0' && ft_isalpha(data->map[y][x]))
			{
				data->pos_x = x;
				data->pos_y = y;
				get_player_dir(data, data->map[y][x]);
				data->map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}

void	init_data(t_data *data)
{
	get_player_coord(data);
	data->time = get_curr_time();
	data->oldtime = 0;
	data->hit = 0;
}
