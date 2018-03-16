/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:30:56 by dthuilli          #+#    #+#             */
/*   Updated: 2017/06/11 11:50:36 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		fnl(char *str)
{
	if (str)
		if (ft_strchr(str, '\n'))
			return (1);
	return (0);
}

static char		*extract_line(char **str)
{
	char	*result;
	char	*tmp;

	tmp = ft_strdup(ft_strchr(*str, '\n'));
	result = ft_strsub(*str, 0, ft_strlen(*str) - ft_strlen(tmp));
	free(*str);
	*str = ft_strsub(tmp, 1, ft_strlen(tmp));
	ft_memdel((void **)&tmp);
	return (result);
}

static int		read_line_fd(t_fd *nl, char **line, char *buf)
{
	int		cur;
	char	*tmp;

	while (!fnl(nl->buf) && (cur = read(nl->fd, buf, BUFF_SIZE)) >= 1)
	{
		tmp = ft_strdup(nl->buf);
		ft_memdel((void **)&nl->buf);
		nl->buf = ft_strjoin(tmp, buf);
		ft_memdel((void **)&tmp);
		ft_bzero(buf, BUFF_SIZE);
	}
	if (cur < 0)
		return (-1);
	if (cur == 0 && !fnl(nl->buf) && ft_strlen(nl->buf))
	{
		*line = ft_strdup(nl->buf);
		ft_strclr(nl->buf);
		return (1);
	}
	if (!ft_strlen(nl->buf) && cur == 0)
		return (0);
	*line = extract_line(&nl->buf);
	return (1);
}

static t_list	*new_fd(int const fd, t_list **lst)
{
	t_fd	*nl;

	nl = (t_fd*)ft_memalloc(sizeof(t_fd));
	nl->fd = fd;
	nl->buf = ft_strnew(BUFF_SIZE + 1);
	*lst = ft_lstnew(nl, sizeof(t_fd));
	ft_memdel((void **)&nl);
	return (*lst);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*lstfd = NULL;
	char			*buf;
	t_list			*lst;
	int				result;

	lst = lstfd;
	if (!(line) || BUFF_SIZE <= 0)
		return (-1);
	while (lst && ((t_fd*)lst->content)->fd != fd)
		lst = lst->next;
	if (!lst)
		ft_lstadd(&lstfd, new_fd(fd, &lst));
	buf = ft_strnew(BUFF_SIZE + 1);
	if (!buf)
		return (-1);
	result = read_line_fd(lst->content, line, buf);
	ft_memdel((void **)&buf);
	return (result);
}
