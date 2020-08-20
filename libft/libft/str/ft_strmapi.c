/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:25:36 by fratardi          #+#    #+#             */
/*   Updated: 2018/11/30 15:25:11 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*rez;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(rez = ft_strdup(s)))
		return (NULL);
	while (i < ft_strlen(s))
	{
		rez[i] = (*f)(i, rez[i]);
		i++;
	}
	return (rez);
}
