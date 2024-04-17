/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_from_memory_tree.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:08:49 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/17 12:36:30 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_tree.h"

static t_type	yet_another_helper(t_memory_tree *memory_tree)
{
	t_memory_tree	min_root;
	t_type			min_type;

	if ((*memory_tree)->ltree == NULL)
	{
		min_root = *memory_tree;
		min_type = min_root->type;
		*memory_tree = min_root->rtree;
		free(min_root);
	}
	else
	{
		min_type = yet_another_helper(&((*memory_tree)->ltree));
	}
	rebalance_memory_tree(memory_tree);
	return (min_type);
}

static void	*another_helper(t_memory_tree *memory_tree)
{
	t_memory_tree	min_root;
	void			*min_address;

	if ((*memory_tree)->ltree == NULL)
	{
		min_root = *memory_tree;
		min_address = min_root->address;
	}
	else
	{
		min_address = another_helper(&((*memory_tree)->ltree));
	}
	return (min_address);
}

void	remove_from_memory_tree(t_memory_tree *memory_tree, void *address)
{
	t_memory_tree	old_root;

	if (*memory_tree == NULL)
		return ;
	else if ((*memory_tree)->address == address)
	{
		if ((*memory_tree)->rtree != NULL)
		{
			(*memory_tree)->address = another_helper(&((*memory_tree)->rtree));
			(*memory_tree)->type = yet_another_helper(&((*memory_tree)->rtree));
			free(address);
		}
		else
		{
			old_root = *memory_tree;
			*memory_tree = (*memory_tree)->ltree;
			free(old_root->address);
			free(old_root);
		}
	}
	else if (address < (*memory_tree)->address)
		remove_from_memory_tree(&((*memory_tree)->ltree), address);
	else if (address > (*memory_tree)->address)
		remove_from_memory_tree(&((*memory_tree)->rtree), address);
	rebalance_memory_tree(memory_tree);
}
