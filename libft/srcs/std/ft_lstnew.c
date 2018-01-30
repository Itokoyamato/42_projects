/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:49:54 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/22 13:55:07 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlst;

	newlst = (t_list *)ft_memalloc(sizeof(t_list));
	if (newlst == NULL)
		return (0);
	if (content == NULL)
	{
		newlst->content = NULL;
		newlst->content_size = 0;
	}
	else
	{
		newlst->content = (void *)ft_memalloc(content_size);
		if (newlst->content == NULL)
			return (0);
		else
		{
			ft_memcpy(newlst->content, content, content_size);
			newlst->content_size = content_size;
		}
	}
	newlst->next = NULL;
	return (newlst);
}
