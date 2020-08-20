/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:07:23 by fratardi          #+#    #+#             */
/*   Updated: 2018/11/21 22:55:28 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int nbl;

	nbl = n;
	if (nbl < 0)
	{
		ft_putchar_fd('-', fd);
		nbl = -nbl;
	}
	if (nbl / 10 >= 1)
		ft_putnbr_fd(nbl / 10, fd);
	if (nbl % 10 <= 9)
		ft_putchar_fd(nbl % 10 + '0', fd);
}
