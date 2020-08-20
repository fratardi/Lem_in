/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_init_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 22:41:16 by fratardi          #+#    #+#             */
/*   Updated: 2020/05/13 06:51:50 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"

/*
**Print only end (1line) if start is directly linked to end room
*/

static void				se(t_anthill *anthill)
{
	unsigned int i;
	unsigned int end;

	end = anthill->size - 1;
	i = 1;
	while (i <= anthill->ants)
	{
		ft_printf("L%zu-%s ", i, roomname_from_roomid(anthill->room, end));
		i++;
	}
	ft_putchar('\n');
	exit(0);
}

/*
** Init the struct s_anthill
*/

static unsigned char	lm_init_matr(t_anthill *anthill)
{
	if (!(anthill->dfs_map = malloc_matr(
			anthill->size + 1, anthill->real_s + 1)))
		return (0);
	if (!(anthill->dfs_dup = malloc_matr(
			anthill->size + 1, anthill->real_s + 1)))
		return (0);
	if (!(anthill->paths = malloc_matr(
			anthill->size + 1, anthill->real_s + 1)))
		return (0);
	return (1);
}

static unsigned char	ft_init_anthill(t_anthill *anthill, t_lines *read)
{
	if (!(anthill->matrice = matrice(read, anthill->room)))
	{
		free_buf(read);
		return (0);
	}
	anthill->size = ft_matr_size(anthill->matrice);
	if (is_room_linked_to_end(anthill->matrice[0], anthill->size))
		se(anthill);
	if (!(anthill->total_pths = (unsigned char *)ft_memalloc(
			sizeof(unsigned char) * (anthill->size + 1))))
		return (0);
	if (!(anthill->update_total = (unsigned char *)ft_memalloc(
			sizeof(unsigned char) * (anthill->size + 1))))
		return (0);
	anthill->real_s = (anthill->size / 8) + ((anthill->size % 8 > 0) ? 1 : 0);
	if (!(anthill->layer = malloc_matr(anthill->size + 1, anthill->real_s + 1)))
		return (0);
	if (!lm_init_matr(anthill))
		return (0);
	skim(anthill);
	if (!(anthill->bfs_total = (unsigned char *)ft_memalloc(
			sizeof(unsigned char) * (anthill->real_s + 1))))
		return (0);
	return (1);
}

unsigned int			ferr(t_lines *read)
{
	free_buf(read);
	return (0);
}

unsigned char			ft_init_anthill_parse(t_anthill *anthill)
{
	t_lines	*read;
	int		all[3];

	all[0] = 0;
	if (!(read = ft_to_buf_file()))
		return (0);
	anthill->read = read;
	if (read->line && read->line[0])
		all[0] = check_first(read->line, ft_strlen(read->line));
	if (all[0] == 0)
		return (0);
	anthill->ants = all[0];
	if (all[0])
	{
		if (!(anthill->room = check_second(read->next))
			|| (!(anthill->room = start_first(anthill->room)))
			|| (!(anthill->room = end_last(anthill->room))))
			return (ferr(read));
	}
	if (!anthill->room)
		return (0);
	anthill->form = NULL;
	anthill->b_set.form = NULL;
	return (ft_init_anthill(anthill, read));
}
