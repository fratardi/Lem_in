/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 23:22:40 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/12 23:53:42 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void	print_rooms(t_room *rooms)
{
	unsigned int room_id;

	room_id = 0;
	ft_printf("##### ROOMS_DEFINITIONS #####\n");
	while (rooms->next)
	{
		ft_printf(">> Room_Name {%s}", rooms->name);
		ft_printf("Room_id{%zu} _x {%zu} _y {%zu}",
			room_id, rooms->x, rooms->y);
		ft_printf("is_start {%d} is_end {%d}\n",
			((rooms->start_end == 1) ? 1 : 0),
			((rooms->start_end == 2) ? 1 : 0));
		rooms = rooms->next;
		room_id++;
	}
	ft_printf("##### _________________ #####\n");
}

char	*room_name(char *str)
{
	char	*ret;
	size_t	i;

	i = 0;
	while (str[i] && str[i] != 32)
		i++;
	if (!(ret = (char *)ft_memalloc(sizeof(char) * (i + 1))))
		exit(1);
	i = 0;
	while (str[i] && str[i] != 32)
	{
		ret[i] = str[i];
		i++;
	}
	return (ret);
}

int		ft_fill_rooms(char *str, t_room *rooms)
{
	size_t i;

	i = 0;
	if (!(rooms->name = room_name(str)))
		return (0);
	while (str[i] && str[i] != 32)
		i++;
	while (str[i] && str[i] == 32)
		i++;
	rooms->x = ft_atoi(&str[i]);
	while (str[i] && str[i] != 32)
		i++;
	while (str[i] && str[i] == 32)
		i++;
	rooms->y = ft_atoi(&str[i]);
	return (1);
}
