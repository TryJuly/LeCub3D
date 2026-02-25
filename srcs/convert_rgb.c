/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 09:56:05 by strieste          #+#    #+#             */
/*   Updated: 2026/02/24 10:21:01 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*get_hex(int nb);
static char	*add_prefix(char *str);
static char	*sticky_function(char *red, char *green, char *blue);

char	*get_hex_color(int red, int green, int blue)
{
	char	*r;
	char	*g;
	char	*b;
	char	*res;

	r = get_hex(red);
	if (!r)
		return (NULL);
	g = get_hex(green);
	if (!g)
		return (free(r), NULL);
	b = get_hex(blue);
	if (!b)
		return (free(r), free(g), NULL);
	res = sticky_function(r, g, b);	
	free(r);
	free(g);
	free(b);
	if (!res)
		return (NULL);
	r = add_prefix(res);
	free(res);
	if (!r)
		return (NULL);
	return (r);
}

static char	*sticky_function(char *red, char *green, char *blue)
{
	char	*tmp;
	char	*res;
	
	if (!red || !green || !blue)
		return (NULL);
	tmp = ft_strjoin(red, green);
	if (!tmp)
		return (NULL);
	res = ft_strjoin(tmp, blue);
	free(tmp);
	if (!res)
		return (NULL);
	return (res);
}

static char	*add_prefix(char *str)
{
	char	*res;
	char	*tmp;

	tmp = ft_strdup("0x");
	if (!tmp)
		return (NULL);
	res = ft_strjoin(tmp, str);
	free(tmp);
	if (!res)
		return  (NULL);
	return (res);
}


static char	*get_hex(int nb)
{
	char	*result;
	int		count;
	char	*base;

	if (nb == 0)
		return (ft_strdup("00"));
	base = "0123456789ABCDEF";
	result = ft_calloc(3, sizeof(char));
	if (!result)
		return (NULL);
	result[2] = '\0';
	count = 1;
	while (nb > 0)
	{
		result[count] = base[nb % 16];
		count--;
		nb = nb / 16;
	}
	return (result);
}
