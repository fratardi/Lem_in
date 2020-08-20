/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lm_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:55:37 by fratardi          #+#    #+#             */
/*   Updated: 2020/04/30 14:55:46 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_print_matrice_line(unsigned char *matrice_line,
									unsigned int size)
{
	ft_putchar('[');
	ft_print_bits(matrice_line, size - 1);
	ft_putchar(']');
	if (is_room_linked_to_end(matrice_line, size))
		ft_putstr("🏁");
	if (is_room_linked_to_start(matrice_line))
		ft_putstr("🔚");
	ft_putstr("\n");
}

void		ft_print_matrice(unsigned char **matrice, char *name,
								unsigned int size)
{
	size_t i;

	i = 0;
	ft_printf("##### %s of size %zu #####\n", name, size);
	while (matrice[i] && !(ft_is_room_empty(matrice[i], size)) && i < size)
	{
		ft_print_bits(matrice[i], size - 1);
		if (is_room_linked_to_end(matrice[i], size))
			ft_putstr("🏁");
		if (is_room_linked_to_start(matrice[i]))
			ft_putstr("🔚");
		ft_putchar('\n');
		i++;
	}
	ft_printf("##### ___ %zu lines ___ #####\n", i);
}
