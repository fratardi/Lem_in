/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_dfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:43:11 by fratardi          #+#    #+#             */
/*   Updated: 2020/05/13 01:21:31 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

unsigned int	ft_hm_llinked(unsigned char **matrice, unsigned char *l,
									unsigned int r, unsigned int size)
{
	unsigned int	i;
	unsigned int	ret;

	i = 0;
	ret = 0;
	while (i < size)
	{
		if (0x80 >> (i % 8) & l[i / 8] &&
			matrice[r][i / 8] & 0x80 >> (i % 8))
			ret++;
		i++;
	}
	return (ret);
}

/*
** add id of the matched room into respective strings
*/

void			collect_dfs(t_anthill *anthill, unsigned int *pos,
								unsigned int to_collect, unsigned int i)
{
	anthill->paths[to_collect][i / 8] |= 0x80 >> (i % 8);
	anthill->total_pths[i / 8] |= 0x80 >> (i % 8);
	*pos += 1;
}

/*
**	Depth first Search
*/

unsigned int	no_start_dfs(t_anthill *anthill, unsigned int entry,
								unsigned int to_collect)
{
	anthill->dfs_map[0][entry / 8] -= 0x80 >> (entry % 8);
	ft_bzero(anthill->paths[to_collect], anthill->real_s);
	return (0);
}

unsigned int	write_pth(t_anthill *anthill, unsigned int siz,
							unsigned int to_collect, unsigned int i)
{
	siz++;
	anthill->paths[to_collect][i / 8] |= 0x80 >> (i % 8);
	anthill->paths[to_collect][(anthill->size - 1) / 8] |=
		0x80 >> ((anthill->size - 1) % 8);
	return (siz);
}

unsigned int	dfs(unsigned int entry, t_anthill *anthill,
						unsigned int to_collect)
{
	unsigned int	i;
	unsigned int	pos;
	unsigned int	s;
	unsigned int	last;

	i = entry;
	pos = 2;
	s = 1;
	last = entry;
	anthill->paths[to_collect][i / 8] |= 0x80 >> (i % 8);
	while (!is_room_linked_to_end(anthill->dfs_map[i], anthill->size))
	{
		if (!(i = find_first_match(anthill->dfs_map[i], anthill->size)) && s++)
		{
			ft_bzero(anthill->paths[to_collect], anthill->real_s);
			return (0);
		}
		if (!(anthill->total_pths[i / 8] & 0x80 >> (i % 8)) && (last = i))
			collect_dfs(anthill, &pos, to_collect, i);
	}
	if (last == i && is_room_linked_to_end(anthill->dfs_map[i], anthill->size))
		s = write_pth(anthill, s, to_collect, i);
	else
		return (no_start_dfs(anthill, entry, to_collect));
	return (pos);
}
