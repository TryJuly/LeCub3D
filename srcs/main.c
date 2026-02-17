/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:57:36 by strieste          #+#    #+#             */
/*   Updated: 2026/02/17 15:37:00 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	char	**tab;
	if (ac < 2)
		return (ft_putstr_fd("Missing maps argument\n", 2), 0);
	if (ac > 2)
		return (ft_putstr_fd("Too many arguments\n", 2), 0);
	if (valide_extension(av[1]))
		return (0);
	tab = exctract_file(av[1]);
	print_tab(tab);
	return (0);
}
