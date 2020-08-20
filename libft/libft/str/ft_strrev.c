/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 04:32:32 by tpacaud           #+#    #+#             */
/*   Updated: 2018/11/11 04:35:57 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrev(char const *str)
{
	int		i;
	int		y;
	char	*ret;

	i = 0;
	y = ft_strlen(str) - 1;
	ret = NULL;
	while (y >= 0)
		ret[i++] = str[y--];
	ret[i] = 0;
	return (ret);
}
