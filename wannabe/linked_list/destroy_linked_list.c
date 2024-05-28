/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_llist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:02:31 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/16 19:05:12 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "llist.h"

void	destroy_llist(t_minishell mini, t_llist list)
{
	t_llist_node	current;
	t_llist_node	next;

	current = list->head;
	while (current != list->tail)
	{
		next = current->next;
		destroy_llist_node(mini, current);
		current = next;
	}
}
