/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:14:10 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/17 14:18:02 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **lst)
{
	t_list	*tmp;
	t_list	*rlst;

	rlst = NULL;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		(*lst)->next = rlst;
		rlst = *lst;
		*lst = tmp;
	}
	*lst = rlst;
}
