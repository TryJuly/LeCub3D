/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:05:32 by strieste          #+#    #+#             */
/*   Updated: 2026/02/17 15:40:10 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	length_file(char *filename);

// int	parsing(char *filename)
// {
	
// }

void	print_tab(char **tab)
{
	int	count;

	count = 0;
	while (tab[count] != 0)
		printf("%s", tab[count++]);
	return ;
}

char	**exctract_file(char *filename)
{
	int		fd;
	int		count;
	char	*tmp;
	char	**out_file;

	count = 0;
	out_file = malloc((length_file(filename) + 1) * sizeof(char *));
	if (!out_file)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error open fd\n", 2), free(out_file), NULL);
	tmp = get_next_line(fd);
	if (!tmp)
		return (free(out_file), NULL);
	out_file[count++] = tmp; 
	while (tmp)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		out_file[count++] = tmp;
	}
	out_file[count] = 0;
	return (out_file);
}

static int	length_file(char *filename)
{
	int		count;
	int		fd;
	char	*file;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error open fd\n", 2), exit(1), -1);
	file = get_next_line(fd);
	while (file)
	{
		free(file);
		file = get_next_line(fd);
		count++;
	}
	return (count);
}
