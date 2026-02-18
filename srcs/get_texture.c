/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:34:13 by strieste          #+#    #+#             */
/*   Updated: 2026/02/18 12:18:57 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*get_no_texture(char **out_file)
{
	int		i;
	int		count;
	char	*path_image;

	count = 0;
	while (out_file[count] != 0)
	{
		i = 0;
		while (!ft_isalpha(out_file[count][i]))
			i++;
		if (!ft_strncmp(&out_file[count][i], "NO", 2))
		{
			while (out_file[count][i] != '/' && out_file[count][i] != '.')
				i++;
			path_image = ft_strdup(&out_file[count][i]);
			if (!path_image)
				return (NULL);
			return (path_image);
		}
		count++;
	}
	return (NULL);
}

char	*get_so_texture(char **out_file)
{
	int		i;
	int		count;
	char	*path_image;

	count = 0;
	while (out_file[count] != 0)
	{
		i = 0;
		while (!ft_isalpha(out_file[count][i]))
			i++;
		if (!ft_strncmp(&out_file[count][i], "SO", 2))
		{
			while (out_file[count][i] != '/' && out_file[count][i] != '.')
				i++;
			path_image = ft_strdup(&out_file[count][i]);
			if (!path_image)
				return (NULL);
			return (path_image);
		}
		count++;
	}
	return (NULL);
}

char	*get_we_texture(char **out_file)
{
	int		i;
	int		count;
	char	*path_image;

	count = 0;
	while (out_file[count] != 0)
	{
		i = 0;
		while (!ft_isalpha(out_file[count][i]))
			i++;
		if (!ft_strncmp(&out_file[count][i], "WE", 2))
		{
			while (out_file[count][i] != '/' && out_file[count][i] != '.')
				i++;
			path_image = ft_strdup(&out_file[count][i]);
			if (!path_image)
				return (NULL);
			return (path_image);
		}
		count++;
	}
	return (NULL);
}

char	*get_ea_texture(char **out_file)
{
	int		i;
	int		count;
	char	*path_image;

	count = 0;
	while (out_file[count] != 0)
	{
		i = 0;
		while (!ft_isalpha(out_file[count][i]))
			i++;
		if (!ft_strncmp(&out_file[count][i], "EA", 2))
		{
			i = 0;
			while (out_file[count][i] != '/' && out_file[count][i] != '.')
				i++;
			path_image = ft_strdup(&out_file[count][i]);
			if (!path_image)
				return (NULL);
			return (path_image);
		}
		count++;
	}
	return (NULL);
}
