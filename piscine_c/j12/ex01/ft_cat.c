/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 10:29:42 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/20 10:29:43 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		write(2, &str[count], 1);
		count++;
	}
}

int		ft_cat(int argc, char **argv)
{
	char	content;
	int		fd;
	int		i;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			ft_putstr("ft_cat: ");
			ft_putstr(argv[i]);
			ft_putstr(": No such file or directory\n");
			close(fd);
			return (1);
		}
		while (read(fd, &content, 1))
			write(1, &content,1);
		close(fd);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc == 2 && argv[1][0] != '-')
		ft_cat(argc, argv);
	return (0);
}
