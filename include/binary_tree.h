/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:46:07 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/09 18:15:39 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H
# define BINARY_TREE_H

# include "types.h"

typedef struct s_binary_tree		*t_binary_tree;
typedef struct s_binary_tree_node	*t_binary_tree_node;

struct s_binary_tree {
	t_binary_tree_node	root;	
};

struct s_binary_tree_node {
	t_binary_tree	left;
	t_binary_tree	right;
	t_any			value;
};

t_binary_tree	new_binary_tree(t_minishell mini, t_binary_tree_node root);

#endif