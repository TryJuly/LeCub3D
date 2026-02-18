/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbezenco <cbezenco@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:57:36 by strieste          #+#    #+#             */
/*   Updated: 2026/02/18 14:51:58 by cbezenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_player(t_img *img, t_data *data, int color)
{
	t_img	temp;
	int		x;
	int		y;

	x = 0;
	temp.img = mlx_new_image(data->mlx, GRIDSIZE, GRIDSIZE);
	temp.addr = mlx_get_data_addr(temp.img, &temp.bits_per_pixel, &temp.line_length, &temp.endian);
	while (x < GRIDSIZE)
	{
		y = 0;
		while (y < GRIDSIZE)
		{
			my_pixel_put(&temp, x, y, color);
			y++;
		}
		x++;
	}
	mlx_destroy_image(data->mlx, img->img);
	*img = temp;
}

int	set_p_coord(int keycode, t_data *data)
{
	print_player(&data->player, data, 0x00000000);
	mlx_put_image_to_window(data->mlx, data->win, data->player.img, data->pos.x, data->pos.y);
	if ((keycode == 119))
		data->pos.y -= 5;
	else if ((keycode == 115))
		data->pos.y += 5;
	else if ((keycode == 97))
		data->pos.x -= 5;
	else if ((keycode == 100))
		data->pos.x += 5;
	else if (keycode == 65361)
		data->angle += 5;
	else if (keycode == 65363)
		data->angle -= 5;
	else
		printf("%i \n", keycode);
	return (1);
}

int	player_move(t_data *data)
{
	print_player(&data->player, data, 0x00FF0000);
	mlx_put_image_to_window(data->mlx, data->win, data->player.img, data->pos.x, data->pos.y);
	return (0);
}

int	win_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		win_close(data);
	if (!set_p_coord(keycode, data))
		return (0);
	return (0);
}

int	get_width(char **map)
{
	int	i_max;
	int	i;
	int	j;

	i_max = 0;
	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
			i++;
		if (i > i_max)
			i_max = i;
		j++;
	}
	return (i_max);
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	print_grid(t_img map, int x, int y)
{
	int	i;
	int	j;

	j = y;
	while (j < y + GRIDSIZE)
	{
		i = x;
		while (i < x + GRIDSIZE)
		{
			my_pixel_put(&map, i, j, BLUE);
			i++;
		}
		j++;
	}
}

void	print_map(t_data *data)
{
	int	width;
	int	height;
	int	x;
	int	y;

	width = get_width(data->map) * GRIDSIZE;
	height = get_height(data->map) * GRIDSIZE;
	data->mapi.img = mlx_new_image(data->mlx, width, height);
	data->mapi.addr = mlx_get_data_addr(data->mapi.img, &data->mapi.bits_per_pixel, &data->mapi.line_length, &data->mapi.endian);
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			print_grid(data->mapi, x * GRIDSIZE, y * GRIDSIZE);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->mapi.img, 200, 200);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac > 2)
		return (0);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1000, 1000, "Cub3D");
	data.pos.x = 500;
	data.pos.y = 500;
	data.angle = 0;
	data.map = get_map(&av[1]);
	print_map(&data);
	//data.player.img = mlx_new_image(data.mlx, GRIDSIZE, GRIDSIZE);
	//data.player.addr = mlx_get_data_addr(data.player.img, &data.player.bits_per_pixel, &data.player.line_length, &data.player.endian);
	//print_player(&data.player, &data, 0x00FF0000);
	//mlx_put_image_to_window(data.mlx, data.win, data.player.img, data.pos.x, data.pos.y);
	//mlx_hook(data.win, 2, (1L << 0), handle_key, &data);
	mlx_hook(data.win, 17, (0L), win_close, &data);
	//mlx_loop_hook(data.mlx, player_move, &data);
	mlx_loop(data.mlx);
}
