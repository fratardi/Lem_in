/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:12:51 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/03 13:05:28 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char			*rez;
	unsigned int	i;

	i = ft_strlen(s1) + 1;
	if (!(rez = (char *)malloc(sizeof(char ) * i)))
		return (NULL);
	return (ft_strncpy(rez, s1, i));
}
