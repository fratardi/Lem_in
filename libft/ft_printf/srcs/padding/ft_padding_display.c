/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_display.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 03:12:49 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/26 06:35:40 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		ft_padding_display(t_printinfo *l, char **buf, int zero)
{
	if (l->t == 'p' && !ft_same("0x0", *buf))
		zero = 1;
	if (l->t == 'f' && (!ft_strcmp(*buf, "nan") || !ft_strcmp(*buf, "inf")
		|| !ft_strcmp(*buf, "-inf")))
		return (ft_pad_float(l, buf));
	if (ft_strchr("diuUf", l->t))
		return (ft_pad_di(l, buf));
	if (ft_strchr("xXoOp", l->t))
		return (ft_pad_xo(l, zero, buf));
	if (l->t == 'c' || l->t == 's' || ft_strchr("Bb", l->t))
		return (ft_pad_char_type(l, buf));
	if (l->t == 'f' && l->prec == 0 && l->showsign && !l->alt && !l->extra)
	{
		*buf[ft_strlen(*buf) - 1] = 0;
		ft_strdel(buf);
	}
	return (0);
}
