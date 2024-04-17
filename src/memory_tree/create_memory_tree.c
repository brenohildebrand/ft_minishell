/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_memory_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:08:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/17 12:12:29 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_tree.h"

t_memory_tree	create_memory_tree(t_type type, void *address)
{
	t_memory_tree	memory_tree;

	memory_tree = malloc(sizeof(struct s_memory_tree));
	if (memory_tree == NULL)
	{
		return (NULL);
	}
	memory_tree->height = 1;
	memory_tree->ltree = NULL;
	memory_tree->rtree = NULL;
	memory_tree->address = address;
	memory_tree->type = type;
	return (memory_tree);
}
