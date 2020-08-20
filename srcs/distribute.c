/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distribute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:02:46 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/03 14:03:23 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

/*
**Print distribution
*/

void			print_distribution(t_anthill *anthill)
{
	unsigned int	i;
	t_distrubute	distrib;

	ft_printf("\n\nDistribution des fourmis dans chacun des paths :\n");
	ft_printf("__Pid__ __How many ants for this path__\n");
	distrib = anthill->dis;
	i = 0;
	while (i < distrib.len)
	{
		ft_printf("__%zu__   ", distrib.dis[i++]);
		if (!(i % 2))
			ft_printf("\n");
	}
	ft_printf("\n");
}

/*
**Distribute ants to paths
*/

void			extra_distribute(t_anthill *anthill)
{
	t_distrubute distrib;
	unsigned int i;

	distrib = anthill->dis;
	while (distrib.nb_f_all)
	{
		i = 1;
		while (distrib.nb_f_all && i < distrib.len)
		{
			distrib.dis[i] += 1;
			distrib.nb_f_all--;
			i += 2;
		}
	}
}

unsigned int	get_max(t_anthill *anthill)
{
	unsigned int pid;
	unsigned int i;
	unsigned int max_all;

	pid = 0;
	i = 1;
	max_all = 0;
	while (pid < anthill->dis.nb_pths)
	{
		anthill->dis.dis[i] = anthill->b_set.form->longest - (current_len_path(
						anthill->b_set.mat_pths[pid], anthill->real_s) - 1);
		max_all += anthill->dis.dis[i];
		i += 2;
		pid++;
	}
	return (max_all);
}

unsigned int	init_distribute(t_anthill *anthill)
{
	unsigned int pid;
	unsigned int i;
	unsigned int max_all;

	pid = 0;
	i = 0;
	max_all = 0;
	anthill->dis.len = anthill->b_set.form->nb_pths * 2;
	anthill->dis.nb_pths = anthill->b_set.form->nb_pths;
	if (!(anthill->dis.dis = (unsigned int *)ft_memalloc(sizeof(unsigned int) *
					(anthill->dis.len + 10))))
		exit(1);
	while (i < anthill->dis.len && pid < anthill->dis.nb_pths)
	{
		anthill->dis.dis[i] = pid;
		pid++;
		i += 2;
	}
	max_all = get_max(anthill);
	anthill->dis.dis[anthill->dis.len + 1] = 0;
	anthill->dis.nb_f_all =
		(max_all < anthill->ants) ? anthill->ants - max_all : 0;
	extra_distribute(anthill);
	return (1);
}
