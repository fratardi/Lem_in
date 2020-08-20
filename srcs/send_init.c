/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 10:40:38 by tpacaud           #+#    #+#             */
/*   Updated: 2020/04/30 12:10:13 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

t_explore		*init_first(t_anthill *anthill)
{
	t_explore		*expl;
	unsigned int	i;

	i = 0;
	if (!(expl = (t_explore *)ft_memalloc(sizeof(t_explore))))
		exit(1);
	i = 0;
	expl->id = i;
	expl->pid = i;
	expl->rid = 0;
	expl->last = 0;
	expl->f_st = 0;
	expl->next = NULL;
	anthill->dis.dis[1] -= 1;
	return (expl);
}

t_explore		*init_f(t_anthill *anthill, unsigned char **set)
{
	t_explore		*expl;
	t_explore		*start;
	unsigned int	i;

	i = 1;
	expl = init_first(anthill);
	start = expl;
	while (i < anthill->dis.nb_pths && !ft_is_room_empty(set[i], anthill->size))
	{
		if (anthill->dis.dis[(i * 2)] && anthill->dis.dis[(i * 2) + 1] > 0)
		{
			if (!(expl->next = (t_explore *)ft_memalloc(sizeof(t_explore))))
				exit(1);
			expl = expl->next;
			expl->next = NULL;
			expl->id = i;
			expl->pid = i;
			expl->rid = 0;
			expl->last = 0;
			expl->f_st = 0;
			anthill->dis.dis[(i * 2) + 1] -= 1;
		}
		i++;
	}
	return (start);
}
