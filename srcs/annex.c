/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 03:34:11 by tpacaud           #+#    #+#             */
/*   Updated: 2020/03/01 19:49:35 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**Get the room name from the room_id
*/

char		*roomname_from_roomid(t_room *rooms, unsigned int room_id)
{
	unsigned int i;

	i = 0;
	while (i < room_id && rooms->next)
	{
		rooms = rooms->next;
		i++;
	}
	if (i == room_id && rooms)
		return (rooms->name);
	return (NULL);
}
