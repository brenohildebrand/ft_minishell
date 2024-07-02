/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memtree_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:08:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/17 12:12:29 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_memtree	memtree_create(t_any address)
{
	t_memtree	memtree;

	memtree = malloc(sizeof(struct s_memtree));
	if (memtree == NULL)
	{
		return (NULL);
	}
	memtree->height = 1;
	memtree->ltree = NULL;
	memtree->rtree = NULL;
	memtree->address = address;
	return (memtree);
}
