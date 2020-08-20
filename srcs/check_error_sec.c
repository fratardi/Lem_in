/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_sec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:34:49 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/12 23:05:13 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

int			is_line_second(char *str, t_room *rooms)
{
	size_t i;
	size_t digits;

	if (!str)
		return (0);
	i = 0;
	digits = 1;
	while (str[i] && str[i] != 32 && str[i] != '\n' && !ft_strchr("L#", str[i]))
		i++;
	if (str[0] != '#' && ft_strchr("L#", str[i]))
		return (0);
	else if (str[0] == '#')
		return (ft_fill_rooms(str, rooms));
	while (str[i] && str[i] != '\n')
	{
		if (str[i] == ' ')
			digits++;
		if (!ft_isdigit(str[i]) && str[i] != 32)
			return (0);
		i++;
	}
	if (digits == 3)
		return (ft_fill_rooms(str, rooms));
	return (0);
}

t_room		*stock_rse(t_lines *buf, t_room *rooms, unsigned int *se)
{
	rooms->start_end = is_instruction(buf->line);
	se[0] += (rooms->start_end == 1) ? 1 : 0;
	se[1] += (rooms->start_end == 2) ? 1 : 0;
	if (rooms->start_end == 3)
		rooms->start_end = 0;
	return (rooms);
}

t_lines		*stock_rest(t_lines *buf, t_room *rooms, unsigned int *se)
{
	if (!(rooms->next = (t_room *)ft_memalloc(sizeof(t_room))))
		exit(1);
	rooms = rooms->next;
	rooms->next = NULL;
	buf = buf->next;
	if ((rooms->start_end = is_instruction(buf->line)))
	{
		se[0] += (rooms->start_end == 1) ? 1 : 0;
		se[1] += (rooms->start_end == 2) ? 1 : 0;
		if (rooms->start_end == 3)
			rooms->start_end = 0;
		buf = buf->next;
	}
	if (rooms->start_end == 0xFF)
		return (NULL);
	return (buf);
}

t_room		*f_exit(t_room *start)
{
	free_rooms(start);
	return (NULL);
}

t_room		*check_second(t_lines *buf)
{
	t_room			*rooms;
	t_room			*start;
	unsigned int	se[2];

	if (!(rooms = (t_room *)ft_memalloc(sizeof(t_room))))
		exit(1);
	rooms->next = NULL;
	start = rooms;
	se[0] = 0;
	se[1] = 0;
	while ((is_instruction(buf->line)))
	{
		rooms = stock_rse(buf, rooms, &se[0]);
		buf = buf->next;
	}
	while (is_line_second(buf->line, rooms))
	{
		if (!(buf = stock_rest(buf, rooms, &se[0])))
			return (NULL);
		rooms = rooms->next;
	}
	if ((se[0] != 1 || se[1] != 1) || (!buf->line || (buf->line &&
				(!ft_strchr(buf->line, '#') && !ft_strchr(buf->line, '-')))))
		return (f_exit(start));
	return (start);
}
