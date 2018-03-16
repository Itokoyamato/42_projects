/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 17:17:37 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/25 17:17:39 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		get_map_info(char *info_line, t_map_info *map_info, int fl_size)
{
	t_map_info	info;
	int			i;
	char		*lc;

	i = 0;
	lc = (char *)malloc(sizeof(*lc) * (fl_size - 4));
	info.x = map_info->x;
	info.empty = info_line[fl_size - 4];
	info.obs = info_line[fl_size - 3];
	info.full = info_line[fl_size - 2];
	while (i <= fl_size - 4)
	{
		lc[i] = info_line[i];
		i++;
	}
	if (map_info->y != ft_atoi(lc))
		return (0);
	info.y = map_info->y;
	*map_info = info;
	return (1);
}

char	*retrieve_line(int fd, int current_i, int prev_line_i, t_map_info *info)
{
	int			i;
	char		*line;
	char		buf[1];

	i = 0;
	line = (char*)malloc(sizeof(*line) * (current_i - prev_line_i) + 1);
	lseek(fd, prev_line_i, SEEK_SET);
	while (read(fd, buf, 1) && i <= current_i - prev_line_i)
	{
		line[i] = buf[0];
		i++;
	}
	line[i] = '\0';
	i--;
	if (info->y == 1)
		i++;
	if (i != info->x && info->y > 1)
		return (0);
	info->x = i;
	return (line);
}

char	**retrieve_content(int fd, int count[3], int fl_size, t_map_info *info)
{
	char		**map;
	char		buf[1];
	char		*info_line;

	count[2] = fl_size;
	info_line = (char*)malloc(sizeof(*info_line) * (fl_size));
	map = (char**)malloc(sizeof(**map) * (get_file_size(fd) - fl_size) + 1);
	lseek(fd, 0, SEEK_SET);
	while (read(fd, buf, 1))
	{
		if (count[0] < fl_size)
			info_line[count[0]] = buf[0];
		else if (buf[0] == '\n')
		{
			if (!(map[count[1]] = retrieve_line(fd, count[0], count[2], info)))
				return (0);
			count[1]++;
			count[2] = count[0] + 1;
		}
		info->y = count[1];
		count[0]++;
	}
	if (!(get_map_info(info_line, info, fl_size)))
		return (0);
	return (map);
}

char	**get_map(char *path, t_map_info *map_info)
{
	int		fd;
	char	**map;
	int		count[3];
	int		fl_size;

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	fd = open(path, O_RDWR);
	if (fd < 0)
		return (0);
	fl_size = get_file_first_line(fd);
	if (!(map = retrieve_content(fd, count, fl_size, map_info)))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (map);
}
