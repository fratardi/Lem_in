/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_anthill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 17:11:02 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/09 22:41:52 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void		free_form(t_formset *form)
{
	t_formset *ffree;

	while (form && form->next)
	{
		ffree = form;
		form = form->next;
		free(ffree);
		ffree = NULL;
	}
	if (form)
		free(form);
}

void		free_rooms(t_room *rooms)
{
	t_room *rfree;

	rfree = NULL;
	while (rooms && rooms->next)
	{
		rfree = rooms;
		rooms = rooms->next;
		free(rfree->name);
		free(rfree);
		rfree = NULL;
	}
	if (rooms)
		free(rooms);
}

void		free_matrice(unsigned char **matrice, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i <= size && matrice[i])
	{
		free(matrice[i]);
		matrice[i] = NULL;
		i++;
	}
	if (matrice)
	{
		free(matrice);
		matrice = NULL;
	}
}

void		free_anthill(t_anthill *anthill)
{
	free(anthill->total_pths);
	free(anthill->update_total);
	free(anthill->bfs_total);
	free_matrice(anthill->layer, anthill->size);
	free_matrice(anthill->matrice, anthill->size);
	free_matrice(anthill->dfs_map, anthill->size);
	free_matrice(anthill->paths, anthill->size);
	free_rooms(anthill->room);
	free_form(anthill->form);
}
