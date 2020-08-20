/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_the_pow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 14:36:31 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/03 14:37:57 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long double	ft_to_the_pow(long double pow, long double val)
{
	if (pow == 0.0F)
		return (1.0F);
	while (pow > 1.0F)
	{
		val *= val;
		pow -= 1.0F;
	}
	return (val);
}
