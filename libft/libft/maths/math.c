/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:02:48 by fratardi          #+#    #+#             */
/*   Updated: 2020/05/03 14:43:02 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long double	ft_factorial_of(long double value)
{
	return (value >= 1.0F ? value * ft_factorial_of(value - 1.0F) : 1.0F);
}

long double	ft_expo_of(long double value, long double depth)
{
	long double ret;
	long double start;

	start = 1.0f;
	ret = 1.0f;
	while (start < depth)
	{
		ret += (value * value) / ft_factorial_of(start);
		value = value * value;
		start = start + 1;
	}
	return (ret);
}

long double	ft_pi(void)
{
	long double ret;
	long double start;
	long double mod;

	mod = 1.0F;
	ret = 0.0F;
	start = 0.0F;
	while (start < 12)
	{
		ret = ret + ((1.0F / (mod)) *
		(
			(4.0F / ((8.0F * start) + 1.0F))
			- (2.0F / ((8.0F * start) + 4.0F))
			- (1.0F / ((8.0F * start) + 5.0F))
			- (1.0F / ((8.0F * start) + 6.0F))));
		mod *= 16.0F;
		start += 1.0F;
	}
	return (ret);
}

long double	ft_riemann(long double zeta_of, long double n)
{
	long double ret;
	long double start;

	start = 1.0F;
	ret = 0.0F;
	while (n > 0.0F)
	{
		ret += (1.0F / (ft_to_the_pow(zeta_of, start)));
		n -= 1.0F;
		start += 1.0F;
	}
	return (ret);
}

long double	ft_fib(long double n)
{
	return (n <= 1.0F ? n : ft_fib(n - 2.0F) + ft_fib(n - 1.0F));
}
