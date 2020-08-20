/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_room_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 15:48:43 by fratardi          #+#    #+#             */
/*   Updated: 2020/04/30 15:48:53 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** finds the indexof the first active bitelse returns zero
*/

unsigned int	find_first_match(unsigned char *line, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (line[i / 8] & 0x80 >> (i % 8))
			return (i);
		i++;
	}
	return (0);
}

/*
**	count the number of links within a room
*/

unsigned int	ft_countlink(unsigned char *ligne, unsigned int size)
{
	unsigned int	pos;
	unsigned int	ret;
	unsigned char	mask;
	unsigned char	tmp;

	pos = 0;
	ret = 0;
	while (pos < size)
	{
		mask = 0x80;
		while (!ligne[pos / 8] && pos < size)
			pos += 8;
		if (ligne[pos / 8])
		{
			tmp = ligne[pos / 8];
			while (mask)
			{
				if (mask & tmp)
					ret++;
				pos++;
				mask >>= 1;
			}
		}
	}
	return (ret);
}

/*
**Count column
*/

unsigned int	c_column(unsigned char **matrice, unsigned int r,
							unsigned int size)
{
	unsigned int	i;
	unsigned int	ret;

	i = 0;
	ret = 0;
	if (r >= size)
		return (0);
	while (i < size - 1)
	{
		if (matrice[i][r / 8] & 0x80 >> (r % 8))
			ret++;
		i++;
	}
	return (ret);
}

/*
** 0x00 if no _link
** 0xF0 if l1 only in l2
** 0x0F if l2 only in l1
** 0xFF if l1 & l2 in both rooms  is  adj linkup
*/

unsigned char	ft_is_adj_up(unsigned char **matrice, unsigned int l1,
								unsigned int l2)
{
	unsigned char	ret;

	ret = 0;
	if (matrice[l1][l2 / 8] & (0x80 >> (l2 % 8)))
		ret |= 0x0F;
	if (matrice[l2][l1 / 8] & (0x80 >> (l1 % 8)))
		ret |= 0xF0;
	return (ret);
}

/*
**	returns the len of the matrix
*/

unsigned int	ft_matr_size(unsigned char **matrice)
{
	if (!&*matrice[0] || !matrice[0])
		return (0);
	return (1 + ft_matr_size(&matrice[1]));
}
