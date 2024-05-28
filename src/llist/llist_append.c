/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_append.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:42:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/28 10:46:03 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	llist_append(t_mini mini, t_llist llist, t_any value)
{
	t_llist_node	node;

	if (llist == NULL)
	{
		return ;
	}
	else
	{
		node = llist_node_new(mini);
		node->value = value;
	
		if (llist->head == NULL)
		{
			llist->head = node;
			llist->tail = node;	
		}
		else
		{
			llist->tail->next = node;
			node->previous = llist->tail;
			llist->tail = node;
		}
	}
}
