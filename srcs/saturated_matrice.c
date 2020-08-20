/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saturated_matrice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 19:49:18 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/05 21:33:18 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

/*
**	Malloc matrice and fill 0
*/

unsigned char	**ft_malloc_matrice(unsigned int map_size, unsigned int reals)
{
	unsigned char	**new_matrice;
	unsigned int	i;

	i = 0;
	if (!(new_matrice = (unsigned char **)ft_memalloc(sizeof(unsigned char *) *
			(map_size + 1))))
		exit(1);
	while (i < map_size)
	{
		if (!(new_matrice[i] = (unsigned char *)ft_memalloc(
				sizeof(unsigned char *) * reals + 1)))
			exit(1);
		i++;
	}
	return (new_matrice);
}
