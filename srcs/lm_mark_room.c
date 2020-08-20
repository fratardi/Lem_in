/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_mark_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 15:43:22 by fratardi          #+#    #+#             */
/*   Updated: 2020/05/04 13:49:10 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

inline	unsigned char	mark_room_unused(unsigned char *room, unsigned int size)
{
	return (0x01 | (room[(size / 8) + 1] = 0x00));
}

inline	unsigned char	mark_room_used(unsigned char *room, unsigned int size)
{
	return (room[(size / 8) + 1] |= 0x01);
}

/*
**	write on an allocated matrix the infos about the rooms
*/

void					fill_bool_map(unsigned char **map, char *l1, char *l2,
	t_room *room)
{
	int i;
	int i_l1;
	int i_l2;

	i = 0;
	i_l1 = 0;
	i_l2 = 0;
	while (room->next && room->name)
	{
		if (!ft_strcmp(room->name, l1))
			i_l1 = i;
		if (!ft_strcmp(room->name, l2))
			i_l2 = i;
		room = room->next;
		i++;
	}
	map[i_l1][(i_l2 / 8)] |= 0x80 >> (i_l2 % 8);
	map[i_l2][(i_l1 / 8)] |= 0x80 >> (i_l1 % 8);
	free(l1);
	free(l2);
}
