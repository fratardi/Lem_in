/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 02:01:00 by fratardi          #+#    #+#             */
/*   Updated: 2018/11/25 03:19:41 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int h;
	int n;

	h = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[h])
	{
		n = 0;
		while (haystack[h] == needle[n])
		{
			h++;
			n++;
			if (!needle[n])
				return ((char *)haystack + h - n);
		}
		h = h - n;
		h++;
	}
	return (0x00000000);
}
