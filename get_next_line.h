/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:16:02 by dthuilli          #+#    #+#             */
/*   Updated: 2016/12/01 14:32:56 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

# define BUFF_SIZE 1024

typedef struct	s_fd
{
	int			fd;
	char		*buf;
	int			nbl;
}				t_fd;

int				get_next_line(int const fd, char **line);

#endif
