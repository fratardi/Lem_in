/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_update.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:32:18 by fratardi          #+#    #+#             */
/*   Updated: 2020/05/09 22:49:22 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

/*
**Get Match for Update_Map fct
*/

unsigned int	update_match(t_anthill *ant, unsigned int mid,
													unsigned int layer_level)
{
	unsigned char		mask;
	unsigned int		match;

	match = 0;
	while (match < ant->size && (mask = 0x80))
	{
		while (!ant->layer[layer_level][match / 8] && match < ant->size)
			match += 8;
		if (ant->layer[layer_level][match / 8])
		{
			while (mask)
			{
				if (mask & ant->layer[layer_level][match / 8])
					if (ant->matrice[match][mid / 8] & (0x80 >> (mid % 8)))
						return (match);
				mask >>= 1;
				match++;
			}
		}
	}
	return (0);
}

/*
**	collect a set of paths that are not colliding
*/

unsigned int	generate_flow(t_anthill *anthill,
				unsigned int collect, unsigned int collected)
{
	unsigned int	start_set;
	unsigned int	entry;
	unsigned int	size;
	unsigned int	id;

	id = 0;
	entry = 0;
	size = anthill->size;
	start_set = collected;
	ft_bzero(anthill->total_pths, size - 1);
	while (collect && entry < size)
	{
		if (entry > 0 && anthill->dfs_map[0][entry / 8] & 0x80 >> (entry % 8))
		{
			anthill->paths[collected + id][0] |= 0x80;
			if (dfs(entry, anthill, collected + id))
			{
				id++;
				collect--;
			}
		}
		entry++;
	}
	ft_sort_pths(anthill, &anthill->paths[start_set], id);
	return (get_best(anthill, id, &anthill->paths[start_set], start_set));
}

/*
**	generate all the sets of path
**	return the amount of sets generated
*/

unsigned char	**dup_matrice(t_anthill *anthill)
{
	unsigned int i;
	unsigned int reals;

	i = 0;
	anthill->skiml = 0;
	skim_layer(anthill, anthill->size - 1, anthill->layer_depth);
	ft_bzero_uctab(anthill->dfs_dup, anthill->size, anthill->real_s);
	while (i < anthill->size)
	{
		reals = 0;
		while (reals <= anthill->real_s)
		{
			anthill->dfs_dup[i][reals] = anthill->dfs_map[i][reals];
			reals++;
		}
		i++;
	}
	return (anthill->dfs_dup);
}

unsigned int	generate_flow_sets(t_anthill *anthill)
{
	unsigned int	path_to_collect;
	unsigned int	amount_of_path;
	t_formset		*form;

	amount_of_path = 0;
	path_to_collect = 1;
	if (!(form = (t_formset *)ft_memalloc(sizeof(t_formset))))
		exit(1);
	form->next = NULL;
	anthill->form = form;
	ft_bzero(anthill->update_total, anthill->real_s);
	while (ft_bfs(anthill))
	{
		update_map(anthill);
		if (!(generate_flow(anthill, path_to_collect, amount_of_path)))
		{
			free_matrice(anthill->dfs_map, anthill->size);
			anthill->dfs_map = anthill->dfs_dup;
			return (amount_of_path);
		}
		amount_of_path += path_to_collect;
		path_to_collect++;
	}
	free_matrice(anthill->dfs_dup, anthill->size);
	return (amount_of_path);
}
