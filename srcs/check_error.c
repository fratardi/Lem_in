/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:07:26 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/12 21:42:42 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>

int			check_first(char *str, size_t readed)
{
	size_t	i;

	i = 0;
	if (readed < 1)
		return (0);
	while (i < readed && ft_isdigit(str[i]))
		i++;
	if (i > 10 || (i == 10 && str[0] > '2'))
		return (0);
	if (i <= readed && str[i] == '\0')
		return ((ft_atoi(str)) > 0 ? ft_atoi(str) : 0);
	return (0);
}

/*
**	check the content of each line
*/

int			is_instruction(char *str)
{
	if (!str)
		return (0);
	if (ft_strlen(str) == 7 && !ft_strncmp(str, "##start", 7))
		return (1);
	if (ft_strlen(str) == 5 && !ft_strncmp(str, "##end", 5))
		return (2);
	if (str[0] == '#')
		return (0);
	return (0);
}

int			is_third_part(char *str)
{
	size_t i;
	size_t nb_d;

	i = 0;
	nb_d = 1;
	while (str[i] && (str[i] == '-' || ft_isdigit(str[i])))
	{
		if (str[i] == '-')
			nb_d++;
		i++;
	}
	if (!str[i] && nb_d == 2)
		return (1);
	return (0);
}

int			check_last(t_lines *buf)
{
	size_t link;

	link = 0;
	while (buf->line && (!ft_strchr(buf->line, '-')))
		buf = buf->next;
	while (buf->next && is_third_part(buf->line))
	{
		link++;
		buf = buf->next;
		if (buf->next && is_instruction(buf->line))
			buf = buf->next;
	}
	return (link);
}
