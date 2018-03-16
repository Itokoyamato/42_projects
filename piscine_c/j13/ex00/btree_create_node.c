/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 13:01:56 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/22 15:13:47 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *tree;

	tree = 0;
	tree = (t_btree*)malloc(sizeof(t_btree));
	if (tree)
	{
		tree->left = 0;
		tree->right = 0;
		tree->item = item;
	}
	return (tree);
}
