/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:09:38 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/16 19:21:14 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "types.h"
#include "linked_list.h"
#include "token.h"

void	push_to_token_list(
	t_minishell mini,
	t_linked_list list,
	t_token token
){
	if (list == NULL)
	{
		list = new_linked_list(mini, NULL, NULL);
		list->head = new_linked_list_node(mini, NULL, NULL, token);
		list->tail = list->head;
	}
	else if (list->head == list->tail)
	{
		list->tail = new_linked_list_node(mini, list->head, NULL, token);
		list->head->next = list->tail;
	}
	else
	{
		list->tail->next = new_linked_list_node(mini, list->tail, NULL, token);
		list->tail = list->tail->next;
	}
}
