/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:40:48 by bhildebr          #+#    #+#             */
/*   Updated: 2024/04/30 15:52:37 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include "types.h"

typedef struct s_linked_list		*t_linked_list;
typedef struct s_linked_list_node	*t_linked_list_node;

struct s_linked_list {
	t_linked_list_node	head;
	t_linked_list_node	tail;
};

struct s_linked_list_node {
	t_linked_list	previous;
	t_linked_list	next;
	t_any			value;
};

#endif