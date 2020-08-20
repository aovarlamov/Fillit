/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_cord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 23:46:13 by bdrinkin          #+#    #+#             */
/*   Updated: 2019/12/09 01:19:26 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		cord_to_char(char *char_cord, int cord[8])
{
	int		i;

	i = 0;
	while (i < 8)
	{
		char_cord[i] = cord[i] + '0';
		i++;
	}
}

void		change_cord(int (*cord)[8])
{
	while (1)
	{
		if ((*cord)[0] == 0 || (*cord)[2] == 0 || (*cord)[4] == 0
				|| (*cord)[6] == 0)
			break ;
		(*cord)[0] -= 1;
		(*cord)[2] -= 1;
		(*cord)[4] -= 1;
		(*cord)[6] -= 1;
	}
	while (1)
	{
		if ((*cord)[1] == 0 || (*cord)[3] == 0 || (*cord)[5] == 0
				|| (*cord)[7] == 0)
			break ;
		(*cord)[1] -= 1;
		(*cord)[3] -= 1;
		(*cord)[5] -= 1;
		(*cord)[7] -= 1;
	}
}

int			write_cord(char tetra[4][5], int (*cord)[8])
{
	int		i;
	int		j;
	int		n_cord;

	n_cord = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetra[i][j] == '#')
			{
				(*cord)[n_cord] = j;
				n_cord++;
				(*cord)[n_cord] = i;
				n_cord++;
			}
			j++;
		}
		i++;
	}
	return (0);
}
