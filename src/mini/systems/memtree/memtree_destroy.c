/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memtree_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:08:59 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/17 11:19:32 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_tree.h"

void	memtree_destroy(t_memtree memtree)
{
	if (memtree == NULL)
		return ;
	memtree_destroy(memtree->ltree);
	memtree_destroy(memtree->rtree);
	free(memtree->address);
	free(memtree);
}
