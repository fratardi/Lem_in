/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_content_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 03:03:21 by tpacaud           #+#    #+#             */
/*   Updated: 2019/08/11 21:56:17 by tpacaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <unistd.h>

size_t		ft_display_char_content(void *content, size_t len)
{
	unsigned char	*tmp;
	int				ret;

	tmp = (unsigned char *)content;
	ret = (int)len;
	while (ret > 0)
	{
		write(1, tmp, (ret < BUFF_SIZE) ? ret : BUFF_SIZE);
		tmp += BUFF_SIZE;
		ret -= BUFF_SIZE;
	}
	return (len);
}
