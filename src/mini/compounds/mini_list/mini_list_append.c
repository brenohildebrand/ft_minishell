/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_list_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:50:04 by bhildebr          #+#    #+#             */
/*   Updated: 2024/06/06 15:16:46 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_none	mini_list_append(
	t_mini mini,
	t_mini_list *list,
	t_cstring token,
	t_i32 type
){
	t_mini_list	node;

	if (*list == NULL)
	{
		(*list) = mini_alloc(mini, sizeof(struct s_mini_list));
		(*list)->previous = NULL;
		(*list)->next = NULL;
		(*list)->token = token;
		(*list)->type = type;
	}
	else
	{
		node = (*list);
		while (node->next)
		{
			node = node->next;			
		}
		node->next = mini_alloc(mini, sizeof(struct s_mini_list));
		node->next->previous = node;
		node->next->next = NULL;
		node->next->token = token;
		node->next->type = type;
	}
}
