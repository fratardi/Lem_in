/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:40:40 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/02 12:18:48 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**ignal for star is value 1  signal for end  value 2  else 0
**list of room is handled so that the first room gets
**located at the top of the list
*/

t_room	*start_first(t_room *rooms)
{
	t_room *start;
	t_room *swp;
	t_room *swp2;

	if (!rooms || rooms->start_end == 1)
		return (rooms);
	start = rooms;
	while (rooms->next && rooms->next->start_end != 1)
		rooms = rooms->next;
	if (rooms->next && rooms->next->start_end == 1)
	{
		swp = rooms->next;
		swp2 = (rooms->next->next) ? rooms->next->next : NULL;
		rooms->next = swp2;
		swp->next = start;
		return (swp);
	}
	return (start);
}

/*
**list of room is handled so that the end room
**gets located at the bottom of the list
*/

t_room	*swap_end(t_room *rooms)
{
	t_room	*swp;
	t_room	*swp2;

	if (rooms->next && rooms->next->start_end == 2)
	{
		swp = rooms->next;
		swp2 = (rooms->next->next) ? rooms->next->next : NULL;
		if (swp2)
			rooms->next = swp2;
		while (rooms->next && rooms->next->name)
			rooms = rooms->next;
		swp2 = rooms->next;
		rooms->next = swp;
		rooms->next->next = swp2;
	}
	return (rooms);
}

t_room	*end_last(t_room *rooms)
{
	t_room *start;
	t_room *swp;

	if (!rooms)
		return (rooms);
	if (rooms->start_end == 2)
	{
		swp = rooms;
		start = rooms->next;
		while (rooms->next)
			rooms = rooms->next;
		rooms->next = swp;
		return (start);
	}
	start = rooms;
	while (rooms->next && rooms->next->start_end != 2)
		rooms = rooms->next;
	rooms = swap_end(rooms);
	return (start);
}
