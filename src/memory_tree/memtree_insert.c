/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memtree_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:35:24 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/20 12:31:16 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_tree.h"

static int	helper(
	t_memtree *memtree,
	t_type type,
	void *address
){
	if (*memtree == NULL)
	{
		*memtree = memtree_create(type, address);
		if (*memtree == NULL)
			return (1);
	}
	else if (address == (*memtree)->address)
		return (0);
	else
	{
		if (address < (*memtree)->address)
		{
			if (helper(&((*memtree)->ltree), type, address) == 1)
				return (1);
		}
		else
		{
			if (helper(&((*memtree)->rtree), type, address) == 1)
				return (1);
		}
		memtree_rebalance(memtree);
	}
	return (0);
}

void	memtree_insert(
	t_memtree *memtree,
	t_type type,
	void *address
){
	if (helper(memtree, type, address) == 1)
	{
		memtree_destroy(*memtree);
	}
}
