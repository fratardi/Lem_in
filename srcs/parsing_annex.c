/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_annex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:16:06 by tpacaud           #+#    #+#             */
/*   Updated: 2020/04/30 12:12:17 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

/*
** in case of /dev/random
*/

int				is_conform(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (!ft_isascii(str[i++]))
			return (0);
	}
	return (1);
}

char			*join_left(char *s1, char *s2)
{
	char *tmp;

	if (!(tmp = ft_memalloc(sizeof(char) *
			(ft_strlen(s1) + ft_strlen(s2) + 2))))
		exit(1);
	tmp = ft_strcpy(tmp, s1);
	tmp = ft_strcat(tmp, s2);
	ft_strdel(&s1);
	return (tmp);
}

size_t			ft_line_len(char *str, size_t i)
{
	size_t ret;

	ret = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
		ret++;
	}
	return (ret);
}
