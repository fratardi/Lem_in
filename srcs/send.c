/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 23:26:35 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/09 22:42:14 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**Send first ROW
**add_pos_find(unsigned int i)
*/

void			send_f(t_anthill *ant, t_explore *ex,
						unsigned int f, unsigned char *set_pid)
{
	unsigned int i;

	i = 0;
	while (i < ant->size)
	{
		if (ant->dfs_map[ex->f_st][i / 8] & 0x80 >> (i % 8) &&
				set_pid[i / 8] & 0x80 >> (i % 8))
		{
			if (!(ant->total_pths[i / 8] & 0x80 >> (i % 8)))
			{
				ant->total_pths[i / 8] |= 0x80 >> (i % 8);
				ft_printf("L%zu-%s ", f + 1,
					roomname_from_roomid(ant->room, i));
				ex->last = ex->f_st;
				ex->f_st = i;
				return ;
			}
		}
		i++;
	}
}

/*
** Main function
*/

void			send_next_line(t_anthill *anthill, t_explore *expl_s,
								t_explore *expl)
{
	while (expl && expl->next)
	{
		send_next(anthill, expl, expl_s);
		expl = expl->next;
	}
	if (expl->rid != 0)
		send_next(anthill, expl, expl_s);
	ft_printf("\n");
}

void			send_line(t_anthill *anthill, t_explore *expl_s,
							unsigned char **set)
{
	unsigned int	i;
	t_explore		*expl;

	expl = expl_s;
	i = 0;
	if (!expl)
		return ;
	ft_bzero(anthill->total_pths, anthill->size);
	send_f(anthill, expl, expl->id, set[i]);
	while (expl->next && expl->next->rid == 0)
	{
		ft_bzero(anthill->total_pths, anthill->size);
		expl = expl->next;
		send_f(anthill, expl, expl->id, set[expl->pid]);
		i++;
	}
	if (expl && expl->next)
		expl = expl->next;
	else
	{
		ft_printf("\n");
		return ;
	}
	send_next_line(anthill, expl_s, expl);
}

unsigned int	is_f_explored(t_anthill *anthill, t_explore *explore)
{
	if (!explore || explore->f_st != anthill->size - 1)
		return (0);
	while (explore->next)
	{
		if (explore->f_st != anthill->size - 1)
			return (0);
		explore = explore->next;
	}
	if (explore->f_st != anthill->size - 1)
		return (0);
	return (1);
}

void			send_ants(t_anthill *anthill)
{
	t_explore		*expl;
	unsigned int	rid;

	rid = 1;
	init_distribute(anthill);
	expl = init_f(anthill, anthill->b_set.mat_pths);
	while (!(is_f_explored(anthill, expl)))
	{
		send_line(anthill, expl, &anthill->paths[anthill->b_set.start_set]);
		next_row(anthill, expl, rid++);
	}
	free_expl(expl);
	free_distri(anthill);
}
