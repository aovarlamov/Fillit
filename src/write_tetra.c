/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_tetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 23:04:31 by bdrinkin          #+#    #+#             */
/*   Updated: 2019/12/17 20:15:41 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			first_check(char tetra[4][5])
{
	int		i;
	int		j;
	int		r_count;

	r_count = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetra[i][j] != '.' && tetra[i][j] != '#')
				break ;
			if (tetra[i][j] == '#')
				r_count++;
			j++;
		}
		if (tetra[i][j] == '\n')
			i++;
		else
			return (0);
	}
	if (r_count != 4)
		return (0);
	return (1);
}

int			second_check(char tetra[4][5], int (*cord)[8])
{
	char	*char_cord;

	char_cord = ft_strnew(8);
	write_cord(tetra, cord);
	change_cord(cord);
	cord_to_char(char_cord, *cord);
	if ((ft_strcmp(char_cord, I_T) != 0 && ft_strcmp(char_cord, IH_T) != 0 &&
		ft_strcmp(char_cord, O_T) != 0 && ft_strcmp(char_cord, LR_T) != 0 &&
		ft_strcmp(char_cord, L_T) != 0 && ft_strcmp(char_cord, LL_T) != 0 &&
		ft_strcmp(char_cord, ZR_T) != 0 && ft_strcmp(char_cord, LD_T) != 0 &&
		ft_strcmp(char_cord, Z_T) != 0 && ft_strcmp(char_cord, J_T) != 0 &&
		ft_strcmp(char_cord, SR_T) != 0 && ft_strcmp(char_cord, JR_T) != 0 &&
		ft_strcmp(char_cord, S_T) != 0 && ft_strcmp(char_cord, JD_T) != 0 &&
		ft_strcmp(char_cord, TL_T) != 0 && ft_strcmp(char_cord, JL_T) != 0 &&
		ft_strcmp(char_cord, TD_T) != 0 && ft_strcmp(char_cord, T_T) != 0 &&
		ft_strcmp(char_cord, TR_T) != 0))
	{
		ft_strdel(&char_cord);
		return (0);
	}
	ft_strdel(&char_cord);
	return (1);
}

int			read_file(int fd, char (*tetra)[4][5], int *check)
{
	int		rt;
	int		i;
	char	n;

	i = 0;
	*check = 0;
	while (i < 4)
	{
		rt = read(fd, (*tetra)[i], 5);
		i++;
		*check += rt;
	}
	rt = read(fd, &n, 1);
	if (n == '\n' || rt == 0)
		return (1);
	else
		return (0);
}

int			write_tetra(int fd, t_tetris **tets)
{
	char	tetra[4][5];
	int		cord[8];
	int		check;

	while ((read_file(fd, &tetra, &check)))
	{
		if (check == 0)
			return (1);
		else if (check != 20)
			return (0);
		if (first_check(tetra))
		{
			if (second_check(tetra, &cord))
				go_to_list(&(*tets), cord);
			else
				return (0);
		}
		else
			return (0);
	}
	return (0);
}
