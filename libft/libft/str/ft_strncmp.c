/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 00:04:36 by fratardi          #+#    #+#             */
/*   Updated: 2018/11/25 02:41:06 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (*(unsigned char*)(s1 + i) || *(unsigned char *)(s2 + i)))
	{
		if (*(unsigned char*)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char*)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}
