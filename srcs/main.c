/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:51:54 by tpacaud           #+#    #+#             */
/*   Updated: 2020/05/13 01:20:01 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>
#include <stdlib.h>

int				main(void)
{
	t_anthill	anthill;

	if (!ft_init_anthill_parse(&anthill))
		exit(!ft_printf("ERROR\n"));
	if (!(generate_flow_sets(&anthill)))
	{
		free_buf(anthill.read);
		exit(!ft_printf("ERROR\n"));
	}
	print_buf(anthill.read);
	free_buf(anthill.read);
	send_ants(&anthill);
	free_anthill(&anthill);
	return (0);
}
