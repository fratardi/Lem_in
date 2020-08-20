/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annex_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:05:06 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/26 00:04:31 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_hexfloat(void *content, size_t n)
{
	static char tab[16] = "0123456789abcdef";
	char		*str;

	str = (char *)content;
	ft_putstr("0x");
	while (0 < n--)
	{
		ft_putchar(tab[((unsigned char)str[n] / 16)]);
		ft_putchar(tab[((unsigned char)str[n] % 16)]);
	}
}

size_t	digitlen(unsigned long long int i)
{
	size_t ret;

	ret = 0;
	while (i)
	{
		i = i / 10;
		ret++;
	}
	return (ret);
}

/*
**Get binary mantissa from long double
*/

char	*ft_mantissaldouble(long double d)
{
	char	*temp;
	char	*f;

	temp = ft_binary(&d, 10);
	f = ft_strdup(&temp[16]);
	free(temp);
	return (f);
}

/*
**Get exp from long double
*/

int		ft_expldouble(long double a)
{
	char	*exp_bin;
	int		ret;

	ret = 0;
	exp_bin = ft_binary(&a, 10);
	exp_bin[16] = 0;
	ret = ft_binary_exopnent(&exp_bin[1]);
	free(exp_bin);
	return (ret - 16383);
}

int		ft_binary_exopnent(char *bin)
{
	int ret;
	int i;
	int mask;

	mask = 0x00000001;
	ret = 0;
	i = 14;
	if (!bin)
		return (ret);
	while (i >= 0)
	{
		if (bin[i--] == '1')
			ret = (ret | mask);
		mask = mask << 1;
	}
	return (ret);
}
