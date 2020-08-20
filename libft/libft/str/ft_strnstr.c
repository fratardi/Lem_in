/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:31:08 by fratardi          #+#    #+#             */
/*   Updated: 2018/11/27 09:17:07 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;

	if (!*haystack)
		return (NULL);
	if (!*needle || needle == haystack)
		return ((char *)haystack);
	h = 0;
	while (haystack[h] && h + ft_strlen(needle) <= len)
	{
		if (!ft_strncmp(&haystack[h], needle, ft_strlen(needle)))
			return ((char *)haystack + h);
		h++;
	}
	return (NULL);
}
