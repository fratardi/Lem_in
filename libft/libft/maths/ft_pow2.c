/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:05:30 by tpacaud           #+#    #+#             */
/*   Updated: 2019/04/15 18:21:31 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long int	ft_pow2(unsigned int i)
{
	return ((i == 0) ? 1 : (0x00000001 << i));
}