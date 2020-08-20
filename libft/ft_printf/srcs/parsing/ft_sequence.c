/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sequence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 02:07:09 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/28 04:41:10 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>

int			ft_sequencelen(const char *format)
{
	int i;

	i = 0;
	if (format[0])
		i++;
	while (format[i] && ft_strchr("%", format[i]) == NULL)
		i++;
	return (i);
}

int			ft_init_sequence(char *str, t_no_syntax *content, size_t len)
{
	int i;

	content->extra = 0;
	content->left = 0;
	i = 1;
	while (ft_strchr("-+ 0#", str[i]) && str[i] && (unsigned int)i < len)
	{
		(str[i] == '-') ? (content->left = 1) : 0;
		(str[i] == '0') ? (content->extra = 1) : 0;
		i++;
	}
	content->width = ft_atoi((str + i));
	content->width -= (content->width) ? 1 : 0;
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '.')
		&& (unsigned int)i < len)
		i++;
	return (i);
}

size_t		ft_sequence(char *s, int len)
{
	int			i;
	int			rest;
	t_no_syntax	sy;

	rest = ft_sequencelen(&s[len]);
	i = ft_init_sequence(s, &sy, len);
	sy.ret = (sy.left) ? 1 : 0;
	if (sy.left)
		ft_putchar((s[i] == 0) ? s[len] : s[i]);
	if (sy.width > 0)
		sy.ret += ft_print_preset_buf(
			(sy.extra == 1 && !sy.left) ? '0' : ' ', sy.width);
	if (i <= len)
	{
		if (s[i + ((sy.left) ? 1 : 0)] == '%')
			sy.ret += ft_print_n_uni_str(&s[i + ((sy.left) ? 1 : 0)], rest);
		else if (len - i)
			sy.ret += ft_print_n_uni_str(&s[i + ((sy.left) ? 1 : 0)], len - i);
		else if (rest-- > 0)
			sy.ret += ft_print_n_uni_str(&s[i + ((sy.left) ? 1 : 0)], rest);
	}
	else if (s[len] != 0)
		sy.ret += ft_print_uni_str((sy.left) ? &s[len + 1] : &s[len]);
	return (sy.ret);
}
