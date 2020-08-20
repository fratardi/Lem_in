/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_flows.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:08:22 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/09 22:44:41 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	function that marks the matrixes while finding the path up
**	removing from bfs map and adding back to the dfs map
*/

unsigned char	upflower(t_anthill *anthill, unsigned int matrix_index,
	unsigned int last, unsigned char mark)
{
	anthill->dfs_map[matrix_index][last / 8] |= 0x80 >> (last % 8);
	anthill->matrice[matrix_index][last / 8] -= 0x80 >> (last % 8);
	if (matrix_index != anthill->size - 1 && last != anthill->size - 1
	&& ((0xFF == ft_is_adj_up(anthill->dfs_map, matrix_index, last))))
	{
		if (mark)
			mark_room_unused(anthill->matrice[matrix_index], anthill->size);
		else
		{
			mark = 0;
			mark_room_used(anthill->matrice[matrix_index], anthill->size);
		}
		anthill->dfs_map[matrix_index][last / 8] -= 0x80 >> (last % 8);
		anthill->dfs_map[last][matrix_index / 8] -= 0x80 >> (matrix_index % 8);
		anthill->matrice[matrix_index][last / 8] |= 0x80 >> (last % 8);
		anthill->matrice[last][matrix_index / 8] |= 0x80 >> (matrix_index % 8);
	}
	else
		mark = !mark_room_used(anthill->matrice[matrix_index], anthill->size);
	return (mark);
}

/*
**	finds the index of the upflow room  room is considered already explored )
*/

unsigned int	up_flow_room_index(unsigned char **map,
	unsigned int room_index, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size - 1)
	{
		if (0xF0 == ft_is_adj_up(map, i, room_index))
			return (i);
		i++;
	}
	return (0);
}
