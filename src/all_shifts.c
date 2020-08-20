/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_shifts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 16:48:16 by bdrinkin          #+#    #+#             */
/*   Updated: 2019/12/17 20:28:56 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				put_tetra(t_tetris **tets_r, int k, int min_map)
{
	while (check_shift(*tets_r, k + 1))
	{
		if (!(right_shift(&*tets_r, k + 1, min_map - 1)))
		{
			if (!(down_shift(&*tets_r, k + 1, min_map - 1)))
				return (0);
		}
	}
	return (1);
}

int				shifts_next(t_tetris **tets_r, int *k, int mp)
{
	if (!(right_shift(&*tets_r, *k, mp - 1)))
	{
		if (!(down_shift(&*tets_r, *k, mp - 1)))
		{
			return_shift(&*tets_r, *k);
			*k -= 1;
		}
		else if (!(check_shift(*tets_r, *k)))
		{
			*k -= 1;
			return (0);
		}
	}
	else if (!(check_shift(*tets_r, *k)))
	{
		*k -= 1;
		return (0);
	}
	return (1);
}

void			whiles_shift(t_tetris **tets_r, t_tetris *tets, int *mp, int c)
{
	int			k;

	k = 1;
	while (k < c)
	{
		if (!(put_tetra(&*tets_r, k, *mp)))
		{
			return_shift(&*tets_r, k + 1);
			while (k != 0)
			{
				if (!(shifts_next(&*tets_r, &k, *mp)))
					break ;
				if (k == 0)
				{
					ft_tetdel(&*tets_r);
					*tets_r = ft_tetcpy(tets);
					*mp += 1;
					k = 0;
					break ;
				}
			}
		}
		k++;
	}
}
