/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 20:11:52 by jmichaud          #+#    #+#             */
/*   Updated: 2016/07/24 18:10:26 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "functions.h"

char			*get_string(void)
{
	t_list		*chaine;
	char		buf[2];
	char		*str;
	int			i;

	chaine = NULL;
	i = 0;
	while (read(0, buf, 1) > 0)
	{
		buf[1] = '\0';
		ft_list_push_back(&chaine, buf[0]);
		i++;
	}
	str = (char*)malloc(sizeof(*str) * i);
	i = 0;
	while (chaine)
	{
		str[i] = chaine->data;
		chaine = chaine->next;
		i++;
	}
	str[i] = '\0';
	return (str);
}
