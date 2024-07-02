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

#include "minishell.h"

static int	memtree_insert_recursively(t_memtree *memtree, void *address)
{
	if (*memtree == NULL)
	{
		*memtree = memtree_create(address);
		if (*memtree == NULL)
			return (1);
	}
	else if (address == (*memtree)->address)
		return (0);
	else
	{
		if (address < (*memtree)->address)
		{
			if (memtree_insert_recursively(&((*memtree)->ltree), address) == 1)
				return (1);
		}
		else
		{
			if (memtree_insert_recursively(&((*memtree)->rtree), address) == 1)
				return (1);
		}
		memtree_rebalance(memtree);
	}
	return (0);
}

void	memtree_insert(t_mini mini, t_any address)
{
	t_memtree	*memtree;

	memtree = &mini->shared->memtree;
	if (memtree_insert_recursively(memtree, address) == 1)
	{
		printf("Memtree is calling mini_quit!\n");
		mini_quit(mini, MINI_ERROR);
	}
}
