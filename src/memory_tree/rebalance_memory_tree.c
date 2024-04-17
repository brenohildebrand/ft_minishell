/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rebalance_memory_tree.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:09:15 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/16 20:10:46 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_tree.h"

static void	left_rotate(t_memory_tree *memory_tree)
{
	t_memory_tree	y;
	t_memory_tree	x;
	t_memory_tree	b;

	y = *memory_tree;
	x = y->rtree;
	b = x->ltree;
	y->rtree = b;
	x->ltree = y;
	*memory_tree = x;
	update_memory_tree_height((*memory_tree)->ltree);
	update_memory_tree_height(*memory_tree);
}

static void	right_rotate(t_memory_tree *memory_tree)
{
	t_memory_tree	y;
	t_memory_tree	x;
	t_memory_tree	b;

	y = *memory_tree;
	x = y->ltree;
	b = x->rtree;
	y->ltree = b;
	x->rtree = y;
	*memory_tree = x;
	update_memory_tree_height((*memory_tree)->rtree);
	update_memory_tree_height(*memory_tree);
}

static void	rebalance_left(t_memory_tree *memory_tree)
{
	int	lgrandheight;
	int	rgrandheight;

	lgrandheight = get_memory_tree_height((*memory_tree)->ltree->ltree);
	rgrandheight = get_memory_tree_height((*memory_tree)->ltree->rtree);
	if (lgrandheight >= rgrandheight)
	{
		right_rotate(memory_tree);
	}
	else
	{
		left_rotate(&((*memory_tree)->ltree));
		right_rotate(memory_tree);
	}
}

static void	rebalance_right(t_memory_tree *memory_tree)
{
	int	lgrandheight;
	int	rgrandheight;

	lgrandheight = get_memory_tree_height((*memory_tree)->rtree->ltree);
	rgrandheight = get_memory_tree_height((*memory_tree)->rtree->rtree);
	if (rgrandheight >= lgrandheight)
	{
		left_rotate(memory_tree);
	}
	else
	{
		right_rotate(&((*memory_tree)->rtree));
		left_rotate(memory_tree);
	}
}

void	rebalance_memory_tree(t_memory_tree *memory_tree)
{
	int	lheight;
	int	rheight;

	if ((*memory_tree) == NULL)
		return ;
	lheight = get_memory_tree_height((*memory_tree)->ltree);
	rheight = get_memory_tree_height((*memory_tree)->rtree);
	if (lheight - rheight > 1)
		rebalance_left(memory_tree);
	else if (rheight - lheight > 1)
		rebalance_right(memory_tree);
	update_memory_tree_height(*memory_tree);
}
