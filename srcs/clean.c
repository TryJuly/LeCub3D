/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: strieste <strieste@student.42.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 10:09:13 by strieste          #+#    #+#             */
/*   Updated: 2026/02/18 10:11:48 by strieste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	clean_array(char **array)
{
	int	count;

	if (!array || !array[0])
		return ;
	count = 0;
	while (array[count] !=  0)
		free(array[count++]);
	free(array);
	return ;
}