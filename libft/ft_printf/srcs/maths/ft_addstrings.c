/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstrings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:31:12 by tpacaud           #+#    #+#             */
/*   Updated: 2019/06/20 18:17:46 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/*
**Function that add 2 char
*/

char	ft_addchar(char *s1, char *s2, char *ret, char carry)
{
	if (*s1 + *s2 + carry - (2 * '0') <= 9)
	{
		*ret = *s1 + *s2 + carry - '0';
		return (0);
	}
	*ret = (*s1 + *s2) + carry - 10 - '0';
	return (1);
}

/*
**Function that add 2 strings
*/

char	*ft_addstrings(char *s1, char *s2)
{
	int		s1p;
	int		s2p;
	int		y;
	char	diff;
	char	*ret;

	s1p = ft_strlen(s1);
	s2p = ft_strlen(s2);
	if (!(ret = (char *)ft_memalloc((s1p >= s2p) ? s1p + 1 : s2p + 1)))
		return (NULL);
	ft_memset(ret, '0', (s1p >= s2p) ? s1p - 1 : s2p - 1);
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
