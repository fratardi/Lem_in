/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 22:50:29 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/03 13:13:31 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static size_t		ft_spacefront(char *str)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	while (str[i] && ft_isspace(str[i]))
	{
		i++;
		k++;
	}
	return (k);
}

static size_t		ft_spaceend(char *str)
{
	size_t i;
	size_t k;

	i = ft_strlen(str) - 1;
	k = 0;
	while (i > 0 && ft_isspace(str[i]) && str[i])
	{
		i--;
		k++;
	}
	return (k);
}

char				*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	k;
	char	*rez;

	i = 0;
	if (!s || !*s)
		return ("\0");
	k = ft_strlen(s) - (ft_spacefront((char*)s) + ft_spaceend((char*)s));
	if (ft_strlen(s) == ft_spacefront((char *)s))
	{
		if (!(rez = (char *)malloc(sizeof(char) * 1)))
			return (NULL);
		rez[0] = '\0';
		return (rez);
	}
	if (!(rez = (char *)ft_memalloc(sizeof(char) * k + 1)))
		return (NULL);
	k = 0;
	while (ft_isspace(s[k]))
		k++;
	while (k < ft_strlen((char *)s) - ft_spaceend((char *)s))
		rez[i++] = (char)s[k++];
	return (rez);
}
