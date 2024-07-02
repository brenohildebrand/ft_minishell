/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdtree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:30:46 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/01 10:19:29 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDTREE_H
# define FDTREE_H

# include "minishell.h"

typedef struct s_fdtree	*t_fdtree;

struct s_fdtree {
	t_fdtree	ltree;
	t_fdtree	rtree;
	t_i32		fd;
	t_i32		height;
};

t_fdtree	fdtree_create(t_i32 fd);
t_none		fdtree_destroy(t_mini mini);
t_none		fdtree_insert(t_mini mini, t_i32 fd);
t_none		fdtree_remove(t_mini mini, t_i32 fd);
t_none		fdtree_rebalance(t_fdtree *fdtree);
t_none		fdtree_update_height(t_fdtree fdtree);
t_i32		fdtree_get_height(t_fdtree fdtree);

#endif