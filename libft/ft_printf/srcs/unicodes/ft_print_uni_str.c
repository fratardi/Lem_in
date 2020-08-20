/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uni_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:45:46 by fratardi          #+#    #+#             */
/*   Updated: 2019/06/24 04:46:31 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <unistd.h>

size_t	ft_print_uni_str(char *str)
{
	size_t ret;

	if (!str)
		return (0);
	ret = ft_uni_str_len(str);
	if (ret)
		write(1, str, ret);
	return (ret);
}

int		ft_print_n_uni_str(char *str, int size)
{
	int ret;

	if (!str)
	{
		ft_print_n_uni_str("(null)", (size == 0) ? 6 : size);
		return (size == 0 ? 6 : size);
	}
	if (size < 0)
		return (0);
	ret = ft_uni_str_len(str);
	if (size == 0)
		size = (int)ret;
	if (ret)
		write(1, str, (ret >= size) ? size : ret);
	return (ret >= size ? size : ret);
}
