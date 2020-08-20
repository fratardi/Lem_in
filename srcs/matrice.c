/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 00:44:30 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/04 16:40:04 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

/*
**	bzero  a whole uchar tab
**	but the address
*/

void			ft_bzero_uctab(unsigned char **mat, unsigned int mat_size,
							unsigned int lsize)
{
	unsigned int i;

	i = 0;
	while (i < mat_size)
	{
		ft_bzero(mat[i], lsize);
		i++;
	}
}

/*
**	computes the number of rooms
*/

unsigned int	size_grid(t_room *rooms)
{
	unsigned int size;

	size = 0;
	if (!rooms)
		return (0);
	while (rooms->next != NULL)
	{
		size++;
		rooms = rooms->next;
	}
	return (size);
}

/*
**	malloc tab from presets infos
*/

unsigned char	**malloc_matr(int row, int collumn)
{
	unsigned char	**tab;
	int				i;

	i = 0;
	if (!(tab = (unsigned char **)ft_memalloc(sizeof(unsigned char *) *
			(row + 1))))
		exit(1);
	tab[row] = NULL;
	while (i < row)
	{
		if (!(tab[i] = (unsigned char *)ft_memalloc(sizeof(unsigned char) *
				collumn)))
			exit(1);
		i++;
	}
	return (tab);
}

/*
**	mallocates a Blank grid from room infos
*/

unsigned char	**ft_create_matrice(t_room *rooms)
{
	int size;

	if (0 == (size = size_grid(rooms)))
		return (NULL);
	return (malloc_matr(size, (size / sizeof(char)) +
				(size % sizeof(char) ? 1 : 0)));
}

/*
**	mallocates grid and  fills it with relevant infos
*/

unsigned char	**matrice(t_lines *buf, t_room *rooms)
{
	t_lines			*start;
	unsigned char	**matrice;

	start = buf;
	while (buf->line && !ft_strchr(buf->line, '-'))
		buf = buf->next;
	if (!(matrice = ft_create_matrice(rooms)))
		return (NULL);
	while (buf->next)
	{
		if (!(buf = init_mat(buf, rooms, matrice)))
			return (NULL);
	}
	return (matrice);
}
