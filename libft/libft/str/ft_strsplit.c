/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 02:35:53 by fratardi          #+#    #+#             */
/*   Updated: 2018/11/25 02:28:54 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		wordnb(const char *str, char c)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			j++;
		while (str[i] != c && str[i] != '\0')
		{
			i++;
		}
		i++;
	}
	return (j);
}

static int		ft_wl(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**rez;
	int		i;
	int		j;
	void	*(*f)(size_t);

	f = &ft_memalloc;
	i = 0;
	if ((!s || !c) || (!(rez = (char **)f(sizeof(char*) * (wordnb(s, c) + 1)))))
		return (NULL);
	j = 0;
	while (j < wordnb(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			if (!(rez[j] = (char*)f(sizeof(char) * (ft_wl(s + i, c) + 1))))
				return (NULL);
			ft_strncpy(rez[j], s + i, (size_t)ft_wl(s + i, c));
		}
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	return (rez);
}
