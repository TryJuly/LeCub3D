/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:18:40 by strieste          #+#    #+#             */
/*   Updated: 2026/02/18 13:56:04 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	get_lenght_f(char **file);
static int	get_lenght_c(char **file);

int	*get_rgb_f(char **file)
{
	int		i;
	int		*tab;
	int		count;
	char	**tmp;
	
	tab = malloc(3 * sizeof(int));
	if (!tab)
		return (NULL);
	count = get_lenght_f(file);
	i = 0;
	while (!ft_isdigit(file[count][i]))
		i++;
	tmp = ft_split(&file[count][i], ',');
	if (!tmp)
		return (free(tab), NULL);
	tab[0] = ft_atoi(tmp[0]);
	tab[1] = ft_atoi(tmp[1]);
	tab[2] = ft_atoi(tmp[2]);
	clean_array(tmp);
	return (tab);
}

static int	get_lenght_f(char **file)
{
	int	i;
	int	count;

	count = 0;
	while (file[count] != 0)
	{
		i = 0;
		while (file[count][i] && !ft_isalpha(file[count][i]))
			i++;
		if (ft_isalpha(file[count][i])
				&& !ft_strncmp(&file[count][i], "F ", 2))
			break ;
		count++;
	}
	return (count);
}

int	*get_rgb_c(char **file)
{
	int		i;
	int		*tab;
	int		count;
	char	**tmp;
	
	tab = malloc(3 * sizeof(int));
	if (!tab)
		return (NULL);
	count = get_lenght_c(file);
	i = 0;
	while (!ft_isdigit(file[count][i]))
		i++;
	tmp = ft_split(&file[count][i], ',');
	if (!tmp)
		return (free(tab), NULL);
	tab[0] = ft_atoi(tmp[0]);
	tab[1] = ft_atoi(tmp[1]);
	tab[2] = ft_atoi(tmp[2]);
	clean_array(tmp);
	return (tab);
}

static int	get_lenght_c(char **file)
{
	int	i;
	int	count;

	count = 0;
	while (file[count] != 0)
	{
		i = 0;
		while (file[count][i] && !ft_isalpha(file[count][i]))
			i++;
		if (ft_isalpha(file[count][i])
				&& !ft_strncmp(&file[count][i], "C ", 2))
			break ;
		count++;
	}
	return (count);
}
