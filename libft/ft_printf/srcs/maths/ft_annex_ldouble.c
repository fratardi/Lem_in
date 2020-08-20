/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_ldouble.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:08:12 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/23 02:24:53 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

/*
**Conditions according to the sign of exposant
*/

t_double	ft_doublesign(t_double dble, char end)
{
	dble.temp = ft_pow2str(dble.b + dble.ex, end);
	if (dble.b + dble.ex >= 0)
	{
		ft_adjustpospo(&dble.temp, &dble.ent);
		dble.tempent = ft_addstrings(dble.temp, dble.ent);
		ft_strdel(&dble.ent);
		dble.ent = dble.tempent;
	}
	else if (dble.b + dble.ex < 0)
	{
		ft_adjustnegpo(&dble.dec, &dble.temp);
		ft_addstrings_stack(dble.dec, dble.temp, ft_strlen(dble.dec),
			ft_strlen(dble.temp));
	}
	ft_strdel(&dble.temp);
	return (dble);
}

/*
**Main function to calculate and transform mant&exp to str long double
*/

t_double	ft_distribute_exp(int *i, t_double dble)
{
	int cpy;
	int b_cpy;

	while (dble.m[*i] && (dble.b + dble.ex) >= 0)
	{
		*i += 1;
		dble.b--;
	}
	dble.b++;
	cpy = *i + 1;
	b_cpy = dble.b - 1;
	while (*i > 0)
	{
		if (dble.m[*i] == '1')
			dble = ft_doublesign(dble, 0);
		*i -= 1;
		dble.b++;
	}
	*i = (cpy > 64) ? 64 : cpy;
	dble.b = b_cpy;
	return (dble);
}

void		ft_free_staticpo(void)
{
	free(ft_pow2str(-1, 1));
	free(ft_pow2str(1, 1));
}

char		*ft_ldouble(long double a, int prec, unsigned int is_ten, int sign)
{
	t_double	dble;
	int			i;

	i = 0;
	if (a == 0)
		return (ft_float_zero(prec, is_ten, a, sign));
	dble = init_dble(a);
	dble = ft_distribute_exp(&i, dble);
	while (dble.m[i])
	{
		if (dble.m[i++] == '1')
			dble = ft_doublesign(dble, 0);
		dble.b--;
	}
	if (!dble.m[i])
		ft_free_staticpo();
	if (!is_ten)
		dble = ft_rounding_float(dble, prec);
	dble.ent = ((a < 0.0) ? ft_joinfree(ft_strdup("-"), dble.ent) : dble.ent);
	if (prec != 0 || (!sign))
		dble.ent = ft_joinfree(dble.ent, ft_strdup("."));
	dble.ent = ft_joinfree(dble.ent, dble.dec);
	ft_strdel(&dble.m);
	dble.ent = (is_ten) ? ft_floatexp(dble.ent, prec) : dble.ent;
	return (dble.ent);
}
