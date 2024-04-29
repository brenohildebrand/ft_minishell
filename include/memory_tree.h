/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:27:24 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/29 18:05:52 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_TREE_H
# define MEMORY_TREE_H

# include <stdlib.h>

typedef char					*t_cstring;

typedef struct s_type			*t_type;
struct							s_type;

struct s_type	{
	t_cstring	name;
};

typedef struct s_memory_tree	*t_memory_tree;

struct s_memory_tree {
	t_memory_tree	ltree;
	t_memory_tree	rtree;
	void			*address;
	t_type			type;
	int				height;
};

t_memory_tree	create_memory_tree(t_type type, void *address);
void			destroy_memory_tree(t_memory_tree memory_tree);
void			insert_in_memory_tree(
					t_memory_tree *memory_tree,
					t_type type,
					void *address);
void			remove_from_memory_tree(
					t_memory_tree *memory_tree,
					void *address);
void			rebalance_memory_tree(t_memory_tree *memory_tree);
void			update_memory_tree_height(t_memory_tree memory_tree);
int				get_memory_tree_height(t_memory_tree memory_tree);
// t_type		search_in_memory_tree(void *address);

#endif