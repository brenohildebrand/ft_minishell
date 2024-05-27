/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:52:48 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/27 11:05:38 by bhildebr         ###   ########.fr       */
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

t_linked_list	linked_list_new(t_mini mini);

#endif