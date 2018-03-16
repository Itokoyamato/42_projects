/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 09:49:03 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/23 09:49:04 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	eval_expr_0(char **ps);
int	eval_expr_1(char **ps);

int     do_op(int lnbr, int rnbr, char op)
{
  if (op == '+')
    return (lnbr + rnbr);
  else if (op == '-')
    return (lnbr - rnbr);
  else if (op == '*')
    return (lnbr * rnbr);
  else if (op == '/')
    return (lnbr / rnbr);
  else if (op == '%')
    return (lnbr % rnbr);
  else
    return (0);
}

char	*rid_spaces(char *str)
{
	int		i;
	int		k;
	char	*str2;

	i = 0;
	k = 0;
	str2 = malloc(ft_strlen(str) + 1);
	while (str[i])
	{
		if (str[i] != ' ')
		{
			str2[k] = str[i];
			k++;
		}
		i++;
	}
	str2[k] = '\0';
	return (str2);
}

int		execute_eval_expr(char **str, int current)
{
	while (*str[current])
	{

	}
	return (0);
}

int		eval_expr(char *str)
{
	str = rid_spaces(str);
	if (str[0] == '\0')
		return (0);
	return (execute_eval_expr(&str, 0));
}
