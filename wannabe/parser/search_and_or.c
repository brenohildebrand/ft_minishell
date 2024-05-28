/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:44:09 by bhildebr          #+#    #+#             */
/*   Updated: 2024/05/28 10:47:00 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "token.h"

t_token	search_and_or(t_llist list)
{
	t_llist_node	current_node;
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
