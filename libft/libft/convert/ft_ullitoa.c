/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 02:32:38 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/12 03:29:38 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int		ft_nblen(unsigned long long int nb)
{
	unsigned long long int	nbl;
	int						i;

	i = 0;
	nbl = nb;
	while ((nbl / 10) > 0)
	{
		i++;
		nbl = nbl / 10;
	}
	return (i + 1);
}

char			*ft_ullitoa(unsigned long long int n)
{
	char					*rez;
	unsigned long long int	nbl;
	long long int			i;

	nbl = n;
	i = 0;
	if (nbl == 0)
		return (ft_strdup("0"));
	if (!(rez = (char*)ft_memalloc((sizeof(char) * ft_nblen(nbl) + 1))))
		return (NULL);
	i = ft_nblen(nbl) - 1;
	rez[i] = '\0';
	while (i >= 0)
	{
		rez[i] = nbl % 10 + '0';
		i--;
		nbl = nbl / 10;
	}
	return (rez);
}
