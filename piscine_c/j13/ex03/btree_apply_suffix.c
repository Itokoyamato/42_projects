/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 15:09:40 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/22 15:22:29 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (*root)
	{
		if (root->left)
			btree_apply_infix(root->left, applyf);
		if (root->right)
			btree_apply_infix(root->right, applyf);
		(*applyf)(root->item);
	}
}
