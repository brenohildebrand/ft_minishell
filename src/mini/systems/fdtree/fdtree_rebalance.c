/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdtree_rebalance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:15:04 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 21:15:50 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	left_rotate(t_fdtree *fdtree)
{
	t_fdtree	y;
	t_fdtree	x;
	t_fdtree	b;

	y = *fdtree;
	x = y->rtree;
	b = x->ltree;
	y->rtree = b;
	x->ltree = y;
	*fdtree = x;
	fdtree_update_height((*fdtree)->ltree);
	fdtree_update_height(*fdtree);
}

static void	right_rotate(t_fdtree *fdtree)
{
	t_fdtree	y;
	t_fdtree	x;
	t_fdtree	b;

	y = *fdtree;
	x = y->ltree;
	b = x->rtree;
	y->ltree = b;
	x->rtree = y;
	*fdtree = x;
	fdtree_update_height((*fdtree)->rtree);
	fdtree_update_height(*fdtree);
}

static void	rebalance_left(t_fdtree *fdtree)
{
	int	lgrandheight;
	int	rgrandheight;

	lgrandheight = fdtree_get_height((*fdtree)->ltree->ltree);
	rgrandheight = fdtree_get_height((*fdtree)->ltree->rtree);
	if (lgrandheight >= rgrandheight)
	{
		right_rotate(fdtree);
	}
	else
	{
		left_rotate(&((*fdtree)->ltree));
		right_rotate(fdtree);
	}
}

static void	rebalance_right(t_fdtree *fdtree)
{
	int	lgrandheight;
	int	rgrandheight;

	lgrandheight = fdtree_get_height((*fdtree)->rtree->ltree);
	rgrandheight = fdtree_get_height((*fdtree)->rtree->rtree);
	if (rgrandheight >= lgrandheight)
	{
		left_rotate(fdtree);
	}
	else
	{
		right_rotate(&((*fdtree)->rtree));
		left_rotate(fdtree);
	}
}

void	fdtree_rebalance(t_fdtree *fdtree)
{
	int	lheight;
	int	rheight;

	if ((*fdtree) == NULL)
		return ;
	lheight = fdtree_get_height((*fdtree)->ltree);
	rheight = fdtree_get_height((*fdtree)->rtree);
	if (lheight - rheight > 1)
		rebalance_left(fdtree);
	else if (rheight - lheight > 1)
		rebalance_right(fdtree);
	fdtree_update_height(*fdtree);
}
