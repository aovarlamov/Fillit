/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 23:14:07 by bdrinkin          #+#    #+#             */
/*   Updated: 2019/12/17 20:22:49 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				right_shift(t_tetris **tets_r, int num, int mm)
{
	t_tetris	*temp;

	temp = *tets_r;
	while ((temp)->num != num)
		temp = (temp)->next;
	if ((temp)->cord[0] != mm && (temp)->cord[2] != mm &&
		(temp)->cord[4] != mm && (temp)->cord[6] != mm)
	{
		(temp)->cord[0] += 1;
		(temp)->cord[2] += 1;
		(temp)->cord[4] += 1;
		(temp)->cord[6] += 1;
		return (1);
	}
	else
		return (0);
}

int				down_shift(t_tetris **tets_r, int num, int mm)
{
	t_tetris	*temp;

	temp = *tets_r;
	while ((temp)->num != num)
		temp = (temp)->next;
	if ((temp)->cord[1] != mm && (temp)->cord[3] != mm &&
		(temp)->cord[5] != mm && (temp)->cord[7] != mm)
	{
		while ((temp)->cord[0] != 0 && (temp)->cord[2] != 0 &&
				(temp)->cord[4] != 0 && (temp)->cord[6] != 0)
		{
			(temp)->cord[0] -= 1;
			(temp)->cord[2] -= 1;
			(temp)->cord[4] -= 1;
			(temp)->cord[6] -= 1;
		}
		(temp)->cord[1] += 1;
		(temp)->cord[3] += 1;
		(temp)->cord[5] += 1;
		(temp)->cord[7] += 1;
		return (1);
	}
	else
		return (0);
}

void			return_shift(t_tetris **tets_r, int num)
{
	t_tetris	*temp;

	temp = *tets_r;
	while ((temp)->num != num)
		temp = (temp)->next;
	while ((temp)->cord[0] != 0 && (temp)->cord[2] != 0 &&
			(temp)->cord[4] != 0 && (temp)->cord[6] != 0)
	{
		(temp)->cord[0] -= 1;
		(temp)->cord[2] -= 1;
		(temp)->cord[4] -= 1;
		(temp)->cord[6] -= 1;
	}
	while ((temp)->cord[1] != 0 && (temp)->cord[3] != 0 &&
			(temp)->cord[5] != 0 && (temp)->cord[7] != 0)
	{
		(temp)->cord[1] -= 1;
		(temp)->cord[3] -= 1;
		(temp)->cord[5] -= 1;
		(temp)->cord[7] -= 1;
	}
}

int				while_temp(t_tetris *temp1, t_tetris *temp, int num)
{
	int			i;
	int			j;

	while ((temp1->num != num))
	{
		i = 0;
		while (i < 7)
		{
			j = 0;
			while (j < 7)
			{
				if (temp->cord[i] == temp1->cord[j] &&
					temp->cord[i + 1] == temp1->cord[j + 1])
					return (1);
				j += 2;
			}
			i += 2;
		}
		temp1 = temp1->next;
	}
	return (0);
}

int				check_shift(t_tetris *tets_r, int num)
{
	t_tetris	*temp;
	t_tetris	*temp1;
	t_tetris	*tempch;

	temp = tets_r;
	temp1 = ft_tetcpy(tets_r);
	tempch = temp1;
	while ((temp)->num != num)
		temp = (temp)->next;
	if (while_temp(temp1, temp, num))
	{
		ft_tetdel(&tempch);
		return (1);
	}
	else
		ft_tetdel(&tempch);
	return (0);
}
