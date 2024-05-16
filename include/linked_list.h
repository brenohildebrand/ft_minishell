/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:40:48 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/16 19:06:44 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include "types.h"
# include "minishell.h"

typedef struct s_minishell	*t_minishell;

typedef struct s_linked_list		*t_linked_list;
typedef struct s_linked_list_node	*t_linked_list_node;

struct s_linked_list {
	t_linked_list_node	head;
	t_linked_list_node	tail;
};

struct s_linked_list_node {
	t_linked_list_node	previous;
	t_linked_list_node	next;
	t_any				value;
};

t_linked_list	new_linked_list(
	t_minishell mini,
	t_linked_list_node head,
	t_linked_list_node tail
);

t_linked_list_node	new_linked_list_node(
	t_minishell mini,
	t_linked_list_node previous,
	t_linked_list_node next,
	t_any value
);

void	destroy_linked_list(t_minishell mini, t_linked_list list);
void	destroy_linked_list_node(t_minishell mini, t_linked_list_node node);

#endif