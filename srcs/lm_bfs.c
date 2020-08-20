/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 15:51:03 by fratardi          #+#    #+#             */
/*   Updated: 2020/05/09 22:48:46 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	find from layer level the matching room id to matrix line
*/

unsigned int	ft_get_match(t_anthill *ant, unsigned int mid,
													unsigned int layer_level)
{
	unsigned char		mask;
	unsigned int		match;

	match = 0;
	while (match < ant->size && (mask = 0x80))
	{
		while (!ant->layer[layer_level][match / 8] && match < ant->size)
			match += 8;
		if (ant->layer[layer_level][match / 8])
		{
			while (mask)
			{
				if (mask & ant->layer[layer_level][match / 8])
					if (ant->matrice[match][mid / 8] & (0x80 >> (mid % 8)))
					{
						if (!is_room_used(ant->matrice[match], ant->size)
							|| c_column(ant->dfs_map, mid, ant->size) == 1)
							return (match);
					}
				mask >>= 1;
				match++;
			}
		}
	}
	return (0);
}

/*
**	Write out of the bfs matrix the upflow and gets it into the dfs_map
*/

unsigned int	update_map(t_anthill *anthill)
{
	unsigned int	last;
	unsigned int	matrix_index;
	unsigned int	layer_level;
	unsigned char	mark;

	mark = 0;
	matrix_index = anthill->size - 1;
	last = matrix_index;
	layer_level = anthill->layer_depth;
	dup_matrice(anthill);
	while ((matrix_index = update_match(anthill, matrix_index, layer_level)))
	{
		if (is_room_used(anthill->matrice[matrix_index], anthill->size))
			matrix_index = update_match(anthill, last, layer_level);
		anthill->update_total[matrix_index / 8] |= 0x80 >> (matrix_index % 8);
		mark = upflower(anthill, matrix_index, last, mark);
		last = matrix_index;
		layer_level--;
	}
	anthill->dfs_map[matrix_index][last / 8] |= 0x80 >> (last % 8);
	anthill->matrice[matrix_index][last / 8] -= 0x80 >> (last % 8);
	ft_bzero_uctab(anthill->layer, anthill->size, anthill->real_s);
	anthill->layer_depth = 0;
	return (1);
}

/*
**		next layer must contain only the rooms that are refered inside the
**														(room to explore)
**		and must not be in total already
**		using this method if it already in next layer (|)
*/

void			apply_layer(unsigned char *next_layer,
	unsigned int index, t_anthill *anthill)
{
	unsigned int pos;
	unsigned int size;

	pos = 0;
	size = anthill->size;
	while (pos < size)
	{
		next_layer[pos / 8] |=
			(anthill->bfs_total[pos / 8]
			& anthill->matrice[index][pos / 8])
			^ (anthill->matrice[index][pos / 8]);
		pos += 8;
	}
}

/*
**	gives a room giving from the current layer to explore
**	all the rooms that were not exlored from the current room given
*/

void			explore_layer_level(t_anthill *data, unsigned int y,
									unsigned int pos)
{
	while (pos < (data->size - 1))
	{
		if (((0x80 >> (pos % 8)) & (data->layer[y][pos / 8])))
		{
			if (!(((0x80 >> (pos % 8)) & (data->layer[y][pos / 8])) &
				data->bfs_total[pos / 8]))
			{
				data->bfs_total[pos / 8] |= (0x80 >> (pos % 8));
				if (y != 0 && is_room_used(data->matrice[pos], data->size)
					&& !is_room_used(data->matrice[ft_get_match(data,
						pos, y - 1)], data->size))
				{
					data->layer[y + 1][up_flow_room_index(data->matrice,
						pos, data->size) / 8] |=
						(0x80 >> (up_flow_room_index(data->matrice,
							pos, data->size) % 8));
				}
				else
					apply_layer(data->layer[y + 1], pos, data);
			}
		}
		pos++;
	}
}

unsigned int	ft_bfs(t_anthill *anthill)
{
	unsigned int depth;

	depth = 0;
	anthill->layer[depth][0] |= 0x80;
	while (anthill->layer[depth]
	&& !ft_is_room_empty(anthill->layer[depth], anthill->size)
	&& !is_room_linked_to_end(anthill->layer[depth], anthill->size))
	{
		explore_layer_level(anthill, depth, 0);
		depth++;
	}
	ft_bzero(anthill->bfs_total, anthill->real_s + 1);
	anthill->layer_depth = (depth > 0) ? (depth - 1) : 0;
	if (!is_room_linked_to_end(anthill->layer[depth], anthill->size)
		|| ft_is_room_empty(anthill->layer[depth], anthill->size))
		return (anthill->layer_depth = 0);
	return (1);
}
