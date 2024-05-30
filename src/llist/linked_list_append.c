/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_append.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 10:42:42 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 14:41:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"

t_none	linked_list_append(t_mini mini, t_linked_list linked_list, t_any value)
{
	t_linked_list_node	node;

	if (linked_list == NULL)
	{
		return ;
	}
	else
	{
		node = linked_list_node_new(mini);
		node->value = value;
	
		if (linked_list->head == NULL)
		{
			linked_list->head = node;
			linked_list->tail = node;	
		}
		else
		{
			linked_list->tail->next = node;
			node->previous = linked_list->tail;
			linked_list->tail = node;
		}
	}
}
