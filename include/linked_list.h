/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:52:48 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/29 14:44:13 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include "minishell.h"

typedef struct s_linked_list		*t_linked_list;
typedef struct s_linked_list_node	*t_linked_list_node;

struct s_linked_list {
	t_linked_list_node	head;
	t_linked_list_node	tail;
};

struct s_linked_list_node {
	t_linked_list_node	next;
	t_linked_list_node	previous;	
	t_any				value;
};

/**
 * Linked List
*/
t_linked_list			linked_list_new(t_mini mini);
t_none			linked_list_destroy(t_mini mini, t_linked_list linked_list);
t_none			linked_list_append(t_mini mini, t_linked_list linked_list, t_any value);

/**
 * Node
*/
t_linked_list_node	linked_list_node_new(t_mini mini);
t_none			linked_list_node_destroy(t_mini mini, t_linked_list_node node);

#endif