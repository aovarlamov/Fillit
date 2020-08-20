/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:38:50 by bdrinkin          #+#    #+#             */
/*   Updated: 2019/12/15 16:55:34 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_map(int mm, char tetramino[106][106])
{
	char	c;
	int		l;
	int		m;

	l = 0;
	m = 0;
	while (l < mm)
	{
		while (m < mm)
		{
			c = tetramino[l][m];
			ft_putchar(c);
			m++;
		}
		ft_putchar('\n');
		m = 0;
		l++;
	}
}

void		ft_dots(int mm, char map[106][106])
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < mm)
	{
		while (x < mm)
		{
			map[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
}

void		write_map(t_tetris *tetra, int mm)
{
	char	map[106][106];
	char	letter;

	ft_dots(mm, map);
	while (tetra)
	{
		letter = tetra->letter;
		map[tetra->cord[1]][tetra->cord[0]] = tetra->letter;
		map[tetra->cord[3]][tetra->cord[2]] = tetra->letter;
		map[tetra->cord[5]][tetra->cord[4]] = tetra->letter;
		map[tetra->cord[7]][tetra->cord[6]] = tetra->letter;
		tetra = tetra->next;
	}
	print_map(mm, map);
}
