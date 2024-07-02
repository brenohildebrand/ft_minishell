/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdtree_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:37:14 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/01 10:15:59 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fdtree_destroy_recursively(t_fdtree fdtree)
{
	if (fdtree == NULL)
	{
		return ;
	}
	fdtree_destroy_recursively(fdtree->ltree);
	fdtree_destroy_recursively(fdtree->rtree);
	close(fdtree->fd);
	free(fdtree);
}

t_none	fdtree_destroy(t_mini mini)
{
	t_fdtree	fdtree;
	
	fdtree = mini->shared->fdtree;
	fdtree_destroy_recursively(fdtree);
}
