/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:24:52 by fratardi          #+#    #+#             */
/*   Updated: 2018/11/21 22:16:18 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)dst;
	i = 0;
	while (src[i] && len > 0)
	{
		tmp[i] = (char)src[i];
		i++;
		len--;
	}
	while (len)
	{
		tmp[i] = 0x00;
		i++;
		len--;
	}
	return (dst);
}
