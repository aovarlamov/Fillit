/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:01:24 by bdrinkin          #+#    #+#             */
/*   Updated: 2019/11/16 18:30:11 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	size_t	n;

	n = 0;
	while ((s1[n] != '\0') && (s2[n] != '\0') && (s1[n] == s2[n]))
	{
		n++;
	}
	if ((s1[n] == '\0') && (s2[n] == '\0'))
		return (0);
	else if ((s1[n] == '\0') && (s2[n] != '\0'))
		return (-1);
	else if ((s1[n] != '\0') && (s2[n] == '\0'))
		return (1);
	else
		return (s1[n] - s2[n]);
}
