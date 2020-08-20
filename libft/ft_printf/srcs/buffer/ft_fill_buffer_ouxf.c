/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_buffer_ouxf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 04:00:28 by fratardi          #+#    #+#             */
/*   Updated: 2019/08/15 07:41:44 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_fillbuf_float(t_printinfo *l, t_rep *rep)
{
	long double	flts;
	char		*buf;
	char		*exception;
	int			i;

	buf = NULL;
	i = (!l->alt) ? 1 : 0;
	flts = (l->is_long_double) ?
	(va_arg(rep->current, long double)) : (va_arg(rep->current, double));
	rep->vapos++;
	exception = ft_exception(flts, l);
	if (exception == NULL)
	{
		if (l->t == 'f' && !l->is_long_double)
			buf = ft_ldouble(flts, (l->prec < 0) ? 6 :
				l->prec, l->is_float_ten, i);
		else if (l->t == 'f' && l->is_long_double)
			buf = ft_ldouble(flts,
			(l->prec < 0) ? 6 : l->prec, l->is_float_ten, i);
	}
	else
		buf = exception;
	return (buf);
}

char	*ft_fillbuff_convert_o(t_printinfo *l, unsigned long long int temp)
{
	char *buf;

	buf = NULL;
	if (l->t == 'o' && l->is_char)
		buf = ft_convert_o((unsigned char)temp);
	else if (l->t == 'o' && l->is_short)
		buf = ft_convert_o((unsigned short)temp);
	else if (l->t == 'o')
		buf = ft_convert_o(temp);
	return (buf);
}

char	*ft_fillbuff_convert_low_x(t_printinfo *l, unsigned long long int temp)
{
	char *buf;

	buf = NULL;
	if (l->t == 'x' && l->is_char)
		buf = ft_convert_x((unsigned char)temp);
	else if (l->t == 'x' && l->is_short)
		buf = ft_convert_x((unsigned short)temp);
	else if (l->t == 'x')
		buf = ft_convert_x(temp);
	return (buf);
}

char	*ft_fillbuff_convert_up_x(t_printinfo *l, unsigned long long int temp)
{
	char *buf;

	buf = NULL;
	if (l->t == 'X' && l->is_char)
		buf = ft_convert_up_x((unsigned char)temp);
	else if (l->t == 'X' && l->is_short)
		buf = ft_convert_up_x((unsigned short)temp);
	else if (l->t == 'X')
		buf = ft_convert_up_x(temp);
	return (buf);
}

char	*ft_fillbuf_convert(t_printinfo *l, t_rep *rep)
{
	char					*buf;
	unsigned long long int	temp;

	buf = NULL;
	if (l->t == 'p')
		return (ft_convert_p(va_arg(rep->current, void *)));
	temp = ft_fillunsigned(l, rep);
	if (l->t == 'o')
		buf = ft_fillbuff_convert_o(l, temp);
	if (l->t == 'x')
		buf = ft_fillbuff_convert_low_x(l, temp);
	else if (l->t == 'X')
		buf = ft_fillbuff_convert_up_x(l, temp);
	return (buf);
}
