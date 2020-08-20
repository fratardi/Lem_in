/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaybin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:48:41 by fratardi          #+#    #+#             */
/*   Updated: 2019/06/20 18:17:21 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**Display Binary Content
*/

void	ft_displaybin(void *content, size_t n)
{
	unsigned char	*tmp;
	unsigned int	mask;

	tmp = (unsigned char *)content + n - 1;
	while (n--)
	{
		mask = 0x100;
		while ((mask = mask >> 1))
			(*tmp & mask) ? ft_putchar('1') : ft_putchar('0');
		tmp--;
	}
}

char	*ft_binary(void *content, size_t n)
{
	unsigned char	*tmp;
	unsigned int	mask;
	char			*str;

	str = ft_memaset(0, 1);
	tmp = (unsigned char *)content + n - 1;
	while (n--)
	{
		mask = 0x100;
		while ((mask = mask >> 1))
			str = ft_joinfree(str, ft_strdup((*tmp & mask) ? "1" : "0"));
		tmp--;
	}
	return (str);
}

char	*ft_binary_string(void *content, size_t n)
{
	unsigned char	*tmp;
	unsigned int	mask;
	char			*str;

	str = ft_memaset(0, 1);
	tmp = (unsigned char *)content + n - 1;
	while (n--)
	{
		mask = 0x100;
		while ((mask = mask >> 1))
			str = ft_joinfree(str, ft_strdup((*tmp & mask) ? "1" : "0"));
		tmp--;
	}
	return (str);
	return (str);
}
