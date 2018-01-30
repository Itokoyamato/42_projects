/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 16:19:42 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/12 16:30:25 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*result;
	t_list	*anchor;

	if (!lst)
		return (0);
	temp = lst;
	result = f(temp);
	anchor = result;
	while (temp->next)
	{
		temp = temp->next;
		result->next = f(temp);
		result = result->next;
	}
	return (anchor);
}
