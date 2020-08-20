/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 22:13:24 by bdrinkin          #+#    #+#             */
/*   Updated: 2019/11/04 23:06:12 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	long	i;
	int		convert;

	i = 0;
	convert = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		(*str == '-') ? convert = -1 : 1;
		str++;
		if (*str == '+' || *str == '-')
			return (0);
	}
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		i = 10 * i + *str - '0';
		str++;
	}
	return (convert * (int)i);
}
