/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_float_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 02:56:44 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/26 07:15:37 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>

int			ft_pad_char_type(t_printinfo *l, char **buf)
{
	int	width;
	int	ret;

	ret = 0;
	width = l->width - ft_strlen(*buf) - ((l->special == 0) ? 1 : 0);
	if (l->t == 'c' && l->special == 0 && l->left && (ret += 1))
		ft_putchar(0);
	if (width > 0 && !l->left)
	{
		ret += ft_print_preset_buf(((l->t == 'c' || *buf[0] == 0 ||
		(l->t == 's')) && l->extra) ? '0' : ' ', width);
		ret += ft_print_uni_str(*buf);
	}
	else if (width > 0 && l->left)
	{
		ret += ft_print_uni_str(*buf);
		ret += ft_print_preset_buf(((l->t == 'c' || *buf[0] == 0 ||
			l->t == 's') && l->extra) ? ' ' : ' ', width);
	}
	else
		ret += ft_print_uni_str(*buf);
	if (l->t == 'c' && l->special == 0 && !l->left && (ret += 1))
		ft_putchar(0);
	ft_strdel(buf);
	return (ret);
}

int			ft_pad_float(t_printinfo *l, char **buf)
{
	int	width;
	int	ret;

	ret = 0;
	width = l->width - ft_strlen(*buf) - ((l->special == 0) ? 1 : 0);
	if (width > 0 && !l->left)
	{
		ret += ft_print_preset_buf(' ', width);
		ret += ft_print_uni_str(*buf);
	}
	else if (width > 0 && l->left)
	{
		ret += ft_print_uni_str(*buf);
		ret += ft_print_preset_buf(' ', width);
	}
	else
		ret += ft_print_uni_str(*buf);
	ft_strdel(buf);
	return (ret);
}
