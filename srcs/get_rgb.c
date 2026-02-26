/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:18:40 by strieste          #+#    #+#             */
/*   Updated: 2026/02/26 13:12:26 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	**tab_rgb_color(char **file, int index);
static int	valide_rgb(char **tab);

int	*get_rgb_f(char **file)
{
	int		*tab;
	char	**tmp;

	tmp = tab_rgb_color(file, get_index_f(file));
	if (!tmp)
		return (NULL);
	if (lenght_tab(tmp) != 3)
		return (clean_array_null(&tmp), NULL);
	tab = malloc(3 * sizeof(int));
	if (!tab)
		return (clean_array(tmp), NULL);
	if (valide_rgb(tmp))
		return (clean_array(tmp), free(tab), NULL);
	tab[0] = ft_atoi(tmp[0]);
	tab[1] = ft_atoi(tmp[1]);
	tab[2] = ft_atoi(tmp[2]);
	if (tab[0] < 0 || tab[1] < 0 || tab[2] < 0)
		return (clean_array(tmp), free(tab), NULL);
	if (tab[0] > 255 || tab[1] > 255 || tab[2] > 255)
		return (clean_array(tmp), free(tab), NULL);
	clean_array(tmp);
	return (tab);
}

int	*get_rgb_c(char **file)
{
	int		*tab;
	char	**tmp;

	tmp = tab_rgb_color(file, get_index_c(file));
	if (!tmp)
		return (NULL);
	if (lenght_tab(tmp) != 3)
		return (clean_array_null(&tmp), NULL);
	tab = malloc(3 * sizeof(int));
	if (!tab)
		return (clean_array(tmp), NULL);
	if (valide_rgb(tmp))
		return (clean_array(tmp), free(tab), NULL);
	tab[0] = ft_atoi(tmp[0]);
	tab[1] = ft_atoi(tmp[1]);
	tab[2] = ft_atoi(tmp[2]);
	if (tab[0] < 0 || tab[1] < 0 || tab[2] < 0)
		return (clean_array(tmp), free(tab), NULL);
	if (tab[0] > 255 || tab[1] > 255 || tab[2] > 255)
		return (clean_array(tmp), free(tab), NULL);
	clean_array(tmp);
	return (tab);
}

static int	valide_rgb(char **tab)
{
	int	count;
	int	i;

	i = 0;
	while (tab[i])
	{
		count = 0;
		while (tab[i][count])
		{
			if ((tab[i][count] < '0' || tab[i][count] > '9')
				&& (tab[i][count] != ' ' && tab[i][count] != ','
				&& tab[i][count] != '\t'))
				return (1);
			count++;
		}
		i++;
	}
	return (0);
}

static char	**tab_rgb_color(char **file, int index)
{
	char	**tab;
	int		count;

	count = 0;
	if (index < 0)
		return (NULL);
	while (file[index][count] && !ft_isdigit(file[index][count]))
		count++;
	if (!file[index][count])
		return (NULL);
	tab = ft_split(&file[index][count], ',');
	if (!tab)
		return (NULL);
	if (lenght_tab(tab) > 3)
		return (clean_array(tab), NULL);
	return (tab);
}
