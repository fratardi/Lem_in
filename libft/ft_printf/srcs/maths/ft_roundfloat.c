/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_roundfloat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 23:49:09 by fratardi          #+#    #+#             */
/*   Updated: 2019/06/25 15:37:22 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>

char		*ft_round_ent(char *str)
{
	return (ft_new_addstrings(str, "1"));
}

char		*ft_iterate_dec(char *str, int prec, int *round_ent)
{
	int		i;
	char	*tmp;

	i = prec;
	if ((str[i] == '5' && ((str[i - 1] - 48) % 2 != 0 || str[i + 1] > '5')) ||
			(str[i] >= '5' && (str[i + 1])))
	{
		str[i] = 0;
		tmp = ft_strdup("1");
		str = ft_new_addstrings(str, tmp);
		ft_strdel(&tmp);
	}
	*round_ent = 0;
	return (str);
}

char		*ft_fill_end(char *str, int *round_ent, int prec)
{
	if (prec == 0 && str[0] >= '5' && str[1])
		*round_ent = 1;
	else
		str = ft_iterate_dec(str, prec, round_ent);
	str[prec] = 0;
	return (str);
}

char		*ft_round_dec(char *str, int prec, int *round_ent)
{
	int		i;

	i = prec - ((prec != 0) ? 1 : 0);
	if (prec > (int)ft_strlen(str))
		return (str);
	if (str[i] == '9' && str[i + 1] >= '5' && str[0] == '9')
	{
		while (i > 0 && str[i] == '9')
			i--;
		if (i == 0)
		{
			ft_strdel(&str);
			str = ft_memaset('0', prec);
			*round_ent = 1;
			return (str);
		}
	}
	return (ft_fill_end(str, round_ent, prec));
}

t_double	ft_rounding_float(t_double dble, int prec)
{
	int rounding;

	rounding = 0;
	if (prec == -2)
		prec = 6;
	dble.dec = ft_round_dec(dble.dec, prec, &rounding);
	if (rounding)
	{
		dble.ent = ft_round_ent(dble.ent);
		return (dble);
	}
	return (dble);
}
