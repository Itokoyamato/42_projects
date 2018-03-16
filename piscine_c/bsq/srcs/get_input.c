/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 09:26:12 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/27 09:26:14 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <header.h>

int		write_content(int fd, int count)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = (char*)malloc(sizeof(*buffer) * count);
	while (read(0, buffer, count))
	{
		i = 0;
		while (buffer[i])
		{
			write(1, "", 0);
			i++;
		}
		if (buffer[count - 1] != '\n')
			return (0);
		write(fd, buffer, count);
	}
	close(fd);
	return (1);
}

char	*get_input(void)
{
	int		fd;
	char	buf[1];
	int		count;

	count = 0;
	fd = open("map", O_RDWR | O_TRUNC);
	while (read(0, buf, 1) && buf[0] != '\n')
		write(fd, &buf[0], 1);
	write(fd, "\n", 1);
	while (read(0, buf, 1) && buf[0] != '\n')
	{
		write(fd, &buf[0], 1);
		count++;
	}
	write(fd, "\n", 1);
	count++;
	if (!(write_content(fd, count)))
		return (0);
	return ("map");
}
