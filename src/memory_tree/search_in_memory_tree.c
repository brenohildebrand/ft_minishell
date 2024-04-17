/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_memory_tree.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:09:21 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/16 20:11:02 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "memory_tree.h"

// static t_type	helper(t_memory_tree memory_tree, void *address)
// {
// 	if (memory_tree->address == address)
// 		return (memory_tree->type);
// 	else if (address < memory_tree->address)
// 		return (helper(memory_tree->ltree, address));
// 	else if (address > memory_tree->address)
// 		return (helper(memory_tree->rtree, address));
// 	return (NULL);
// }

// t_type	search_in_memory_tree(void *address)
// {
// 	t_memory_tree	*memory_tree;

// 	memory_tree = memory_tree_get();
// 	return (helper(*memory_tree, address));
// }
