/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdtree_update_height.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 22:47:44 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 22:48:06 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fdtree_update_height(t_fdtree fdtree)
{
	int	lheight;
	int	rheight;

	lheight = fdtree_get_height(fdtree->ltree);
	rheight = fdtree_get_height(fdtree->rtree);
	if (lheight > rheight)
	{
		fdtree->height = 1 + lheight;
	}
	else
	{
		fdtree->height = 1 + rheight;
	}
}
