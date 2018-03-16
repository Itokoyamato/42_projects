/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 09:43:53 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/20 10:41:22 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_display_file(int fd)
{
	char content;

	while (read(fd, &content, 1))
		write(1, &content, 1);
}

int		main(int argc, char **argv)
{
	int file;

	if (argc != 2)
	{
		if (argc > 2)
			write(1, "Too many arguments.", 19);
		if (argc < 2)
			write(1, "File name missing.", 18);
		return (1);
	}
	file = open(argv[1], O_RDONLY);
	ft_display_file(file);
	close(file);
	return (0);
}
