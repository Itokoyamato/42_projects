/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:31:02 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/09 16:03:39 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	clean_map(t_list **lst, t_map **map)
{
	t_list	*next;

	while (*lst)
	{
		next = (*lst)->next;
		ft_memdel(&(*lst)->content);
		ft_memdel((void **)lst);
		*lst = next;
	}
	if (map && *map)
	{
		ft_memdel((void **)&(*map)->vectors);
		ft_memdel((void **)map);
	}
	return (0);
}

static int	get_lines(int fd, t_list **lst)
{
	t_list	*temp;
	int		expected;
	char	*line;
	int		ret;

	expected = -1;
	while ((ret = get_next_line(fd, &line)))
	{
		if (expected == -1)
			expected = (int)ft_countwords(line, ' ');
		temp = ft_lstnew(line, ft_strlen(line) + 1);
		if ((temp) == NULL)
			return (clean_map(lst, NULL));
		ft_lstadd(lst, temp);
		if (expected != (int)ft_countwords(line, ' '))
			return (clean_map(lst, NULL));
		ft_strdel(&line);
	}
	if (expected == -1 || ret == -1)
		return (clean_map(lst, NULL));
	ft_lstrev(lst);
	return (1);
}

static int	init_map(t_map **m, t_list *list)
{
	t_list	*lst;
	char	**split;
	int		x;
	int		y;

	lst = list;
	y = 0;
	while (y < (*m)->height)
	{
		x = 0;
		if ((split = ft_strsplit(lst->content, ' ')) == NULL)
			return (clean_map(&list, m));
		while (x < (*m)->width)
		{
			(*m)->vectors[y * (*m)->width + x] = get_vector(x, y, split[x]);
			x++;
		}
		ft_strsplitdel(&split);
		lst = lst->next;
		y++;
	}
	get_depth(*m);
	fill_colors(*m);
	clean_map(&list, NULL);
	return (1);
}

t_map		*get_map(int width, int height)
{
	t_map	*map;

	map = ft_memalloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->width = width;
	map->height = height;
	map->depth_min = 0;
	map->depth_max = 0;
	map->vectors = ft_memalloc(sizeof(t_vector *) * width * height);
	if (map->vectors == NULL)
	{
		ft_memdel((void **)&map);
		return (NULL);
	}
	return (map);
}

int		parse_map(int fd, t_map **map)
{
	t_list	*lst;

	lst = NULL;
	if (!(get_lines(fd, &lst)))
		return (0);
	*map = get_map(ft_countwords(lst->content, ' '), ft_lstcount(lst));
	if (*map == NULL)
		return (clean_map(&lst, map));
	return (init_map(map, lst));
}