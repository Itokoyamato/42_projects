/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:14:00 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/08 14:16:28 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*rlist;
	t_list	*result;

	if (!lst)
		return (NULL);
	rlist = f(lst);
	result = rlist;
	while (lst->next)
	{
		lst = lst->next;
		rlist->next = f(lst);
		rlist = rlist->next;
	}
	return (result);
}
