/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 10:31:26 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/13 06:57:30 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

/*
**Next Row
*/

t_explore		*get_next(t_explore *explore, unsigned int *f)
{
	while (explore && explore->next)
	{
		*f += 1;
		explore = explore->next;
	}
	return (explore);
}

unsigned int	next_row(t_anthill *ant, t_explore *explore, unsigned int rid)
{
	unsigned int	i;
	unsigned int	f;

	i = 0;
	f = 1;
	explore = get_next(explore, &f);
	while (i < ant->b_set.form->nb_pths)
	{
		if ((i == 0 || ant->dis.dis[(i * 2)]) && ant->dis.dis[(i * 2) + 1] > 0)
		{
			if (!(explore->next = (t_explore *)ft_memalloc(sizeof(t_explore))))
				exit(1);
			explore = explore->next;
			explore->next = NULL;
			explore->pid = i;
			explore->rid = rid;
			explore->id = f++;
			explore->last = 0;
			explore->f_st = 0;
			ant->dis.dis[(i * 2) + 1] -= 1;
		}
		i++;
	}
	return (1);
}

/*
** like putnbr but for unsigned
*/

static void		lm_print_unsigned(unsigned int nbr)
{
	if (nbr < 10)
		ft_putchar('0' + nbr);
	if (nbr % 10 < nbr)
	{
		lm_print_unsigned(nbr / 10);
		ft_putchar('0' + nbr % 10);
	}
}

/*
**Send next Row
*/

void			send_next(t_anthill *ant, t_explore *current, t_explore *expl)
{
	if (current->f_st >= (ant->size - 1))
		return ;
	while (expl && expl->next && expl->rid != current->rid - 1)
		expl = expl->next;
	while (expl && expl->next && expl->pid != current->pid)
		expl = expl->next;
	current->last = current->f_st;
	if (current->last == expl->last)
		current->f_st = expl->f_st;
	else
		current->f_st = expl->last;
	ft_putchar('L');
	lm_print_unsigned(current->id + 1);
	ft_putstr("-");
	ft_putstr(roomname_from_roomid(ant->room, current->f_st));
	ft_putchar(' ');
}
