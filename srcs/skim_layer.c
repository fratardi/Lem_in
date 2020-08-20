/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skim_layer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 22:04:12 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/09 22:29:08 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

unsigned int	match(unsigned char *next, unsigned int last,
							unsigned char **mat, unsigned int size)
{
	unsigned int i;
	unsigned int used;

	i = 0;
	used = 0;
	while (i < size)
	{
		if ((next[i / 8] & (0x80 >> (i % 8))) &&
					(mat[i][last / 8] & (0x80 >> (last % 8))))
		{
			if (i > 0 && is_room_used(mat[i], size))
				used = i;
			else
				return (i);
		}
		i++;
	}
	if (used > 0)
		return (used);
	return (0xFFFFFFFF);
}

unsigned int	hm_match(unsigned char *next, unsigned int last,
						t_anthill *anthill)
{
	unsigned int i;
	unsigned int count;

	count = 0;
	i = 0;
	while (i < anthill->size)
	{
		if ((next[i / 8] & (0x80 >> (i % 8))) &&
					(anthill->matrice[i][last / 8] & (0x80 >> (last % 8))))
			count++;
		i++;
	}
	return (count);
}

unsigned int	by_line(unsigned char *layer_line, unsigned int size)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		if (layer_line[i] & 0x80 >> (i % 8))
			count++;
		i++;
	}
	return (count);
}

void			skim_layer(t_anthill *ant, unsigned int last,
					unsigned int curr_line)
{
	unsigned int curr;

	curr = 0xFFFFFFFF;
	if (last > 0)
		curr = match(ant->layer[curr_line], last, ant->matrice, ant->size);
	if (!ant->skiml && curr != 0XFFFFFFFF)
		skim_layer(ant, curr, curr_line - 1);
	if (last == 0)
		ant->skiml = 1;
	if (!ant->skiml && curr != 0XFFFFFFFF &&
			hm_match(ant->layer[curr_line], last, ant))
	{
		ant->layer[curr_line][curr / 8] -= 0x80 >> (curr % 8);
		skim_layer(ant, last, curr_line);
	}
}
