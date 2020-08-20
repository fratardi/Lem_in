/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_annex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 10:32:19 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/13 06:56:03 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_sort_pths(t_anthill *ant, unsigned char **p, unsigned int ss)
{
	unsigned int	i;
	unsigned int	y;
	unsigned int	i_pths;
	unsigned char	*swp;

	i = 0;
	i_pths = 0;
	while (i_pths < ss && !ft_is_room_empty(p[i_pths], ant->size))
		i_pths++;
	while (i < i_pths - 1)
	{
		y = 0;
		while (y + 1 < i_pths)
		{
			if (current_len_path(p[y], ant->real_s) >
					current_len_path(p[y + 1], ant->real_s))
			{
				swp = p[y + 1];
				p[y + 1] = p[y];
				p[y] = swp;
			}
			y++;
		}
		i++;
	}
}

/*
**Print the explore list
*/

void			print_explore(t_explore *explore)
{
	while (explore && explore->next)
	{
		ft_printf("|f%zu|pid%zu|rid%zu|lst%zu|f_st%zu|\n",
			explore->id, explore->pid, explore->rid,
			explore->last, explore->f_st);
		explore = explore->next;
	}
	ft_printf("|f%zu|pid%zu|rid%zu|lst%zu|f_st%zu|\n",
		explore->id, explore->pid, explore->rid,
		explore->last, explore->f_st);
	ft_printf("\n\n");
}

unsigned int	current_len_path(unsigned char *c_layer, unsigned int real_s)
{
	unsigned int i;
	unsigned int j;
	unsigned int y;

	i = 0;
	j = 0;
	y = 0;
	while (i < real_s)
	{
		j = 0;
		while (j < 8)
		{
			if (c_layer[i] & (0x80 >> j))
				y++;
			j++;
		}
		i++;
	}
	return (y);
}
