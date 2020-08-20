/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:47:11 by bdrinkin          #+#    #+#             */
/*   Updated: 2019/11/12 02:42:47 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		no_leaks(char **basket, char *karman)
{
	char		*temp;

	if (!*basket)
		*basket = ft_strdup(karman);
	else
	{
		temp = ft_strjoin(*basket, karman);
		ft_strdel(basket);
		*basket = temp;
	}
}

static void		save_hvost(char *n, char **basket)
{
	char		*beg;

	beg = NULL;
	if (ft_strlen(n + 1) > 0)
	{
		beg = ft_strdup(n + 1);
		ft_strdel(basket);
		*basket = ft_strdup(beg);
		ft_strdel(&beg);
	}
	else
	{
		if (*basket)
		{
			ft_strdel(basket);
			basket = NULL;
		}
	}
}

static void		find_n_and_write_line(char **basket, char **line)
{
	char		*n;

	n = NULL;
	if ((n = ft_strchr(*basket, '\n')) == NULL)
		*line = ft_strsub(*basket, 0, ft_strlen(*basket));
	else
		*line = ft_strsub(*basket, 0, (ft_strlen(*basket) - ft_strlen(n)));
	if (n != NULL)
		save_hvost(n, basket);
	else
	{
		ft_strdel(basket);
		basket = NULL;
	}
}

int				get_next_line(const int fd, char **line)
{
	static char	*basket[OPEN_MAX];
	char		karman[BUFF_SIZE + 1];
	long		result_op;

	if (!line || fd < 0 || fd > OPEN_MAX || (read(fd, basket[fd], 0) < 0))
		return (-1);
	if (basket[fd])
	{
		if ((ft_strchr(basket[fd], '\n') != NULL))
		{
			find_n_and_write_line(&basket[fd], line);
			return (1);
		}
	}
	while ((result_op = read(fd, karman, BUFF_SIZE)) > 0)
	{
		karman[result_op] = '\0';
		no_leaks(&basket[fd], karman);
		if (ft_strchr(basket[fd], '\n') != NULL)
			break ;
	}
	if (result_op < BUFF_SIZE && !basket[fd])
		return (0);
	find_n_and_write_line(&basket[fd], line);
	return (line == NULL ? 0 : 1);
}
