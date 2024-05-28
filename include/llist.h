/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:52:48 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/27 11:05:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LLIST_H
# define LLIST_H

# include "minishell.h"

typedef struct s_llist		*t_llist;
typedef struct s_llist_node	*t_llist_node;

struct s_llist {
	t_llist_node	head;
	t_llist_node	tail;
};

struct s_llist_node {
	t_llist_node	next;
	t_llist_node	previous;	
	t_any				value;
};

/**
 * Linked List
*/
t_llist			llist_new(t_mini mini);
t_none			llist_destroy(t_mini mini, t_llist llist);
t_none			llist_append(t_mini mini, t_llist llist, t_any value);

/**
 * Node
*/
t_llist_node	llist_node_new(t_mini mini);
t_none			llist_node_destroy(t_mini mini, t_llist_node node);

#endif