/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_node_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:52:11 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/28 10:57:42 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_llist_node	llist_node_new(t_mini mini)
{
	t_llist_node	node;

	node = mini_alloc(mini, sizeof(struct s_llist_node));
	node->next = NULL;
	node->previous = NULL;
	node->value = NULL;
	return (node);
}
