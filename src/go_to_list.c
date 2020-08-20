/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 23:18:48 by bdrinkin          #+#    #+#             */
/*   Updated: 2019/12/17 20:26:08 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris		*ft_tetcpy(t_tetris *tets)
{
	t_tetris	*ptr;

	ptr = ft_tetnew(tets->cord, tets->letter, tets->num);
	tets = tets->next;
	while (tets)
	{
		ft_tetadd(&ptr, tets->cord);
		tets = tets->next;
	}
	return (ptr);
}

void			ft_tetdel(t_tetris **tets)
{
	t_tetris	*temp;
	t_tetris	*temp2;
	int			i;

	temp = *tets;
	while (temp)
	{
		temp2 = temp->next;
		i = 0;
		while (i < 8)
		{
			temp->cord[i] = 0;
			i++;
		}
		temp->letter = 0;
		temp->next = NULL;
		temp->num = 0;
		free(temp);
		temp = temp2;
	}
	*tets = NULL;
}

t_tetris		*ft_tetnew(int cord[8], char lettter, int num)
{
	t_tetris	*ptr;
	int			i;

	ptr = (t_tetris *)malloc(sizeof(t_tetris));
	if (ptr)
	{
		i = 0;
		while (i < 8)
		{
			ptr->cord[i] = cord[i];
			i++;
		}
		ptr->letter = lettter;
		ptr->next = NULL;
		ptr->num = num;
		return (ptr);
	}
	else
		ft_tetdel(&ptr);
	return (NULL);
}

void			ft_tetadd(t_tetris **tetlst, int cord[8])
{
	int			num;
	char		letter;

	num = 1;
	letter = 'A';
	if (*tetlst)
	{
		while (*tetlst)
		{
			tetlst = &((*tetlst)->next);
			letter++;
			num++;
		}
		*tetlst = ft_tetnew(cord, letter, num);
	}
}

void			go_to_list(t_tetris **tets, int cord[8])
{
	if (*tets)
		ft_tetadd(&(*tets), cord);
	else
		*tets = ft_tetnew(cord, 'A', 1);
}
