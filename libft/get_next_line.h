/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 20:46:55 by bdrinkin          #+#    #+#             */
/*   Updated: 2019/12/12 23:15:16 by bdrinkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100

# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/uio.h>

int		get_next_line(const int fd, char **line);
#endif
