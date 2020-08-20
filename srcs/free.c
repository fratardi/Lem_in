/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 17:17:43 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/04 17:23:54 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

unsigned char		free_buf(t_lines *buf)
{
	t_lines *lfree;

	while (buf && buf->next)
	{
		lfree = buf;
		buf = buf->next;
		free(lfree->line);
		free(lfree);
		lfree = NULL;
	}
	if (buf)
		free(buf);
	return (0);
}

void				free_expl(t_explore *tofree)
{
	t_explore *expl_f;

	while (tofree && tofree->next)
	{
		expl_f = tofree;
		tofree = tofree->next;
		free(expl_f);
		expl_f = NULL;
	}
	if (tofree)
		free(tofree);
	return ;
}

void				free_distri(t_anthill *anthill)
{
	free(anthill->dis.dis);
}
