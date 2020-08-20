/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:12:19 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/28 03:20:00 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**Fill ndol
*/

t_printinfo	*ft_fillndol(char *str, t_printinfo *list)
{
	int i;

	i = 1;
	while (str[i] && str[i] != '$')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i--;
	i--;
	list->ndol = ft_atoi(&str[i]);
	return (list);
}

/*
**Fill Flag
*/

t_printinfo	*ft_fillflag(char *str, t_printinfo *list)
{
	int i;

	i = 1;
	while (str[i] && str[i] != '$')
		i++;
	i = (str[i] == '$') ? (i + 1) : 1;
	while (str[i] && str[i] != '.')
	{
		if (list->extra != 1 && !ft_isdigit(str[i - 1]))
			list->extra = (str[i] == '0') ? 1 : 0;
		if (list->space != 1)
			list->space = (str[i] == ' ') ? 1 : 0;
		if (list->alt != 1)
			list->alt = (str[i] == '#') ? 1 : 0;
		if (list->left != 1)
			list->left = (str[i] == '-') ? 1 : 0;
		if (list->showsign != 1)
			list->showsign = (str[i] == '+') ? 1 : 0;
		if (list->group != 1)
			list->group = (str[i] == '\'') ? 1 : 0;
		if (list->bin != 1)
			list->bin = (str[i] == 'b') ? 1 : 0;
		i++;
	}
	return (list);
}

/*
**Fill precision
*/

t_printinfo	*ft_fillprec(char *str, t_printinfo *list)
{
	int i;

	i = ft_strlen(str);
	while (i > 0 && str[i] != '.')
		i--;
	if (i == 0)
		return (list);
	i++;
	list->prec = (str[i] == '*') ? -1 : ft_atoi(&str[i]);
	return (list);
}

/*
**Fill width
*/

t_printinfo	*ft_fillwidth(char *str, t_printinfo *list, t_rep *rep)
{
	int i;

	i = 1;
	while (str[i] && str[i] != '$')
		i++;
	i = (!str[i]) ? 1 : i;
	while (str[i] && ft_strchr("$0 #'-+", str[i]))
		i++;
	if (str[i] != '0' && ft_atoi(&str[i]) == 0 && str[i] != '*')
	{
		list->width = -2;
		return (list);
	}
	list->width = (str[i] == '*') ? -1 : ft_atoi(&str[i]);
	if (ft_isdigit(str[i + 1]) && list->width == -1)
	{
		va_arg(rep->current, int);
		rep->vapos++;
		list->width = ft_atoi(&str[i + 1]);
	}
	return (list);
}
