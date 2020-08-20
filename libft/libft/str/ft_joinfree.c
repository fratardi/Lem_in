/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joinfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 18:48:43 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/05 23:53:55 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_joinfree(char *s1, char *s2)
{
	char *ret;

	if (!s1)
		return ((s2) ? s2 : NULL);
	if (!s2)
		return (s1);
	ret = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ret);
}
