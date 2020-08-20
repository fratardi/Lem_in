/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_prec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 20:54:25 by fratardi          #+#    #+#             */
/*   Updated: 2019/08/31 17:54:36 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>

char		*ft_precdigits(int prec, int neg, t_printinfo *l, char *buf)
{
	char *temp;

	if (ft_strchr("di", l->t))
	{
		if (prec && buf[0] == '-' && (neg = -1))
		{
			temp = ft_strdup(&buf[1]);
			ft_strdel(&(buf));
			buf = temp;
		}
		buf = (prec > 0) ? ft_joinfree(ft_memaset('0', (size_t)prec),
				buf) : buf;
		buf = (neg != 0) ? ft_joinfree(ft_strdup("-"), buf) : buf;
	}
	return (buf);
}

char		*ft_prec_uns_ptr(t_printinfo *l, int prec, char *buf)
{
	char *temp;
	char *pad;

	pad = NULL;
	if (ft_strchr("uoxX", l->t) && prec > 0)
	{
		prec -= (ft_strchr("oO", l->t) && l->alt) ? 1 : 0;
		if ((int)(ft_strlen(buf) + 1) != l->prec)
			pad = ft_memaset('0', (size_t)prec);
		else if (prec == 1)
			pad = ft_strdup("0");
		buf = ft_joinfree(pad, buf);
	}
	if (l->t == 'p' && l->prec > (int)ft_strlen(buf) - 2)
	{
		temp = ft_strdup(&buf[2]);
		ft_strdel(&(buf));
		pad = ft_memaset('0', l->prec - ft_strlen(temp));
		buf = ft_joinfree(pad, temp);
		buf = ft_joinfree(ft_strdup("0x"), buf);
	}
	return (buf);
}

char		*ft_pad_prec(t_printinfo *l, char *buf)
{
	int prec;
	int neg;

	neg = 0;
	if ((l->prec == 0) && (ft_strchr("diuxX", l->t) || (ft_strchr("oO", l->t)
				&& !l->alt)) && ft_strlen(buf) == 1 && buf[0] == '0')
	{
		buf[0] = 0;
		return (buf);
	}
	if (l->prec < 0 || l->t == 'f' || l->t == 'c')
		return (buf);
	prec = l->prec - ft_strlen(buf) + ((buf[0] == '-' &&
			ft_strchr("di", l->t)) ? 1 : 0);
	buf = ft_prec_uns_ptr(l, prec, buf);
	if (l->t == 'p' && l->prec == 0 && buf[2] == '0')
		buf[2] = 0;
	if (l->t == 's' && prec < 0 && l->prec >= 0)
		buf[l->prec] = 0;
	buf = ft_precdigits(prec, neg, l, buf);
	return (buf);
}
