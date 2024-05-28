/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:40:48 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/16 19:06:44 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef llist_H
# define llist_H

# include "types.h"
# include "minishell.h"

typedef struct s_minishell	*t_minishell;

typedef struct s_llist		*t_llist;
typedef struct s_llist_node	*t_llist_node;

struct s_llist {
	t_llist_node	head;
	t_llist_node	tail;
};

struct s_llist_node {
	t_llist_node	previous;
	t_llist_node	next;
	t_any				value;
};

t_llist	new_llist(
	t_minishell mini,
	t_llist_node head,
	t_llist_node tail
);

t_llist_node	new_llist_node(
	t_minishell mini,
	t_llist_node previous,
	t_llist_node next,
	t_any value
);

void	destroy_llist(t_minishell mini, t_llist list);
void	destroy_llist_node(t_minishell mini, t_llist_node node);

#endif