/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:57:36 by strieste          #+#    #+#             */
/*   Updated: 2026/02/18 12:24:52 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	char	**tab;
	char	**tmp;
	// t_data	data;
	(void)tab;
	if (ac < 2)
		return (ft_putstr_fd("Missing maps argument\n", 2), 0);
	if (ac > 2)
		return (ft_putstr_fd("Too many arguments\n", 2), 0);
	if (valide_extension(av[1]))
		return (0);
	tab = exctract_file(av[1], 0, 0);
	tmp = get_map(tab);
	// tmp[0] = get_no_texture(tab);
	// tmp[1] = get_so_texture(tab);
	// tmp[2] = get_we_texture(tab);
	// tmp[3] = get_ea_texture(tab);
	// tmp[4] = 0;
	print_tab(tmp);
	// clean_array(tab);
	return (0);
}
