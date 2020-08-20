/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 17:24:26 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/09 22:34:43 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

/*
**  Initialize the formula structure prior to exploitation
*/

void			malloc_form(t_anthill *anthill)
{
	t_formset *form;

	form = anthill->form;
	if (!form)
		return ;
	while (form && form->next)
		form = form->next;
	if (!(form->next = (t_formset *)ft_memalloc(sizeof(t_formset))))
		exit(1);
	form = form->next;
	form->longest = 0;
	form->min_ants = 0;
	form->nb_pths = 0;
	form->ret = 0;
	form->next = NULL;
}

/*
**	Stocks the best set among  them all
*/

unsigned int	stock_best(t_anthill *anthill, t_formset *form,
							unsigned char **mat, unsigned int nbp)
{
	t_best_set	ret;

	ret = anthill->b_set;
	if (!ret.form || form->ret <= ret.form->ret)
	{
		ret.form = form;
		ret.mat_pths = mat;
		ret.nb_pths = nbp;
		ret.nb_f_all = anthill->dis.nb_f_all;
		anthill->b_set = ret;
		dup_matrice(anthill);
		return (1);
	}
	else if (nbp == 2 && current_len_path(mat[0], anthill->real_s)
			== current_len_path(mat[1], anthill->real_s))
		return (1);
	return (0);
}

/*
**	Finds the bes set among the one already found
*/

unsigned int	get_best(t_anthill *ant, unsigned int id,
							unsigned char **mat, unsigned int start_set)
{
	unsigned int	nbp;
	unsigned int	last_form;
	t_formset		*form;
	unsigned int	ret;
	unsigned int	tmp;

	last_form = 0;
	ret = 0;
	form = ant->form;
	nbp = id;
	while (nbp > 0)
	{
		form = init_form(ant, mat, form, id - nbp + 1);
		malloc_form(ant);
		(tmp = stock_best(ant, form, mat, id - nbp + 1));
		ret += tmp;
		if (tmp == 1)
			ant->b_set.start_set = start_set;
		form = form->next;
		nbp--;
	}
	return (ret);
}
