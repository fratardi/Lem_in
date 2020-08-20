/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:47:36 by fratardi          #+#    #+#             */
/*   Updated: 2018/11/21 22:55:40 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr(int n)
{
	long int nbl;

	nbl = n;
	if (nbl < 0)
	{
		ft_putchar('-');
		nbl = -nbl;
	}
	if (nbl / 10 >= 1)
		ft_putnbr(nbl / 10);
	if (nbl % 10 <= 9)
		ft_putchar(nbl % 10 + '0');
}
