/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdtree_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:35:03 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/30 21:10:19 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_fdtree	fdtree_create(int fd)
{
	t_fdtree	fdtree;

	fdtree = malloc(sizeof(struct s_fdtree));
	if (fdtree == NULL)
	{
		return (NULL);
	}
	fdtree->height = 1;
	fdtree->ltree = NULL;
	fdtree->rtree = NULL;
	fdtree->fd = fd;
	return (fdtree);
}
