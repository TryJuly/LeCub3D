/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   announce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 08:11:07 by strieste          #+#    #+#             */
/*   Updated: 2026/02/25 15:24:59 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// void	print_arg_example(void)
// {
// 	printf("Error\n");
// 	printf("Please configure the beginning of the file as follows :\n");
// 	printf("\nNorth texture : NO ./path_to_the_north_texture\n");
// 	printf("South texture : SO ./path_to_the_south_texture\n");
// 	printf("West texture  : WE ./path_to_the_west_texture\n");
// 	printf("East texture  : EA ./path_to_the_east_texture\n");
// 	printf("Floor color   : F 220,100,0\n");
// 	printf("Ceiling color : C 225,30,0\n");
// 	printf("\n(Info) R,G,B colors in range [0,255]: 0, 255, 255\n");
// }

void	print_unclosed(void)
{
	printf("Error\n");
	printf("The map provided in the file is not enclosed by walls, ");
	printf("or the ground is missing.\n");
	printf("Please redraw the map before starting the game.\n");
	return ;
}

void	print_example(void)
{
	printf("Error\n");
	printf("Please configure the file as follows :\n");
	printf("\nNO ./path_to_the_north_texture\n");
	printf("SO ./path_to_the_south_texture\n");
	printf("WE ./path_to_the_west_texture\n");
	printf("EA ./path_to_the_east_texture\n");
	printf("\n");
	printf("Floor color   : F 220,100,0\n");
	printf("Ceiling color : C 225,30,0\n");
	printf("\n(Info) R,G,B colors in range [0,255]: 0, 255, 255\n");
	printf("\n");
	printf("The map must be composed of only 6 possible characters:\n");
	printf("0 for an empty space, 1 for a wall, and N,S,E or W for the player "); 
	printf("start position and spawning orientation.\n");
	printf("\n");
	printf("The map must be closed/surrounded by walls\n");
	printf("\n");
	printf("Exemple: \n111111\n100101\n101001\n1100N1\n111111\n");
	printf("\nGood game !\n");
}
