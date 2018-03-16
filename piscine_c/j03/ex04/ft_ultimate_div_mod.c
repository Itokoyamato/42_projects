/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 12:58:04 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/07 13:05:18 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int save_divide;
	int save_remain;

	save_divide = *a / *b;
	save_remain = *a % *b;
	*a = save_divide;
	*b = save_remain;
}
