/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 12:11:07 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/15 07:49:22 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdarg.h>

void	ft_pick_va_string(char **ret, t_rep *rep)
{
	*ret = (char *)va_arg(rep->current, char *);
	*ret = ft_strdup((*ret == NULL) ? "(null)" : *ret);
	rep->vapos++;
}

void	ft_star_search(t_rep *rep, t_printinfo *info)
{
	if (info->width == -1)
	{
		info->width = (int)va_arg(rep->current, int);
		if (info->width < 0)
		{
			info->left = 1;
			info->width = -info->width;
		}
		rep->vapos++;
	}
	if (info->prec == -1)
	{
		info->prec = (int)va_arg(rep->current, int);
		rep->vapos++;
		if (info->prec < 0)
			info->prec = -2;
	}
}

void	ft_arg_search(t_rep *rep, t_printinfo *info)
{
	if (!info->ndol || rep->vapos == 0)
		return ;
	if (info->ndol != 0 && (int)info->ndol != rep->vapos)
	{
		if ((int)info->ndol < rep->vapos)
		{
			va_end(rep->current);
			va_copy(rep->current, rep->start);
			rep->vapos = 1;
		}
		while (rep->vapos < (int)info->ndol)
		{
			(void)va_arg(rep->current, int);
			rep->vapos++;
		}
	}
}
