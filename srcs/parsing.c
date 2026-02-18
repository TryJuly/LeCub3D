/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:05:32 by strieste          #+#    #+#             */
/*   Updated: 2026/02/18 14:24:59 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	length_file(char *filename);
static char	**exctract_file(char *filename, char *tmp, int count);

// int	is_valide_file(char **file)
// {
// 	int	count;

// 	count = 0;
// 	while (file[count] != 0)
// 	{
		
// 	}
// }

// int	parsing(char *filename)
// {
// 	char	**out_file;
	
// 	out_file = exctract_file(filename, 0, 0);
// 	if (!out_file)
// 		return (-1);
// }

void	print_tab(char **tab)
{
	int	count;

	count = 0;
	while (tab[count] != 0)
		printf("%s\n", tab[count++]);
	return ;
}

char	**clean_extract(char *filename)
{
	int		count;
	char	**file;
	char	*tmp;
	
	file = exctract_file(filename, 0, 0);
	if (!file)
		return (NULL);
	count = 0;
	while (file[count] != 0)
	{
		tmp = ft_strtrim(file[count], "\n");
		if (!tmp)
			return (clean_array(file), NULL);
		free(file[count]);
		file[count] = tmp;
		count++;
	}
	return (file);
}

static char	**exctract_file(char *filename, char *tmp, int count)
{
	int		fd;
	char	**out_file;

	count = 0;
	out_file = malloc((length_file(filename) + 1) * sizeof(char *));
	if (!out_file)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nCan't open file\n", 2);
		return (free(out_file), NULL);
	}
	tmp = get_next_line(fd);
	if (!tmp)
		return (free(out_file), close(fd), NULL);
	out_file[count++] = tmp; 
	while (tmp)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		out_file[count++] = tmp;
	}
	return (out_file[count] = 0, close(fd), out_file);
}

//	Need to free if open fail
static int	length_file(char *filename)
{
	int		count;
	int		fd;
	char	*file;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nCan't open file\n", 2), exit(1), -1);
	file = get_next_line(fd);
	while (file)
	{
		free(file);
		file = get_next_line(fd);
		count++;
	}
	close(fd);
	if (count <= 0)
		return (ft_putstr_fd("Error\nEmpty file\n", 2), exit(1), -1);
	return (count);
}
