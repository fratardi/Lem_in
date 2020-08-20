/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:57:18 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/03 13:03:23 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*rez;

	if (!(rez = (void *)malloc(size)))
		return (NULL);
	ft_bzero(rez, size);
	return (rez);
}
