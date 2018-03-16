/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 14:37:40 by jmichaud          #+#    #+#             */
/*   Updated: 2016/07/23 21:19:42 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "functions.h"

t_list			*ft_create_elem(char data)
{
	t_list		*next_elem;

	next_elem = (t_list*)malloc(sizeof(t_list));
	if (next_elem)
	{
		next_elem->next = NULL;
		next_elem->data = data;
	}
	return (next_elem);
}
