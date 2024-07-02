/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdtree_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:40:52 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/01 10:20:39 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	fdtree_insert_recursively(t_fdtree *fdtree, t_i32 fd)
{
	if (*fdtree == NULL)
	{
		*fdtree = fdtree_create(fd);
		if (*fdtree == NULL)
			return (1);
	}
	else if (fd == (*fdtree)->fd)
		return (0);
	else
	{
		if (fd < (*fdtree)->fd)
		{
			if (fdtree_insert_recursively(&((*fdtree)->ltree), fd) == 1)
				return (1);
		}
		else
		{
			if (fdtree_insert_recursively(&((*fdtree)->rtree), fd) == 1)
				return (1);
		}
		fdtree_rebalance(fdtree);
	}
	return (0);
}

void	fdtree_insert(t_mini mini, t_i32 fd)
{
	t_fdtree	*fdtree;

	fdtree = &mini->shared->fdtree;
	if (fdtree_insert_recursively(fdtree, fd) == 1)
	{
		mini_quit(mini, MINI_ERROR);
	}
}