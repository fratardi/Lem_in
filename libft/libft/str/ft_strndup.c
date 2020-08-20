/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 06:39:55 by fratardi          #+#    #+#             */
/*   Updated: 2019/03/18 16:00:44 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	char	*rez;

	if (!(rez = (char *)ft_memalloc(sizeof(char) * n + 1)))
		return (NULL);
	ft_strncpy(rez, s1, n);
	return (rez);
}
