/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:10:32 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/15 07:43:05 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdarg.h>

unsigned long long int	ft_fillunsigned(t_printinfo *list, t_rep *rep)
{
	unsigned long long int ret;

	ret = 0;
	if (list->is_long_double || list->max)
		ret = (unsigned long long int)va_arg(rep->current,
			unsigned long long int);
	else if (list->is_long || ft_strchr("OU", list->t))
		ret = (unsigned long int)va_arg(rep->current, unsigned long int);
	else
		ret = (unsigned int)va_arg(rep->current, unsigned int);
	if (ft_strchr("OU", list->t))
	{
		list->is_long = 1;
		list->t = (list->t == 'U') ? 'u' : list->t;
		list->t = (list->t == 'O') ? 'o' : list->t;
		list->is_char = 0;
		list->is_short = 0;
	}
	rep->vapos++;
	return (ret);
}

long long int			ft_filldi(t_printinfo *list, t_rep *rep)
{
	long long int ret;

	ret = 0;
	if (list->is_long_double || list->max)
		ret = (long long int)va_arg(rep->current, long long int);
	else if (list->is_long)
		ret = (long int)va_arg(rep->current, long int);
	else
		ret = (int)va_arg(rep->current, int);
	rep->vapos++;
	return (ret);
}

char					*ft_fillbuf_digits(t_printinfo *l, t_rep *rep)
{
	char					*buf;
	long long int			temp;
	unsigned long long int	ullitemp;

	buf = NULL;
	if (!l->is_unsigned)
		temp = ft_filldi(l, rep);
	else
		ullitemp = ft_fillunsigned(l, rep);
	if (l->is_char && !l->is_unsigned)
		buf = ft_llitoa((signed char)temp);
	else if (l->is_short && !l->is_unsigned)
		buf = ft_llitoa((signed short)temp);
	else if (!l->is_unsigned)
		buf = ft_llitoa(temp);
	else if (l->is_char && l->is_unsigned)
		buf = ft_ullitoa((unsigned char)ullitemp);
	else if (l->is_short && l->is_unsigned)
		buf = ft_ullitoa((unsigned short)ullitemp);
	else if (l->is_unsigned && l->t == 'u')
		buf = ft_ullitoa(ullitemp);
	return (buf);
}

char					*ft_fillbuf_bin(t_printinfo *l, t_rep *rep)
{
	char			*buf;
	long long int	temp;
	void			*value;

	buf = NULL;
	if (l->t == 'b')
	{
		temp = ft_filldi(l, rep);
		if (l->is_long)
			buf = ft_binary(&temp, sizeof(long int));
		else if (l->is_long_double)
			buf = ft_binary(&temp, sizeof(long long int));
		else
			buf = ft_binary(&temp, sizeof(int));
	}
	else if (l->t == 'B')
	{
		value = (void *)va_arg(rep->current, void *);
		rep->vapos++;
		buf = ft_binary_string(value,
		sizeof(char) * ft_strlen(value));
	}
	return (buf);
}

char					*ft_fillbuf(t_printinfo *l, t_rep *rep)
{
	char	*ret;
	char	c;

	ret = NULL;
	if (l->t == 'd' || l->t == 'i' || l->t == 'u' || l->t == 'U')
		ret = ft_fillbuf_digits(l, rep);
	else if (ft_strchr("oOxXp", l->t))
		ret = ft_fillbuf_convert(l, rep);
	else if (ft_strchr("bB", l->t))
		ret = ft_fillbuf_bin(l, rep);
	else if (l->t == 'f')
		ret = ft_fillbuf_float(l, rep);
	else if (l->t == 's')
		ft_pick_va_string(&ret, rep);
	else if (l->t == 'c' && (rep->vapos += 1))
	{
		c = (int)va_arg(rep->current, int);
		if (c == 0)
			l->special = 0;
		ret = ft_strndup(&c, 1);
	}
	return (ret);
}
