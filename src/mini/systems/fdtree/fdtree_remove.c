/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdtree_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:05:51 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/01 15:56:55 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_i32	another_helper(t_fdtree *fdtree)
{
	t_fdtree	min_root;
	t_i32		min_fd;

	if ((*fdtree)->ltree == NULL)
	{
		min_root = *fdtree;
		min_fd = min_root->fd;
		*fdtree = min_root->rtree;
		free(min_root);
	}
	else
	{
		min_fd = another_helper(&((*fdtree)->ltree));
	}
	fdtree_rebalance(fdtree);
	return (min_fd);
}

static void	fdtree_remove_recursively(t_fdtree *fdtree, t_i32 fd)
{
	t_fdtree	old_root;

	if (*fdtree == NULL)
		return ;
	else if ((*fdtree)->fd == fd)
	{
		if ((*fdtree)->rtree != NULL)
		{
			(*fdtree)->fd = another_helper(&((*fdtree)->rtree));
			close(fd);
		}
		else
		{
			old_root = *fdtree;
			*fdtree = (*fdtree)->ltree;
			close(old_root->fd);
			free(old_root);
		}
	}
	else if (fd < (*fdtree)->fd)
		fdtree_remove_recursively(&((*fdtree)->ltree), fd);
	else if (fd > (*fdtree)->fd)
		fdtree_remove_recursively(&((*fdtree)->rtree), fd);
	fdtree_rebalance(fdtree);
}

void	fdtree_remove(t_mini mini, t_i32 fd)
{
	t_fdtree	*fdtree;

	fdtree = &(mini->shared->fdtree);
	fdtree_remove_recursively(fdtree, fd);
}
