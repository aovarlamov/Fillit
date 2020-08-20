/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:25:32 by kbethel           #+#    #+#             */
/*   Updated: 2019/12/17 20:31:59 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			check_map(t_tetris *tets_r, int *min_map)
{
	t_tetris	*temp;
	int			i;

	temp = tets_r;
	while (temp)
	{
		i = 0;
		while (i < 8)
		{
			if (temp->cord[i] + 1 > *min_map)
				*min_map = temp->cord[i] + 1;
			i++;
		}
		temp = temp->next;
	}
}

void			input_map(t_tetris *tets, int c_tets)
{
	t_tetris	*tets_r;
	int			min_map;

	min_map = ft_min_map(tets);
	tets_r = ft_tetcpy(tets);
	check_map(tets_r, &min_map);
	whiles_shift(&tets_r, tets, &min_map, c_tets);
	write_map(tets_r, min_map);
	ft_tetdel(&tets_r);
}

int				fck_n(char *av)
{
	int			i;
	int			fd;
	char		*str_n;

	str_n = ft_strnew(550);
	fd = open(av, O_RDONLY);
	read(fd, str_n, 550);
	i = 0;
	while (str_n[i + 2] != '\0')
	{
		if (str_n[i + 1] == '\n' && str_n[i + 2] == '\n'
			&& str_n[i + 3] == '\0')
		{
			ft_strdel(&str_n);
			close(fd);
			return (0);
		}
		i++;
	}
	ft_strdel(&str_n);
	close(fd);
	return (1);
}

int				main(int ac, char **av)
{
	int			fd;
	int			c_tets;
	t_tetris	*tets;

	if (ac != 2)
		return (errors(1));
	fd = open(av[1], O_RDONLY);
	if (read(fd, 0, 1) == 0 || fck_n(av[1]) == 0)
		return (errors(2));
	if (!(write_tetra(fd, &tets)))
	{
		ft_tetdel(&tets);
		return (errors(2));
	}
	c_tets = count_tets(tets);
	if (c_tets > 26 || c_tets == 0)
	{
		ft_tetdel(&tets);
		return (errors(2));
	}
	input_map(tets, c_tets);
	ft_tetdel(&tets);
	close(fd);
	return (0);
}
