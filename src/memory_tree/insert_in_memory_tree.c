/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_in_memory_tree.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:35:24 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/17 12:23:47 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_tree.h"

static int	helper(
	t_memory_tree *memory_tree,
	t_type type,
	void *address
){
	if (*memory_tree == NULL)
	{
		*memory_tree = create_memory_tree(type, address);
		if (*memory_tree == NULL)
			return (1);
	}
	else if (address == (*memory_tree)->address)
		return (0);
	else
	{
		if (address < (*memory_tree)->address)
		{
			if (helper(&((*memory_tree)->ltree), type, address) == 1)
				return (1);
		}
		else
		{
			if (helper(&((*memory_tree)->rtree), type, address) == 1)
				return (1);
		}
		rebalance_memory_tree(memory_tree);
	}
	return (0);
}

void	insert_in_memory_tree(
	t_memory_tree *memory_tree,
	t_type type,
	void *address
){
	if (helper(memory_tree, type, address) == 1)
	{
		destroy_memory_tree(*memory_tree);
	}
}
