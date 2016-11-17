/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:48:03 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/16 12:47:31 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "headers.h"

t_list initTetrilist(int fd)
{
	int go;
	char *buff[4096];
	
	if (fd == -1)
		err("invalid fd");

}
