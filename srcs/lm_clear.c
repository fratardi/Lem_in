/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:27:59 by fratardi          #+#    #+#             */
/*   Updated: 2020/04/30 14:28:09 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** DEBUG - OLD FUNCTION TO PRINT THE LAYER TAB WITH ROOMS ID
*/

void			ft_show_doors(unsigned char *path, unsigned int size)
{
	unsigned int	pos;
	unsigned int	numb;
	unsigned int	mem;

	pos = 0;
	mem = 0;
	numb = 0;
	while (pos < size)
	{
		if (path[pos / 8] & (0x80 >> (pos % 8)))
		{
			if (numb == 0)
				ft_printf("\033[31m[% 5zu]\033[00m", pos);
			else
				ft_printf("\033[32m[% 5zu]\033[00m", pos);
			if (pos == 0)
				ft_printf("\033[32m[% 5zu]\033[00m", pos);
			mem = pos;
			numb++;
		}
		pos++;
	}
	ft_printf("\n");
}

/*
**	bzero  a whole uchar tab
**	but the address
*/

void			ft_bzero_uctab(unsigned char **mat, unsigned int mat_size,
								unsigned int lsize)
{
	unsigned int	i;

	i = 0;
	while (i < mat_size)
	{
		ft_bzero(mat[i], lsize);
		i++;
	}
}

/*
**	check if two sets collide
*/

unsigned int	ft_is_colide(t_anthill *anthill, unsigned char *hash1,
								unsigned char *hash2)
{
	unsigned int i;

	i = 1;
	while (i < anthill->size - 1)
	{
		while (!(hash1[i] & hash2[i]))
			i += 8;
		if (hash1[i] & hash2[i])
			return (1);
	}
	return (0);
}
