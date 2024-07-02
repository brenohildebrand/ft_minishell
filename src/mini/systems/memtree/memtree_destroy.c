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

#include "minishell.h"

static void	memtree_destroy_recursively(t_memtree memtree)
{
	if (memtree == NULL)
			return ;
	memtree_destroy_recursively(memtree->ltree);
	memtree_destroy_recursively(memtree->rtree);
	free(memtree->address);
	free(memtree);
}

void	memtree_destroy(t_mini mini)
{
	t_memtree	memtree;

	memtree = mini->shared->memtree;
	memtree_destroy_recursively(memtree);
}
