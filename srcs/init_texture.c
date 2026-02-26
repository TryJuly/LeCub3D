/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:30:32 by strieste          #+#    #+#             */
/*   Updated: 2026/02/26 10:36:35 by strieste         ###   ########.fr       */
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
	{
		free_error_texture(data);
		clean_array_null(&data->map);
		mlx_destroy_display(data->mlx);
		return (clean_texture_init(data), free(data->mlx), 1);
	}
	return (0);
}

static int	init_texture_no(t_data *data)
{
	void		*ptr;
	char		*img_p;
	t_img		*ptr_t;

	img_p = data->image.no_texture;
	ptr_t = &data->image.no_img;
	ptr = mlx_xpm_file_to_image(data->mlx, img_p, &data->size, &data->size);
	if (!ptr)
	{
		ft_putstr_fd("Error\nUnsupported texture : ", 2);
		ft_putendl_fd(data->image.no_texture, 2);
		data->image.no_img.img = NULL;
		return (1);
	}
	data->image.no_img.img = ptr;
	data->image.no_img.addr = mlx_get_data_addr(ptr, &ptr_t->bits_per_pixel,
			&ptr_t->line_length, &ptr_t->endian);
	if (!data->image.no_img.addr)
		return (1);
	return (0);
}

static int	init_texture_so(t_data *data)
{
	void	*ptr;
	char	*img_p;
	t_img	*ptr_t;

	img_p = data->image.so_texture;
	ptr_t = &data->image.so_img;
	ptr = mlx_xpm_file_to_image(data->mlx, img_p, &data->size, &data->size);
	if (!ptr)
	{
		ft_putstr_fd("Error\nUnsupported texture : ", 2);
		ft_putendl_fd(data->image.so_texture, 2);
		data->image.so_img.img = NULL;
		return (1);
	}
	data->image.so_img.img = ptr;
	data->image.so_img.addr = mlx_get_data_addr(ptr, &ptr_t->bits_per_pixel,
			&ptr_t->line_length, &ptr_t->endian);
	if (!data->image.so_img.addr)
		return (1);
	return (0);
}

static int	init_texture_we(t_data *data)
{
	void	*ptr;
	char	*img_p;
	t_img	*ptr_t;

	img_p = data->image.we_texture;
	ptr_t = &data->image.we_img;
	ptr = mlx_xpm_file_to_image(data->mlx, img_p, &data->size, &data->size);
	if (!ptr)
	{
		ft_putstr_fd("Error\nUnsupported texture : ", 2);
		ft_putendl_fd(data->image.we_texture, 2);
		data->image.we_img.img = NULL;
		return (1);
	}
	data->image.we_img.img = ptr;
	data->image.we_img.addr = mlx_get_data_addr(ptr, &ptr_t->bits_per_pixel,
			&ptr_t->line_length, &ptr_t->endian);
	if (!data->image.we_img.addr)
		return (1);
	return (0);
}

static int	init_texture_ea(t_data *data)
{
	void	*ptr;
	char	*img_p;
	t_img	*ptr_t;

	img_p = data->image.ea_texture;
	ptr_t = &data->image.ea_img;
	ptr = mlx_xpm_file_to_image(data->mlx, img_p, &data->size, &data->size);
	if (!ptr)
	{
		ft_putstr_fd("Error\nUnsupported texture : ", 2);
		ft_putendl_fd(data->image.ea_texture, 2);
		data->image.ea_img.img = NULL;
		return (1);
	}
	data->image.ea_img.img = ptr;
	data->image.ea_img.addr = mlx_get_data_addr(ptr, &ptr_t->bits_per_pixel,
			&ptr_t->line_length, &ptr_t->endian);
	if (!data->image.ea_img.addr)
		return (1);
	return (0);
}
