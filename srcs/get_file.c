/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:05:32 by strieste          #+#    #+#             */
/*   Updated: 2026/02/25 15:20:22 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	length_file(char *filename, int fd);

char	**exctract_file(char *filename, char *tmp, int count)
{
	int		fd;
	char	**out_file;
	int		len;

	count = 0;
	len = length_file(filename, 0);
	out_file = ft_calloc(len + 1, sizeof(char *));
	if (!out_file)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (printf("Error\nfile : %s\n", filename), free(out_file), NULL);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		tmp[ft_strlen(tmp) - 1] = '\0';
		out_file[count++] = tmp;
	}
	out_file[count] = 0;
	return (close(fd), out_file);
}

// char	*propper(char *str)
// {
// 	char	*tmp;

// 	tmp = ft_strtrim(str, "\n\r")
// }

void	print_tab(char **tab)
{
	int	count;

	count = 0;
	while (tab[count] != 0)
		printf("%s\n", tab[count++]);
	return ;
}

// char	**clean_extract(char *filename)
// {
// 	int		count;
// 	char	**file;
// 	char	*tmp;
	
// 	file = exctract_file(filename, 0, 0);
// 	if (!file)
// 		return (NULL);
// 	count = 0;
// 	while (file[count] != 0)
// 	{
// 		tmp = ft_strtrim(file[count], "\n");
// 		if (!tmp)
// 			return (clean_array(file), NULL);
// 		free(file[count]);
// 		file[count] = tmp;
// 		count++;
// 	}
// 	return (file);
// }

// static char	**exctract_file(char *filename, char *tmp, int count)
// {
// 	int		fd;
// 	char	**out_file;
// 	int		len;

// 	count = 0;
// 	len = length_file(filename);
// 	out_file = ft_calloc(len + 1, sizeof(char *));
// 	if (!out_file)
// 		return (NULL);
// 	fd = open(filename, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error\n Can't open file : %s\n", filename);
// 		return (free(out_file), NULL);
// 	}
// 	tmp = get_next_line(fd);
// 	if (!tmp)
// 		return (free(out_file), close(fd), NULL);
// 	out_file[count++] = tmp;
// 	while (tmp)
// 	{
// 		tmp = get_next_line(fd);
// 		if (!tmp)
// 			break ;
// 		out_file[count++] = tmp;
// 	}
// 	out_file[count] = 0;
// 	return (close(fd), out_file);
// }

//	Need to free if open fail
static int	length_file(char *filename, int fd)
{
	int		count;
	char	*file;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCan't open file : %s\n", filename);
		return (exit(1), -1);
	}
	while (1)
	{
		file = get_next_line(fd);
		if (!file)
			break ;
		count++;
		free(file);
	}
	close(fd);
	if (count <= 0)
	{
		printf("Error\nEmpty file\n : %s\n", filename);
		return (exit(1), -1);
	}
	return (count);
}
