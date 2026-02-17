/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 11:40:51 by strieste          #+#    #+#             */
/*   Updated: 2026/02/17 11:43:39 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*fill_stock(int fd, char *stock);
static char		*clean_stock(char *stock);
static char		*extract_line(char *stock);
static size_t	newline(char *stock);

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*final_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = fill_stock(fd, stock);
	if (!stock)
		return (NULL);
	final_line = extract_line(stock);
	stock = clean_stock(stock);
	if (!final_line && stock)
	{
		free(stock);
		return (NULL);
	}
	return (final_line);
}

static char	*fill_stock(int fd, char *stock)
{
	char	*buff;
	char	*temp;
	ssize_t	bytes_read;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !newline(stock))
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buff);
			free(stock);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		temp = ft_strjoin(stock, buff);
		free(stock);
		stock = temp;
	}
	free(buff);
	return (stock);
}

static char	*extract_line(char *stock)
{
	char	*line;
	size_t	count;

	if (!stock || !*stock)
		return (NULL);
	count = 0;
	while (stock[count] && stock[count] != '\n')
		count++;
	if (stock[count] == '\n')
		count++;
	line = ft_substr(stock, 0, count);
	return (line);
}

static char	*clean_stock(char *stock)
{
	char	*stock_clean;
	size_t	count;

	if (!stock)
		return (NULL);
	count = 0;
	while (stock[count] && stock[count] != '\n')
		count++;
	if (!stock[count])
	{
		free(stock);
		return (NULL);
	}
	count++;
	stock_clean = ft_substr(stock, count, ft_strlen(stock) - count);
	free(stock);
	if (stock_clean && *stock_clean == '\0')
	{
		free(stock_clean);
		return (NULL);
	}
	return (stock_clean);
}

static size_t	newline(char *stock)
{
	size_t	count;

	if (!stock)
		return (0);
	count = 0;
	while (stock[count])
	{
		if (stock[count] == '\n')
			return (1);
		count++;
	}
	return (0);
}
