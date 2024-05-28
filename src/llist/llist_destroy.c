/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:24:14 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/28 11:30:23 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	llist_destroy(t_mini mini, t_llist llist)
{
	t_llist_node	current_node;
	t_llist_node	next_node;

	if (llist == NULL)
	{
		return ;
	}
	else
	{
		current_node = llist->head;

		while (current_node)
		{
			next_node = current_node->next;	
			llist_node_destroy(mini, current_node);
			current_node = next_node;
		}
		mini_free(mini, llist);
	}
}
