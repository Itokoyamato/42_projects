/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:08:22 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/16 12:26:06 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *newlst)
{
	t_list *go;

	if (alst && newlst)
	{
		go = *alst;
		while (go->next)
			go = go->next;
		ft_lstadd(&go, newlst);
	}
}
