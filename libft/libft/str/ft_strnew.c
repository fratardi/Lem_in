/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:06:32 by fratardi          #+#    #+#             */
/*   Updated: 2019/05/18 04:10:10 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char		*rez;

	if (!(rez = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	ft_bzero(rez, size + 1);
	return (rez);
}
