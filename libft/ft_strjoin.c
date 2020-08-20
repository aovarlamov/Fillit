/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 13:17:31 by bdrinkin          #+#    #+#             */
/*   Updated: 2019/11/16 18:42:52 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ss;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(ss = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	i = 0;
	while (*s1)
		ss[i++] = *s1++;
	while (*s2)
		ss[i++] = *s2++;
	return (ss);
}
