/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_convert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 05:46:33 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/24 02:59:30 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*padding_hash_convert(t_printinfo *l, int zero, char **buf)
{
	char	*temp;
	char	*cpy;
	int		octal;

	cpy = *buf;
	octal = (l->prec > (int)ft_strlen(*buf)) ? 1 : 0;
	if (l->alt && ft_strchr("xX", l->t) && cpy[0] && !zero)
	{
		*buf = ft_joinfree(ft_strdup((l->t == 'x') ? "0x" : "0X"), *buf);
		if (!ft_strcmp("0x0", *buf) || !ft_strcmp("0X0", *buf))
		{
			temp = ft_strdup("0");
			ft_strdel(buf);
			*buf = temp;
		}
	}
	else if (l->alt && ft_strchr("oO", l->t))
	{
		if ((l->extra == 0 && ((l->prec >= -2 && !zero) ||
			(octal && zero))) || (l->extra && (!zero || octal)))
			*buf = ft_joinfree(ft_strdup("0"), *buf);
	}
	return (*buf);
}

int			ft_preset_zero_xo(int zero, t_printinfo *l, char *buf, int width)
{
	int ret;

	ret = 0;
	ret += (l->t == 'p' && zero) ? ft_print_uni_str("0x") : 0;
	ret += ft_print_preset_buf('0', width);
	ret += ft_print_uni_str((l->t == 'p' && zero) ? &buf[2] : buf);
	return (ret);
}

int			ft_display_pad_xo(t_printinfo *l, int zero, int ret, char **buf)
{
	int		width;

	width = l->width - ft_strlen(*buf);
	if (width > 0 && !l->left && l->extra && zero && l->prec == -2 && (l->alt
				|| l->t == 'p'))
		ret += ft_preset_zero_xo(zero, l, *buf, width);
	else if (width > 0 && !l->left &&
			((!l->extra && l->prec == -2) || (l->extra)
			|| (l->width > l->prec)))
	{
		ret += ft_print_preset_buf(' ', width);
		ret += ft_print_uni_str(*buf);
	}
	else if (width > 0 && l->left && ((!l->extra && l->prec == -2)
			|| (l->extra) || (l->width > l->prec)))
	{
		ret += ft_print_uni_str(*buf);
		ret += ft_print_preset_buf(' ', width);
	}
	else
		ret += ft_print_uni_str(*buf);
	ft_strdel(buf);
	return (ret);
}

int			ft_pad_xo(t_printinfo *l, int zero, char **buf)
{
	int width;

	width = l->width - ft_strlen(*buf) - ((ft_strchr("xX", l->t) && l->alt) ?
		2 : 0);
	if (l->extra && l->prec == -2 && l->t != 'p' && width > 0 && !l->left)
	{
		if (ft_strchr("oO", l->t) && l->alt)
			width--;
		*buf = ft_joinfree(ft_memaset('0', width), *buf);
	}
	*buf = padding_hash_convert(l, zero, buf);
	return (ft_display_pad_xo(l, zero, 0, buf));
}
