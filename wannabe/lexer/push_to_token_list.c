/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:09:38 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/02 15:29:39 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "types.h"
#include "linked_list.h"
#include "token.h"

void	push_to_token_list(
	t_linked_list list,
	t_token token
){
	t_linked_list_node	last_node;

	if (list->head == NULL)
	{
		list->head = new_linked_list_node(NULL, NULL, token);
		list->tail = list->head;
	}
	else if (list->head == list->tail)
	{
		list->tail = new_linked_list_node(list->head, NULL, token);
		list->head->next = list->tail;
	}
	else
	{
		list->tail->next = new_linked_list_node(list->tail, NULL, token);
	}
}
