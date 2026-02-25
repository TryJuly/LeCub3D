/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   announce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 08:11:07 by strieste          #+#    #+#             */
/*   Updated: 2026/02/25 08:12:40 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_arg_example(void)
{
	printf("Error\n");
	printf("Please configure the beginning of the file as follows :\n");
	printf("\nNorth texture : NO ./path_to_the_north_texture\n");
	printf("South texture : SO ./path_to_the_south_texture\n");
	printf("West texture  : WE ./path_to_the_west_texture\n");
	printf("East texture  : EA ./path_to_the_east_texture\n");
	printf("Floor color   : F 220,100,0\n");
	printf("Ceiling color : C 225,30,0\n");
	printf("\n(Info) R,G,B colors in range [0,255]: 0, 255, 255\n");
}

void	print_unclosed(void)
{
	printf("Error\n");
	printf("The map provided in the file is not enclosed by walls, ");
	printf("or the ground is missing.\n");
	printf("Please redraw the map before starting the game.\n");
	return ;
}

