/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 01:14:36 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/03 13:09:43 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rez;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	j = ft_strlen(s1);
	i = ft_strlen(s2);
	if (!(rez = (char *)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	rez = ft_strcpy(rez, s1);
	rez = ft_strcat(rez, s2);
	return (rez);
}
