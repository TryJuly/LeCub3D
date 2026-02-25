/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:57:36 by strieste          #+#    #+#             */
/*   Updated: 2026/02/25 10:06:02 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
void	print_texture(t_data *data);

int	main(int ac, char **av)
{
	t_data	data;
	
	(void)av;
	if (ac != 2)
		return (printf("Error\nArgument missing\n"), 1);
	if (parsing(av[1], &data))
		return (1);
	if (init_texture(&data))
		return (1);
	print_texture(&data);
	printf("Good\n");
	// data.mlx = mlx_init();
	// data.win = mlx_new_window(data.mlx, WIN_W, WIN_H, "Cub3D");
	// data.walls.img = mlx_new_image(data.mlx, WIN_W, WIN_H);
	// data.walls.addr = mlx_get_data_addr(data.walls.img, &data.walls.bits_per_pixel, &data.walls.line_length, &data.walls.endian);
	// init_data(&data);
	// mlx_hook(data.win, 2, (1L << 0), key_pressed, &data);
	// mlx_hook(data.win, 3, (1L << 1), key_released, &data);
	// mlx_hook(data.win, 17, (0L), win_close, &data);
	// mlx_loop_hook(data.mlx, loop, &data);
	// mlx_loop(data.mlx);
	return (0);
}

void	print_texture(t_data *data)
{
	printf("No = %s\n", data->image.no_texture);
	printf("So = %s\n", data->image.so_texture);
	printf("EA = %s\n", data->image.ea_texture);
	printf("WE = %s\n", data->image.we_texture);
	printf("F = %d\n", data->image.rgb_f);
	printf("C = %d\n", data->image.rgb_c);
}