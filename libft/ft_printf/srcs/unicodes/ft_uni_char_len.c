/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_char_len.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:59:00 by fratardi          #+#    #+#             */
/*   Updated: 2019/06/20 18:19:00 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

size_t	ft_uni_char_len(char *str)
{
	if (!str | !*str)
		return (0);
	if ((*str & UNI1) == UNI1)
	{
		if ((*str & UNI2) == UNI2 && *(str + 1))
		{
			if ((*str & UNI3) == UNI3 && *(str + 2))
			{
				if ((*str & UNI4) == UNI4 && *(str + 3))
					return (4);
				return (3);
			}
			return (2);
		}
	}
	return (1);
}
