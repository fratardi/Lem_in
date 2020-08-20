/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 22:22:21 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/18 04:44:08 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>

char		*ft_casenull(char *str, int *last)
{
	ft_strdel(&str);
	*last = 0;
	return (ft_strdup("0"));
}

/*
**Function to initialize values
*/

t_double	init_dble(long double a)
{
	t_double dble;

	dble.b = -1;
	dble.ex = ft_expldouble(a);
	dble.dec = (dble.ex < 0) ? ft_pow2str(0 + dble.ex, 0) : ft_strdup("0");
	dble.ent = (dble.ex >= 0) ? ft_pow2str(0 + dble.ex, 0) : ft_strdup("0");
	dble.m = ft_mantissaldouble(a);
	return (dble);
}

/*
**If float == 0
*/

char		*ft_float_zero(int prec, unsigned int is_ten, long double a, int s)
{
	char	*ret;
	int		temp;
	int		i;
	char	*bin;

	temp = 0;
	bin = ft_binary(&a, 10);
	ret = ft_strdup((ft_strchr(bin, '1')) ? "-0.0000000" : "0.0000000");
	i = prec;
	ft_strdel(&bin);
	if (is_ten && prec > 0)
		ret = ft_floatexp(ret, prec + ((ret[0] == '-') ? 3 : 2));
	if (prec == -2)
		return (ret);
	if (prec > 0)
		ret = ft_round_dec(ret, prec + ((ret[0] == '-') ? 3 : 2), &temp);
	s = (s == 0) ? 1 : 0;
	if (i == 0)
		ret[s + ((ret[0] == '-') ? 2 : 1)] = 0;
	return (ret);
}

char		*ft_exception(long double a, t_printinfo *list)
{
	int		ex;
	char	*m;
	char	*inf;

	ex = ft_expldouble(a);
	if (ex >= -16383 && ex <= 16383)
		return (NULL);
	m = ft_mantissaldouble(a);
	list->is_char = 0;
	inf = ft_memaset('0', 63);
	if (ft_strcmp(inf, &m[1]) == 0)
	{
		ft_strdel(&inf);
		ft_strdel(&m);
		return (ft_strdup((a < 0) ? "-inf" : "inf"));
	}
	else if (ft_strcmp(inf, &m[1]) != 0)
	{
		ft_strdel(&inf);
		ft_strdel(&m);
		return (ft_strdup("nan"));
	}
	ft_strdel(&inf);
	ft_strdel(&m);
	return (ft_strdup("nan"));
}
