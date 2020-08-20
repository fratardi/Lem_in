/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adjustfloat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 00:03:20 by tpacaud           #+#    #+#             */
/*   Updated: 2019/06/24 05:25:28 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>

/*
**Functions to adjust str_numbers for addstrings
*/

void		ft_adjustnegpo(char **s1, char **s2)
{
	size_t	i1;
	size_t	i2;
	char	*tojoin;

	i1 = ft_strlen(*s1);
	i2 = ft_strlen(*s2);
	if (i1 == i2)
		return ;
	if (i1 < i2)
	{
		if (!(tojoin = (char *)ft_memalloc(sizeof(char) * (i2 - i1 + 1))))
			return ;
		ft_memset(tojoin, '0', i2 - i1);
		*s1 = ft_joinfree(*s1, tojoin);
	}
	if (i1 > i2)
	{
		if (!(tojoin = (char *)ft_memalloc(sizeof(char) * (i1 - i2 + 1))))
			return ;
		ft_memset(tojoin, '0', i1 - i2);
		*s2 = ft_joinfree(*s2, tojoin);
	}
}

void		ft_adjustpospo(char **s1, char **s2)
{
	size_t	i1;
	size_t	i2;
	char	*tojoin;

	i1 = ft_strlen(*s1);
	i2 = ft_strlen(*s2);
	if (i1 == i2)
		return ;
	if (i1 < i2)
	{
		if (!(tojoin = (char *)ft_memalloc(sizeof(char) * (i2 - i1 + 1))))
			return ;
		ft_memset(tojoin, '0', i2 - i1);
		*s1 = ft_joinfree(tojoin, *s1);
	}
	if (i1 > i2)
	{
		if (!(tojoin = (char *)ft_memalloc(sizeof(char) * (i1 - i2 + 1))))
			return ;
		ft_memset(tojoin, '0', i1 - i2);
		*s2 = ft_joinfree(tojoin, *s2);
	}
}

/*
**Function to display str_long_double with E^
*/

char		*ft_floatexp(char *str, int prec)
{
	int		i;
	int		puiss;
	char	*ret;

	i = 2;
	puiss = 0;
	if (str[0] != '0')
		return (str);
	while (str[i] && str[i] == '0')
		i++;
	puiss = i - 1;
	ret = ft_memaset(str[i], 1);
	ret = ft_joinfree(ret, ft_strdup("."));
	ret = ft_joinfree(ret, ft_strndup(&str[i + 1], (prec) ? prec : 6));
	ret = ft_joinfree(ret, ft_strdup("E-"));
	ret = ft_joinfree(ret, ft_itoa(puiss));
	ft_strdel(&str);
	prec = 0;
	return (ret);
}
