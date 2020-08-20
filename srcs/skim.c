/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:51:08 by tpacaud           #+#    #+#             */
/*   Updated: 2020/04/30 12:51:29 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	remove the links to rooms linking to themselves
*/

void			ft_skim_to_itself(unsigned char **matrice, unsigned int size)
{
	unsigned int i;
	unsigned int val;

	val = 0;
	i = size;
	while (val < i)
	{
		if (matrice[val][val / 8] & (0x80 >> (val % 8)))
			matrice[val][val / 8] ^= (0x80 >> (val % 8));
		val++;
	}
}

/*
**	prcedure for when a room contains only one link
*/

unsigned int	ft_skim_proc(unsigned char **matrice, unsigned int pos,
								t_anthill *anthill)
{
	unsigned int i;

	if (!(i = find_first_match(matrice[pos], anthill->size)) ||
			i == anthill->size)
		return (0);
	matrice[pos][i / 8] -= ((0x80) >> (i % 8));
	matrice[i][pos / 8] -= ((0x80) >> (pos % 8));
	if (1 == ft_countlink(matrice[i], anthill->size))
		ft_skim_proc(matrice, i, anthill);
	return (1);
}

/*
**	remove dead ends  + parents
*/

void			ft_skim_dead_ends(unsigned char **matrice, unsigned int size,
									t_anthill *anthill)
{
	unsigned int i;

	i = 1;
	while (i < size - 1)
	{
		if (ft_countlink(matrice[i], size) == 1)
		{
			if (!(ft_skim_proc(matrice, i, anthill)))
				return ;
			i = 0;
		}
		i++;
	}
}

char			skim(t_anthill *anthill)
{
	ft_skim_to_itself(anthill->matrice, anthill->size);
	ft_skim_dead_ends(anthill->matrice, anthill->size, anthill);
	return (1);
}
