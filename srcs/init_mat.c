/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 14:45:02 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/12 21:35:18 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

t_lines			*init_mat(t_lines *buf, t_room *rooms, unsigned char **matrice)
{
	unsigned int	i;
	char			*l1;
	char			*l2;

	i = 0;
	while (buf->line[i] && buf->line[i] != '-' &&
			!ft_strchr("L#", buf->line[i]))
		i++;
	if (!buf->line[i] || ft_strchr("L#", buf->line[i]))
	{
		free_matrice(matrice, ft_matr_size(matrice));
		ft_printf("ERROR\n");
		exit(1);
	}
	l1 = ft_strndup(buf->line, i);
	i += 1;
	l2 = ft_strdup(&buf->line[i]);
	if (ft_strchr(l2, '#') || ft_strchr(l2, 'L'))
		return (NULL);
	fill_bool_map(matrice, l1, l2, rooms);
	buf = buf->next;
	while (buf->next && buf->line[0] == '#')
		buf = buf->next;
	return (buf);
}

void			print_buf(t_lines *buf)
{
	while (buf->next)
	{
		ft_printf("%s\n", buf->line);
		buf = buf->next;
	}
	ft_printf("\n");
}
