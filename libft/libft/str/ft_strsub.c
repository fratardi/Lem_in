/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:05:01 by fratardi          #+#    #+#             */
/*   Updated: 2018/11/27 07:44:17 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*rez;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(rez = (char *)ft_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[start + i] && len != i)
	{
		rez[i] = (char)s[start + i];
		i++;
	}
	return (rez);
}
