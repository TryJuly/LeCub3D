/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 08:04:54 by strieste          #+#    #+#             */
/*   Updated: 2026/02/26 10:22:25 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	is_valide_argument(char **tab);
static int	check_double_argument(char **tab);
static int	fill_argument(char **tab, t_data *data);

int	check_before_map(char **file, t_data *data)
{
	char	**tab;

	tab = copy_file_arg(file, 0, 0);
	if (!tab)
		return (1);
	if (lenght_tab(tab) != 6)
	{
		ft_putstr_fd("Error\nArgument not found\n", 2);
		return (clean_array(tab), print_example(), 1);
	}
	if (is_valide_argument(tab))
		return (clean_array(tab), print_example(), 1);
	if (fill_argument(tab, data))
		return (clean_array(tab), 1);
	clean_array(tab);
	return (0);
}

static int	fill_argument(char **tab, t_data *data)
{
	data->image.no_texture = get_no_texture(tab);
	data->image.so_texture = get_so_texture(tab);
	data->image.ea_texture = get_ea_texture(tab);
	data->image.we_texture = get_we_texture(tab);
	if (!data->image.no_texture || !data->image.so_texture
		|| !data->image.ea_texture || !data->image.we_texture)
		return (clean_texture_init(data), 1);
	data->image.rgb_f = get_rgb_color(tab, 'f');
	data->image.rgb_c = get_rgb_color(tab, 'c');
	if (data->image.rgb_f < 0 || data->image.rgb_c < 0)
		return (clean_texture_init(data), 1);
	return (0);
}

static int	is_valide_argument(char **tab)
{
	int	count;
	int	valide;

	count = 0;
	valide = 0;
	while (tab[count] != 0)
	{
		if (is_valide_line(tab[count]))
		{
			ft_putstr_fd("Error\nNot a valide argument :\n", 2);
			ft_putendl_fd(tab[count], 2);
			valide = 1;
		}
		count++;
	}
	if (check_double_argument(tab))
		valide = 1;
	if (valide != 0)
		return (1);
	return (0);
}

char	**copy_file_arg(char **file, int len, int count)
{
	char	**tab;
	char	*tmp;

	len = index_top_map(file);
	if (len == -1)
		return (NULL);
	tab = ft_calloc(len + 2, sizeof(char *));
	if (!tab)
		return (NULL);
	count = 0;
	len--;
	while (len >= 0 && file[len])
	{
		if (!file[len] || !is_wspace_line(file[len]))
		{
			len--;
			continue ;
		}
		tmp = ft_strdup(file[len--]);
		if (!tmp)
			return (clean_array(tab), NULL);
		tab[count++] = tmp;
	}
	tab[count] = 0;
	return (tab);
}

static int	check_double_argument(char **tab)
{
	char	first;
	int		i;
	int		count;

	count = 0;
	while (tab[count] != 0 && tab[count + 1] != 0)
	{
		i = count + 1;
		first = get_identifier(tab[count]);
		while (tab[i] != 0 && is_blank(tab[i]))
		{
			if (first == get_identifier(tab[i]) && !is_valide_line(tab[i]))
			{
				ft_putstr_fd("Error\nAn other same line find : ", 2);
				ft_putendl_fd(tab[i], 2);
				return (1);
			}
			i++;
		}
		count++;
	}
	return (0);
}
