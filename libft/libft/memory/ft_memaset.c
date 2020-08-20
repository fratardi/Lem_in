/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memaset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 21:38:40 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/09 21:39:03 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memaset(int c, size_t n)
{
	unsigned char *ret;

	if (!(ret = (unsigned char *)ft_memalloc(n + 1)) || n == 0)
		return (NULL);
	return (ret = ft_memset(ret, c, n));
}
