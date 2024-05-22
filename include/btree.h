/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:13:50 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/22 11:15:36 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H

# include "minishell.h"

typedef struct s_btree		*t_btree;
typedef struct s_btree_node	*t_btree_node;

struct s_btree {
	t_btree_node	root;	
};

struct s_btree_node {
	t_btree_node	left;
	t_btree_node	right;
	t_any			value;
};

#endif