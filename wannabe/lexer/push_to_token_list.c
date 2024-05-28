/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:09:38 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/28 10:47:00 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "types.h"
#include "llist.h"
#include "token.h"

void	push_to_token_list(
	t_minishell mini,
	t_token token
){
	if (mini->list == NULL)
	{
		mini->list = new_llist(mini, NULL, NULL);
		mini->list->head = new_llist_node(mini, NULL, NULL, token);
		mini->list->tail = mini->list->head;
	}
	else if (mini->list->head == mini->list->tail)
	{
		mini->list->tail = new_llist_node(mini, mini->list->head, NULL, token);
		mini->list->head->next = mini->list->tail;
	}
	else
	{
		mini->list->tail->next = new_llist_node(mini, mini->list->tail, NULL, token);
		mini->list->tail = mini->list->tail->next;
	}
}
