/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_addstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 04:27:12 by fratardi          #+#    #+#             */
/*   Updated: 2019/06/20 18:18:00 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_addstrings_stack(char *assign, char *base, int po_assig, int po_base)
{
	if (po_assig < 0 || po_base < 0)
		return ;
	po_assig -= (!assign[po_assig]) ? 1 : 0;
	po_base -= (!base[po_base]) ? 1 : 0;
	if ((((assign[po_assig]) - '0' + (base[po_base] - '0')) <= 9))
	{
		assign[po_assig] = assign[po_assig] + (base[po_base] - '0');
		ft_addstrings_stack(assign, base, --po_assig, --po_base);
	}
	else
	{
		assign[po_assig] = assign[po_assig] + base[po_base] - 10 - '0';
		assign[po_assig - 1]++;
		ft_addstrings_stack(assign, base, --po_assig, --po_base);
	}
	return ;
}

char	*ft_new_addstrings(char *s1, char *s2)
{
	int		s1p;
	int		s2p;
	int		y;
	char	diff;
	char	*ret;

	s1p = ft_strlen(s1);
	s2p = ft_strlen(s2);
	ret = s1;
	diff = 0;
	y = (s1p >= s2p) ? s1p : s2p;
	while (s1p-- && s2p-- && y--)
		diff = ft_addchar(&s1[s1p], &s2[s2p], &ret[y], diff);
	ret = (y == 0 && diff) ? ft_joinfree(ft_strdup("1"), ret) : ret;
	if (y == 0)
		return (ret);
	s2p--;
	y -= (s2p) ? 1 : 0;
	while (s1p >= 0 || s2p >= 0)
		diff = ft_addchar("0", (s1p >= 0) ? &s1[s1p--] : &s2[s2p--],
		&ret[y--], diff);
	ret = (diff) ? ft_joinfree(ft_strdup("1"), ret) : ret;
	return (ret);
}
