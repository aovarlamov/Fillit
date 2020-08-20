/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 01:10:04 by bdrinkin          #+#    #+#             */
/*   Updated: 2019/12/15 17:06:43 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int	i;

	if (nb < 1)
		return (0);
	i = 1;
	while (i * i < nb)
	{
		i++;
	}
	return (i);
}

int		errors(int error)
{
	if (error == 1)
	{
		write(1, "usage: fillit source_file\n", 27);
		return (0);
	}
	if (error == 2)
	{
		write(1, "error\n", 6);
		return (0);
	}
	return (0);
}

int		ft_min_map(t_tetris *tets)
{
	while (tets->next)
		tets = tets->next;
	return (ft_sqrt(((tets->num)) * 4));
}

int		count_tets(t_tetris *tets)
{
	int	i;

	i = 1;
	while (tets->next)
	{
		i++;
		tets = tets->next;
	}
	return (i);
}
