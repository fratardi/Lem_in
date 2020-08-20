/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:48:33 by fratardi          #+#    #+#             */
/*   Updated: 2018/11/29 09:00:51 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	rez;
	int	sig;

	i = 0;
	rez = 0;
	sig = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -sig;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		rez = ((rez * 10) - (str[i++] - '0'));
	if ((rez > 0 && sig < 0) || rez == 0)
		return (0);
	return ((rez * -sig));
}
