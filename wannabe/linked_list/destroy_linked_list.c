/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_linked_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:02:31 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/29 14:44:04 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "linked_list.h"

void	destroy_linked_list(t_minishell mini, t_linked_list list)
{
	t_linked_list_node	current;
	t_linked_list_node	next;

	current = list->head;
	while (current != list->tail)
	{
		next = current->next;
		destroy_linked_list_node(mini, current);
		current = next;
	}
}
