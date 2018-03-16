/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 11:10:37 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/19 11:10:38 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list **begin_list)
{
	t_list	*list;
	t_list	*save;

	list = *begin_list;
	while (list)
	{
		if (list->next)
			save = list->next;
		else
			save = 0;
		free(list);
		list = save;
	}
}
