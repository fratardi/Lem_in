/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issyntax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:40:55 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/28 04:01:01 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../includes/ft_printf.h"

int		ft_syntaxlen(const char *format)
{
	int i;

	i = 1;
	while (format[i] && ft_strchr("diouxXcfspUObB", format[i]) == NULL)
		i++;
	if (ft_strchr("diouxXcfspUObB", format[i]) != NULL)
		i++;
	return (i);
}

/*
**Verify if str contain a good syntax
*/

int		ft_freestr_return_no(char **str)
{
	ft_strdel(str);
	return (0);
}

int		ft_iterate_syntax(char *str, int i)
{
	if (str[i] == 0)
		i = 1;
	else
		while (str[i] && (str[i] == '$' || ft_isdigit(str[i]) == 1)
			&& str[i] != '0')
			i++;
	while (str[i] && (ft_isdigit(str[i]) || ft_strchr("# 0'-+.*", str[i])))
		i++;
	while (str[i] && ft_strchr("zjhlLE", str[i]) != NULL)
		i++;
	return (i);
}

/*
**		check if current segment is a syntax
*/

int		ft_issyntax(char *s, size_t len)
{
	int		i;
	char	*str;

	i = 1;
	if (s[0] != '%' || (s[0] == '%' && s[1] == '%'))
		return (0);
	str = ft_strndup(s, len);
	while (str[i] && str[i] != '$')
		i++;
	if (str[i] == '$' && str[i - 1] == '%')
		return (ft_freestr_return_no(&str));
	if (i != 0 && str[i - 1] == '0')
		return (ft_freestr_return_no(&str));
	i = ft_iterate_syntax(str, i);
	if (str[i] && ft_strchr("diouxXcfspOUBb", str[i]) != NULL)
	{
		if (ft_strchr("cs", str[i]) && str[i - 1] == 'l')
		{
			free(str);
			return (0);
		}
		free(str);
		return (1);
	}
	return (ft_freestr_return_no(&str));
}
