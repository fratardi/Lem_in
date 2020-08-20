/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:58:59 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/13 06:57:00 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>
#include <stdlib.h>

char			*ft_cut_next_line(char *str)
{
	static int		i = 0;
	unsigned int	y;
	size_t			len;
	char			*line;

	y = 0;
	if (!str || !str[i])
		return (NULL);
	len = ft_line_len(str, i);
	if (!len)
		return (NULL);
	if (!(line = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		exit(1);
	ft_bzero(line, len + 1);
	while (y < len && str[i] && str[i] != '\n')
		line[y++] = str[i++];
	i++;
	return (line);
}

char			*ft_read_file(void)
{
	char			*str;
	unsigned int	readed;
	char			buf[BUFF_RSIZE + 1];

	str = NULL;
	ft_bzero(buf, BUFF_RSIZE + 1);
	if ((readed = read(0, buf, BUFF_RSIZE)) > 0)
	{
		if (!is_conform(buf))
			return (0);
		str = ft_strndup(buf, readed + 1);
	}
	ft_bzero(buf, BUFF_RSIZE);
	while (read(0, buf, BUFF_RSIZE) > 0)
	{
		if (!is_conform(buf) || ft_strlen(str) > 300000)
		{
			ft_strdel(&str);
			return (0);
		}
		if (!(str = join_left(str, buf)))
			exit(0);
		ft_bzero(buf, BUFF_RSIZE);
	}
	return (str);
}

t_lines			*ft_to_buf_file(void)
{
	t_lines	*start;
	t_lines *buf;
	char	*f;

	if (!(f = ft_read_file()))
		return (NULL);
	if (!(buf = (t_lines *)ft_memalloc(sizeof(t_lines))))
		exit(1);
	buf->next = NULL;
	start = buf;
	while ((buf->line = ft_cut_next_line(f)))
	{
		if (!(buf->next = (t_lines *)ft_memalloc(sizeof(t_lines))))
			exit(1);
		buf = buf->next;
		buf->next = NULL;
	}
	free(f);
	return (start);
}
