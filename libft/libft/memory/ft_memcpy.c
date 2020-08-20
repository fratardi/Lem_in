/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:19:33 by fratardi          #+#    #+#             */
/*   Updated: 2018/11/15 21:52:07 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (dst == (void *)n || src == (void *)n || dst == NULL)
		return (dst);
	while (n-- > 0)
		*((unsigned char *)dst + n) = *((unsigned char *)src + n);
	return (dst);
}
