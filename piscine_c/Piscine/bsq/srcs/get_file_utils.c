/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 18:12:34 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/25 18:12:35 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		get_file_first_line(int fd)
{
	int		first_line;
	char	buf[1];
	int		i;

	i = 0;
	first_line = 0;
	lseek(fd, 0, SEEK_SET);
	while (read(fd, buf, 1) && !first_line)
	{
		if (buf[0] == '\n')
		{
			first_line++;
		}
		i++;
	}
	return (i);
}

int		get_file_size(int fd)
{
	int		i;
	char	buf[1];

	i = 0;
	lseek(fd, 0, SEEK_SET);
	while (read(fd, buf, 1))
		i++;
	return (i);
}

int		ft_atoi(const char *str)
{
	int i;
	int nbr;
	int negative;

	nbr = 0;
	negative = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (-nbr);
	else
		return (nbr);
}
