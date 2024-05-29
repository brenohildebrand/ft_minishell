/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:24:14 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/28 11:30:23 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	linked_list_destroy(t_mini mini, t_linked_list linked_list)
{
	t_linked_list_node	current_node;
	t_linked_list_node	next_node;

	if (linked_list == NULL)
	{
		return ;
	}
	else
	{
		current_node = linked_list->head;

		while (current_node)
		{
			next_node = current_node->next;	
			linked_list_node_destroy(mini, current_node);
			current_node = next_node;
		}
		mini_free(mini, linked_list);
	}
}
