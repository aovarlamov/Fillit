/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:52:52 by bdrinkin          #+#    #+#             */
/*   Updated: 2019/11/04 23:09:00 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t d, size_t s)
{
	if (d < s)
		return (d);
	else
		return (s);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		d_len;
	size_t		s_len;

	s_len = ft_strlen(src);
	d_len = ft_min(ft_strlen(dst), size);
	if (s_len < size - d_len)
		ft_strncat(dst, src, s_len + 1);
	else if (size > d_len)
	{
		ft_strncat(dst, src, size - d_len - 1);
		dst[size - 1] = '\0';
	}
	return (d_len + s_len);
}
