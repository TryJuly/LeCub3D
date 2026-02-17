/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbezenco <cbezenco@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 14:19:46 by cbezenco          #+#    #+#             */
/*   Updated: 2025/10/07 14:51:26 by cbezenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	if (n == 0)
		return (0);
	if (!s1 || !*s1)
		return (1);
	if (!s2 || !*s2)
		return (1);
	n--;
	count = 0;
	while ((s1[count] || s2[count]) && (s1[count] == s2[count]) && count < n)
		count++;
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
