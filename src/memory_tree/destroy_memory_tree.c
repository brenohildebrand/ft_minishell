/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_memory_tree.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:08:59 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/17 11:19:32 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_tree.h"

void	destroy_memory_tree(t_memory_tree memory_tree)
{
	if (memory_tree == NULL)
		return ;
	destroy_memory_tree(memory_tree->ltree);
	destroy_memory_tree(memory_tree->rtree);
	free(memory_tree->address);
	free(memory_tree);
}
