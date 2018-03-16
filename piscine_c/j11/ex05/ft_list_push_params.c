/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 11:08:20 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/19 11:08:21 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*list;
	t_list	*save;

	i = 2;
	if (ac == 1)
		return (0);
	list = ft_create_elem(av[1]);
	list->next = 0;
	while (i < ac)
	{
		save = list;
		list = ft_create_elem(av[i]);
		list->next = save;
		i++;
	}
	return (list);
}
