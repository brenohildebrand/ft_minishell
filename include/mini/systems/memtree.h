/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memtree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 23:35:51 by bhildebr          #+#    #+#             */
/*   Updated: 2024/07/01 10:18:15 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMTREE_H
# define MEMTREE_H

# include "minishell.h"

typedef struct s_memtree	*t_memtree;

struct s_memtree {
	t_memtree	ltree;
	t_memtree	rtree;
	t_any		address;
	t_i32		height;
};

t_memtree	memtree_create(t_any address);
t_none		memtree_destroy(t_mini mini);
t_none		memtree_insert(t_mini mini, t_any address);
t_none		memtree_remove(t_mini mini, t_any address);
t_none		memtree_rebalance(t_memtree *memtree);
t_none		memtree_update_height(t_memtree memtree);
t_i32		memtree_get_height(t_memtree memtree);

#endif