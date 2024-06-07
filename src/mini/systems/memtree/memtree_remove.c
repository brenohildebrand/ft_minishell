/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memtree_remove.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:08:49 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/20 12:32:46 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini/systems/memtree.h"

static t_type	yet_another_helper(t_memtree *memtree)
{
	t_memtree	min_root;
	t_type			min_type;

	if ((*memtree)->ltree == NULL)
	{
		min_root = *memtree;
		min_type = min_root->type;
		*memtree = min_root->rtree;
		free(min_root);
	}
	else
	{
		min_type = yet_another_helper(&((*memtree)->ltree));
	}
	memtree_rebalance(memtree);
	return (min_type);
}

static void	*another_helper(t_memtree *memtree)
{
	t_memtree	min_root;
	void			*min_address;

	if ((*memtree)->ltree == NULL)
	{
		min_root = *memtree;
		min_address = min_root->address;
	}
	else
	{
		min_address = another_helper(&((*memtree)->ltree));
	}
	return (min_address);
}

void	memtree_remove(t_memtree *memtree, void *address)
{
	t_memtree	old_root;

	if (*memtree == NULL)
		return ;
	else if ((*memtree)->address == address)
	{
		if ((*memtree)->rtree != NULL)
		{
			(*memtree)->address = another_helper(&((*memtree)->rtree));
			(*memtree)->type = yet_another_helper(&((*memtree)->rtree));
			free(address);
		}
		else
		{
			old_root = *memtree;
			*memtree = (*memtree)->ltree;
			free(old_root->address);
			free(old_root);
		}
	}
	else if (address < (*memtree)->address)
		memtree_remove(&((*memtree)->ltree), address);
	else if (address > (*memtree)->address)
		memtree_remove(&((*memtree)->rtree), address);
	memtree_rebalance(memtree);
}
