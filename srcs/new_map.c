/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:25:24 by fratardi          #+#    #+#             */
/*   Updated: 2020/04/30 14:25:26 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>

void	ft_print_bits(void *data, unsigned int size)
{
	unsigned char	*area;
	unsigned int	pos;
	unsigned char	cursor;

	pos = 0;
	area = (unsigned char *)data;
	while (pos <= size)
	{
		cursor = 0x80;
		while (cursor && (pos <= size))
		{
			write(1, (cursor & *area) ? "1" : "0", 1);
			cursor >>= 1;
			pos++;
		}
		area++;
	}
}

void	ft_new_map(t_anthill *anthill)
{
	ft_print_bits(anthill->matrice[0], anthill->size);
}
