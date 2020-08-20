/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_room_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:50:04 by fratardi          #+#    #+#             */
/*   Updated: 2020/04/30 15:47:16 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	checks if room is linked to start
*/

inline unsigned char	is_room_linked_to_start(unsigned char *lign)
{
	return (*lign >> 7);
}

/*
**	checks if room is linked to end
*/

inline unsigned char	is_room_linked_to_end(unsigned char *lign,
		unsigned int size)
{
	return (((lign[(size - 1) / 8]) & 0x80 >> ((size - 1) % 8)));
}

inline unsigned char	is_room_used(unsigned char *room, unsigned int size)
{
	return (room[(size / 8) + 1]);
}

/*
**  1 if room is empty 0 if not
*/

unsigned char			ft_is_room_empty(unsigned char *room, unsigned int size)
{
	unsigned int pos;

	pos = 0;
	while (pos < size)
	{
		if (room[pos / 8])
			return (0);
		pos += 8;
	}
	return (1);
}
