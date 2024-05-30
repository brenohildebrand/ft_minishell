/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:44:09 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/30 14:41:38 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contexts/mini.h"
#include "token.h"

t_token	search_and_or(t_linked_list list)
{
	t_linked_list_node	current_node;
	t_token				current_token;
	t_i32				parenthesis;

	current_node = token_lst_get_last(list);
	while (current_node)
	{
		current_token = (t_token)current_node->value;
		if (current_token->type == AND || current_token->type == OR)
			return (current_token);
		if (current->type == CLOSE_PAREN)
		{
			parenthesis = 1;
			while (parenthesis)
			{
				current = current->prev
			}
		}
		current_node = current_node->previous;
	}
	return (NULL);
}
