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

#include "minishell.h"

static void	*another_helper(t_memtree *memtree)
{
	t_memtree	min_root;
	void		*min_address;

	if ((*memtree)->ltree == NULL)
	{
		min_root = *memtree;
		min_address = min_root->address;
		*memtree = min_root->rtree;
		free(min_root);
	}
	else
	{
		min_address = another_helper(&((*memtree)->ltree));
	}
	memtree_rebalance(memtree);
	return (min_address);
}

static void	memtree_remove_recursively(t_memtree *memtree, t_any address)
{
	t_memtree	old_root;

	if (*memtree == NULL)
		return ;
	else if ((*memtree)->address == address)
	{
		if ((*memtree)->rtree != NULL)
		{
			(*memtree)->address = another_helper(&((*memtree)->rtree));
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
		memtree_remove_recursively(&((*memtree)->ltree), address);
	else if (address > (*memtree)->address)
		memtree_remove_recursively(&((*memtree)->rtree), address);
	memtree_rebalance(memtree);
}

void	memtree_remove(t_mini mini, t_any address)
{
	t_memtree	*memtree;

	memtree = &(mini->shared->memtree);
	memtree_remove_recursively(memtree, address);
}
