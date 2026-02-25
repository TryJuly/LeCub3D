/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:30:32 by strieste          #+#    #+#             */
/*   Updated: 2026/02/25 10:44:31 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	init_texture_no(t_data *data);
static int	init_texture_so(t_data *data);
static int	init_texture_we(t_data *data);
static int	init_texture_ea(t_data *data);

int	init_texture(t_data *data)
{
	int	valide;

	valide = 0;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (clean_texture_init(data), 1);
	if (init_texture_no(data))
		valide = 1;
	if (init_texture_so(data))
		valide = 1;
	if (init_texture_ea(data))
		valide = 1;
	if (init_texture_we(data))
		valide = 1;
	if (valide == 1)
		return (clean_texture_init(data), free(data->mlx), 1);
	return (0);
}

static int	init_texture_no(t_data *data)
{
	void	*ptr;
	int		width;
	int		height;

	width = WIN_W;
	height = WIN_H;
	ptr = mlx_xpm_file_to_image(data->mlx, data->image.no_texture, &width, &height);
	if (!ptr)
	{
		ft_putstr_fd("Error\nUnsupported texture : ", 2);
		ft_putendl_fd(data->image.no_texture, 2);
		return (1);
	}
	data->image.no_img.img = ptr;
	data->image.no_img.addr = mlx_get_data_addr(ptr, &data->image.no_img.bits_per_pixel,
			&data->image.no_img.line_length, &data->image.no_img.endian);
	if (!data->image.no_img.addr)
		return (1);
	return (0);
}

static int	init_texture_so(t_data *data)
{
	void	*ptr;
	int		width;
	int		height;

	width = WIN_W;
	height = WIN_H;
	ptr = mlx_xpm_file_to_image(data->mlx, data->image.so_texture, &width, &height);
	if (!ptr)
	{
		ft_putstr_fd("Error\nUnsupported texture : ", 2);
		ft_putendl_fd(data->image.so_texture, 2);
		return (1);
	}
	data->image.so_img.img = ptr;
	data->image.so_img.addr = mlx_get_data_addr(ptr, &data->image.so_img.bits_per_pixel,
			&data->image.so_img.line_length, &data->image.so_img.endian);
	if (!data->image.so_img.addr)
		return (1);
	return (0);
}

static int	init_texture_we(t_data *data)
{
	void	*ptr;
	int		width;
	int		height;

	width = WIN_W;
	height = WIN_H;
	ptr = mlx_xpm_file_to_image(data->mlx, data->image.we_texture, &width, &height);
	if (!ptr)
	{
		ft_putstr_fd("Error\nUnsupported texture : ", 2);
		ft_putendl_fd(data->image.we_texture, 2);
		return (1);
	}
	data->image.we_img.img = ptr;
	data->image.we_img.addr = mlx_get_data_addr(ptr, &data->image.we_img.bits_per_pixel,
			&data->image.we_img.line_length, &data->image.we_img.endian);
	if (!data->image.we_img.addr)
		return (1);
	return (0);
}

static int	init_texture_ea(t_data *data)
{
	void	*ptr;
	int		width;
	int		height;

	width = WIN_W;
	height = WIN_H;
	ptr = mlx_xpm_file_to_image(data->mlx, data->image.ea_texture, &width, &height);
	if (!ptr)
	{
		ft_putstr_fd("Error\nUnsupported texture : ", 2);
		ft_putendl_fd(data->image.ea_texture, 2);
		return (1);
	}
	data->image.ea_img.img = ptr;
	data->image.ea_img.addr = mlx_get_data_addr(ptr, &data->image.ea_img.bits_per_pixel,
			&data->image.ea_img.line_length, &data->image.ea_img.endian);
	if (!data->image.ea_img.addr)
		return (1);
	return (0);
}
