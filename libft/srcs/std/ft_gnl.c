/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:38:03 by llaporte          #+#    #+#             */
/*   Updated: 2017/01/09 14:12:36 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*slist_create_elem(int fd, t_list **slist)
{
	t_list		*new_elem;
	t_data		*data;

	data = (t_data *)ft_memalloc(sizeof(*data));
	if (!data)
		return (0);
	data->fd = fd;
	data->i = 0;
	data->buf = ft_strnew(0);
	if (!data->buf)
		return (0);
	ft_lstadd(slist, new_elem = ft_lstnew(data, sizeof(*data)));
	if (!new_elem)
		return (0);
	free(data);
	return (new_elem);
}

static int		something(t_data *data, char **line)
{
	char	*tofree;

	if (!(*line = ft_strsub(data->buf, 0, data->i)))
		return (-1);
	tofree = data->buf;
	if (!(data->buf = ft_strdup(data->buf + data->i + 1)))
		return (-1);
	free(tofree);
	return (1);
}

static int		check_if_something(t_data *data, char **line, int cur)
{
	char	*tofree;

	while (data->buf[data->i] != '\0')
	{
		if (data->buf[data->i] == '\n')
			return (something(data, line));
		++data->i;
	}
	if (!cur && data->buf[data->i] == '\0' && !ft_strchr(data->buf, '\n'))
	{
		if (!(*line = ft_strsub(data->buf, 0, data->i)))
			return (-1);
		tofree = data->buf;
		if (!(data->buf = ft_strdup(data->buf + data->i)))
			return (-1);
		free(tofree);
		return (1);
	}
	return (0);
}

static int		solvatator(t_data *data, int fd, char **line)
{
	int		cur;
	char	*buffer;
	char	*tofree;

	data->i = 0;
	buffer = ft_strnew(BUFF_SIZE);
	while ((cur = read(fd, buffer, BUFF_SIZE)) || data->buf[0])
	{
		if (cur < 0)
			return (-1);
		if (cur > 0)
		{
			tofree = data->buf;
			data->buf = ft_strjoin(data->buf, buffer);
			free(tofree);
			ft_bzero(buffer, BUFF_SIZE);
		}
		if (check_if_something(data, line, cur))
		{
			free(buffer);
			return (1);
		}
	}
	free(buffer);
	return (0);
}

int				ft_gnl(const int fd, char **line)
{
	static	t_list	*slist;
	t_list			*slist_tmp;

	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	slist_tmp = slist;
	while (slist_tmp && ((t_data *)slist_tmp->content)->fd != fd)
		slist_tmp = slist_tmp->next;
	if (!slist_tmp)
		if (!(slist_tmp = slist_create_elem(fd, &slist)))
			return (-1);
	return (solvatator((t_data *)slist_tmp->content, fd, line));
}
