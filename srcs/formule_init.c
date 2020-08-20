/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formule_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 10:56:33 by tpacaud           #+#    #+#             */
/*   Updated: 2020/04/30 11:02:27 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Mathematical Forumula to find how much line are required  to send all ants
*/

t_formset		*calc_form(t_anthill *anthill, unsigned char **mat,
							t_formset *form, unsigned int pth_id)
{
	unsigned int i;

	i = 0;
	while (mat[i] && !ft_is_room_empty(mat[i], anthill->size) && i < pth_id)
	{
		form->min_ants +=
			(form->longest - (current_len_path(mat[i], anthill->real_s) - 1));
		i++;
	}
	if (form->nb_pths > 1 && (anthill->ants - 1) > form->min_ants - 1)
	{
		i = (anthill->ants - form->min_ants - 1) / form->nb_pths;
		form->ret = form->longest + i;
		anthill->dis.nb_f_all = i;
	}
	else if ((form->nb_pths == 1 || (form->nb_pths > 1 && form->min_ants == 0)))
		form->ret = anthill->ants + form->longest - 1 / form->nb_pths;
	else if (form->nb_pths)
		form->ret = form->longest;
	else
		form->ret = 0xFFFFFFFF;
	return (form);
}

t_formset		*init_form(t_anthill *anthill, unsigned char **mat,
							t_formset *form, unsigned int pth_id)
{
	unsigned int	i;
	unsigned int	last_ret;

	i = 0;
	if (!form)
		return (NULL);
	last_ret = 0;
	while (form && form->next)
	{
		last_ret = form->ret;
		form = form->next;
	}
	form->nb_pths = pth_id;
	form->min_ants = 0;
	while (mat[i] && !ft_is_room_empty(mat[i], anthill->size) && i < pth_id)
	{
		if ((current_len_path(mat[i], anthill->real_s) - 1) > form->longest)
			form->longest = (current_len_path(mat[i], anthill->real_s) - 1);
		i++;
	}
	form = calc_form(anthill, mat, form, pth_id);
	if (last_ret > 0 && form->ret > last_ret)
		return (form);
	return (form);
}
