/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memtree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 23:35:51 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 16:15:49 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMTREE_H
# define MEMTREE_H

# include <stdlib.h>

typedef char					*t_cstring;

typedef struct s_type			*t_type;
struct							s_type;

struct s_type	{
	t_cstring	name;
};

typedef struct s_memtree	*t_memtree;

struct s_memtree {
	t_memtree	ltree;
	t_memtree	rtree;
	void		*address;
	t_type		type;
	int			height;
};

t_memtree	memtree_create(t_type type, void *address);
void		memtree_destroy(t_memtree memtree);
void		memtree_insert(t_memtree *memtree, t_type type, void *address);
void		memtree_remove(t_memtree *memory_tree, void *address);
void		memtree_rebalance(t_memtree *memtree);
void		memtree_update_height(t_memtree memtree);
int			memtree_get_height(t_memtree memtree);

#endif