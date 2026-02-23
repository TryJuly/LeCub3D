/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbezenco <cbezenco@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:57:36 by strieste          #+#    #+#             */
/*   Updated: 2026/02/23 13:02:55 by cbezenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	char	**tab;
	t_data	data;

	(void)ac;
	(void)av;
	tab = clean_extract(av[1]);
	if (!tab)
		return (1);
	data.map = get_map(tab);
	if (!data.map)
		return (1);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_W, WIN_H, "Cub3D");
	data.walls.img = mlx_new_image(data.mlx, WIN_W, WIN_H);
	data.walls.addr = mlx_get_data_addr(data.walls.img, &data.walls.bits_per_pixel, &data.walls.line_length, &data.walls.endian);
	//print_map(&data);
	init_data(&data);
	mlx_hook(data.win, 2, (1L << 0), key_pressed, &data);
	mlx_hook(data.win, 3, (1L << 1), key_released, &data);
	mlx_hook(data.win, 17, (0L), win_close, &data);
	mlx_loop_hook(data.mlx, loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
