/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:00:18 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/02 17:03:18 by dthuilli         ###   ########.fr       */
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
			write(2, "Too many arguments.\n", 20);
		if (argc < 2)
			write(2, "File name missing.\n", 19);
		return (1);
	}
	file = open(argv[1], O_RDONLY);
	ft_display_file(file);
	close(file);
	return (0);
}
