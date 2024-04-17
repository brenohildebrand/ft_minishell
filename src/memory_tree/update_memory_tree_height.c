/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_memory_tree_height.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:09:28 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/16 20:10:52 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_tree.h"

void	update_memory_tree_height(t_memory_tree memory_tree)
{
	int	lheight;
	int	rheight;

	lheight = get_memory_tree_height(memory_tree->ltree);
	rheight = get_memory_tree_height(memory_tree->rtree);
	if (lheight > rheight)
	{
		memory_tree->height = 1 + lheight;
	}
	else
	{
		memory_tree->height = 1 + rheight;
	}
}
