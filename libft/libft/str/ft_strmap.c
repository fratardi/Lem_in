/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:17:07 by fratardi          #+#    #+#             */
/*   Updated: 2018/11/30 15:23:18 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*rez;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(rez = ft_strdup(s)))
		return (NULL);
	while (i < ft_strlen(rez))
	{
		rez[i] = (*f)(rez[i]);
		i++;
	}
	return (rez);
}
