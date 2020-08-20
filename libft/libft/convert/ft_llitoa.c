/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 02:32:38 by fratardi          #+#    #+#             */
/*   Updated: 2019/06/05 02:00:57 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static char		*ft_join_free_s(char *s1, char *s2)
{
	char *ret;

	if (!s1)
		return ((s2) ? s2 : NULL);
	if (!s2)
		return (s1);
	ret = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ret);
}

static	int		ft_nblen(long long int nb)
{
	long int	nbl;
	int			i;

	i = 0;
	nbl = nb;
	if (nbl < 0)
	{
		i = i + 1;
		nbl = -nbl;
	}
	while ((nbl / 10) > 0)
	{
		i++;
		nbl = nbl / 10;
	}
	return (i + 1);
}

char			*ft_llitoa(long long int n)
{
	char					*rez;
	unsigned long long int	temp;
	long long int			nbl;
	long long int			i;

	nbl = n;
	i = 0;
	if (nbl == 0)
		return (ft_strdup("0"));
	i = ft_nblen(nbl) - 1;
	if (nbl < 0)
	{
		temp = (unsigned long long int)-nbl;
		return (ft_join_free_s(ft_strdup("-"), ft_ullitoa(temp)));
	}
	if (!(rez = (char*)ft_memalloc((sizeof(char) * ft_nblen(nbl) + 1))))
		return (NULL);
	rez[i] = '\0';
	while (i >= 0)
	{
		rez[i--] = nbl % 10 + '0';
		nbl = nbl / 10;
	}
	rez[0] = (n < 0) ? '-' : rez[0];
	return (rez);
}
