/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_binary_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:46:01 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/02 15:48:24 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_tree.h"

t_binary_tree	new_binary_tree(t_binary_tree_node root)
{
	t_binary_tree	instance;

	instance = allocate_with_memory_tree(sizeof(struct s_binary_tree));
	instance->root = root;
	return (instance);
}
