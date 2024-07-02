/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memtree_update_height.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:09:28 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/20 12:31:57 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	memtree_update_height(t_memtree memtree)
{
	int	lheight;
	int	rheight;

	lheight = memtree_get_height(memtree->ltree);
	rheight = memtree_get_height(memtree->rtree);
	if (lheight > rheight)
	{
		memtree->height = 1 + lheight;
	}
	else
	{
		memtree->height = 1 + rheight;
	}
}
