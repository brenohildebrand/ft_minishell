/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:13:50 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 12:50:35 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H
# define BINARY_TREE_H

# include "any.h"

typedef struct s_binary_tree		*t_binary_tree;
typedef struct s_binary_tree_node	*t_binary_tree_node;
typedef t_binary_tree				t_btree;
typedef t_binary_tree_node			t_btree_node;

struct s_binary_tree {
	t_btree_node	root;	
};

struct s_binary_tree_node {
	t_btree_node	left;
	t_btree_node	right;
	t_any			value;
};

#endif