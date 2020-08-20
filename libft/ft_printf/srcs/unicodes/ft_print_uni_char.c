/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uni_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:42:32 by fratardi          #+#    #+#             */
/*   Updated: 2019/06/24 04:46:45 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../includes/ft_printf.h"

size_t	ft_print_uni_char(char *str)
{
	size_t	ret;

	ret = ft_uni_char_len(str);
	if (ret)
		write(1, str, ret);
	return (ret);
}
